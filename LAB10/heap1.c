/* 

        Author: SONALI SHANKAR
        Roll No: 1410110425

        Implement Heap Sort (Max Heap)

 */ 
#include <stdio.h>
void main()
{
    int maxHeap[10], no, i, j, c, root, temp;
    printf("\n Enter no of elements :");
    scanf("%d", &no);
    printf("\n Enter the nos : ");
    for (i = 0; i < no; i++)
       scanf("%d", &maxHeap[i]);
    for (i = 1; i < no; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (maxHeap[root] < maxHeap[c])   // Creating MaxHeap Array
            {
                temp = maxHeap[root];
                maxHeap[root] = maxHeap[c];
                maxHeap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
    printf("maxHeap array : ");
    for (i = 0; i < no; i++)
        printf("%d\t ", maxHeap[i]);
    for (j = no - 1; j >= 0; j--)
    {
        temp = maxHeap[0];
        maxHeap[0] = maxHeap[j];    /* swap max element with rightmost leaf element */
        maxHeap[j] = temp;
        root = 0;
        do 
        {  c = 2 * root + 1;    
            if ((maxHeap[c] < maxHeap[c + 1]) && c < j-1)
                c++;
            if (maxHeap[root]<maxHeap[c] && c<j)    // Rearrange MaxHeap
            {
                temp = maxHeap[root];
                maxHeap[root] = maxHeap[c];
                maxHeap[c] = temp;
            }
            root = c;
        } while (c < j);
    } 
    printf("\n The sorted array is : ");
    for (i=no-1; i >=0; i--)
       printf("\t %d", maxHeap[i]);
}