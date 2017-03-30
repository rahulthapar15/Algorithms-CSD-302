#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  Structure that represents a node in the Dynamic Programming Table. A node
 *  has a value, root (name), and root index. This exists done so that two
 *  seperate tables are not required.
 */
typedef struct {
    unsigned int value;
    char root;
    unsigned int root_index;
} node_t;

/**
 *  Structure that represents an element in the Optimal Binary Search Tree. An
 *  element has a name and a probability.
 */
typedef struct {
    char name;
    unsigned int probability;
} element_t;

/**
 *  Function that prints the Dynamic Programming Table.
 *
 *  @param table - a square 2D table of nodes
 *  @param elements - the array of elements
 *  @param n - the size of the table
 *  @param file - the file to output the table to
 */
void print_table(node_t **table, element_t *elements, unsigned int n,
    FILE *file)
{
    unsigned int width = 0;
    unsigned int i, j = 0;

    /* Determine the length of the longest tuple. This will make the table
     * formatting look nice */

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            char tuple[256];
            sprintf(tuple, "(%u, %c) ", table[i][j].value, table[i][j].root);
            
            if (strlen(tuple) > width)
            {
                width = strlen(tuple);
            }
        }
    }

    /* Print the first row of element names */

    fprintf(file, "%-*c ", 3, '~');

    for (i = 0; i < n; i++)
    {
        fprintf(file, "%-*c ", width, elements[i].name);
    }

    fprintf(file, "\n");

    /* For each row, print the element name. Then print each entry for that
     * row. It's formatted so that it will be table-like */

    for (i = 0; i < n; i++)
    {
        fprintf(file, "%-*c ", 3, elements[i].name);

        for (j = 1; j <= n; j++)
        {
            char tuple[256];
            sprintf(tuple, "(%u, %c) ", table[i][j].value, table[i][j].root);
            fprintf(file, "%-*s ", width, tuple);
        }

        fprintf(file, "\n");
    }
}

/**
 *  Function that prints the tree. It does so in a pre-order traversal fashion.
 *  
 *  @param table - the initialized Dynamic Programming Table
 *  @param i - the row value
 *  @param j - the column value
 *  @param s - the number of spaces to print before
 *  @param file - the file to output the tree to
 */
void print_tree(node_t **table, unsigned int i, unsigned int j,
    unsigned int s, FILE *file)
{
    unsigned int k = 0;

    if (i < j)
    {
        for (k = 0; k < s; k++)
            fprintf(file, " ");

        fprintf(file, "%c\n", table[i][j].root);

        print_tree(table, i, table[i][j].root_index+0, s+1, file);
        print_tree(table, table[i][j].root_index+1, j, s+1, file);
    }
}

/**
 *  Function that calculates the Optimal Binary Search Tree for the given
 *  elements.
 *
 *  @param elements - list of elements
 *  @param n - the number of elements
 *
 *  @return the OBST table
 */
node_t** calculate_obst_table(element_t *elements, unsigned int n)
{
    unsigned int i, d, j, k;
    unsigned int infinity = 1;

    node_t **table = (node_t**)malloc(sizeof(node_t*) * (n+1));

    /* Allocate space for each row */

    for (i = 0; i <= n; i++)
    {
        table[i] = (node_t*)malloc(sizeof(node_t) * (n+1));

        for (j = 0; j <= n; j++)
        {
            node_t n = {0, '~', 0};
            table[i][j] = n;
        }
    }

    /* Initialize the center diagonal */

    for (i = 0; i < n; i++)
    {
        table[i][i+1].value = elements[i].probability;
        table[i][i+1].root = elements[i].name;
        table[i][i+1].root_index = i;
    }

    /* Calculate infinity for our table. It needs to be bigger than any
     * possible value. I believe the following will work:
     *
     *     Infinity = 2 * sum(probs) + 1
     */

    for (i = 0; i < n; i++)
    {
        infinity += 2 * elements[i].probability;
    }

    /* Fill the table */

    for (d = 1; d < n; d++)
    {
        for (i = 0; i < (n-d); i++)
        {
            unsigned int j = i + d + 1;
            unsigned int sum_p = 0;
            unsigned int min_value = infinity;
            unsigned int min_root_index = 0;
            char min_root = '~';

            for (k = i; k < j; k++)
            {
                unsigned int value = table[i][k].value + table[k+1][j].value;
                sum_p += elements[k].probability;

                if (value < min_value)
                {
                    min_value = value;
                    min_root = elements[k].name;
                    min_root_index = k;
                }
            }

            table[i][j].value = sum_p + min_value;
            table[i][j].root = min_root;
            table[i][j].root_index = min_root_index;
        }
    }

    return table;
}

/**
 *  The main function. It will read the elements from the input file, then
 *  create a Optimal Binary Search Tree, then output the Dynamic Programming
 *  Table, the the Optimal Binary Search Tree itself.
 */
int main(void)
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("jwt0006.txt", "w");
    unsigned int size = 0, index = 0, i = 0;
    char c = 0;
    element_t *elements = NULL;
    node_t **table = NULL;

    /* Read in the number of elements in the input file */

    fscanf(input, "%u\n", &size);

    /* Allocate space for an array of elements */

    elements = (element_t *)malloc(size * sizeof(element_t));

    /* Zero out elements, just incase the number of elements is less than
     * number said were there */

    for (i = 0; i < size; i++)
    {
        element_t e = {'~', 0};
        elements[i] = e;
    }

    /* Read each element from the input file */

    while (fscanf(input, "%c %u\n", &c, &i) == 2)
    {
        element_t e = {c, i};
        elements[index++] = e;
    }

    /* Calculate the values for the Dynamic Programming Table for the Optimal
     * Binary Search Tree */

    table = calculate_obst_table(elements, size);

    /* Now print the Dynamic Programming Table, then the tree itself */

    fprintf(output, "\n===Table===\n");
    print_table(table, elements, size, output);

    fprintf(output, "\n===Tree===\n");
    print_tree(table, 0, size, 0, output);

    /* Processing is complete. Free everything */

    free(elements);

    for (i = 0; i <= size; i++)
    {
        free(table[i]);
    }

    free(table);

    return 0;
}