/*
	@author :Rahul Thapar
	ID 	: 1410110321

	Randomly generate a string of length 100 with the following alphabet set {a, b, c, d). 
	Write a program to use Huffman codes to compress the string.
*/
#include <stdio.h>
#include <string.h>
 
typedef struct node_t {
	struct node_t *left, *right;
	int frequency;
	char c;
} *node;
 
struct node_t pool[256] = {{0}};
node qqq[255], *q = qqq - 1;
int n_nodes = 0, end = 1;
char *code[128] = {0}, buffer[1024];
 
node new_node(int frequency, char c, node a, node b)
{
	node n = pool + n_nodes++;
	if (frequency) n->c = c, n->frequency = frequency;
	else {
		n->left = a, n->right = b;
		n->frequency = a->frequency + b->frequency;
	}
	return n;
}
 
/* priority queue */
void insert(node n)
{
	int j, i = end++;
	while ((j = i / 2)) {
		if (q[j]->frequency <= n->frequency) 
			break;
		q[i] = q[j], i = j;
	}
	q[i] = n;
}
 
node qremove()
{
	int i, l;
	node n = q[i = 1];
 
	if (end < 2) 
		return 0;
	end--;
	while ((l = i * 2) < end) {
		if (l + 1 < end && q[l + 1]->frequency < q[l]->frequency) l++;
		q[i] = q[l], i = l;
	}
	q[i] = q[end];
	return n;
}
 
/* walk the tree and put 0s and 1s */
void build_code(node n, char *s, int len)
{
	static char *out = buffer;
	if (n->c) {
		s[len] = 0;
		strcpy(out, s);
		code[n->c] = out;
		out += len + 1;
		return;
	}
 
	s[len] = '0'; build_code(n->left,  s, len + 1);
	s[len] = '1'; build_code(n->right, s, len + 1);
}
 
void init(const char *s)
{
	int i, frequency[128] = {0};
	char c[16];
 
	while (*s) frequency[(int)*s++]++;
 
	for (i = 0; i < 128; i++)
		if (frequency[i]) insert(new_node(frequency[i], i, 0, 0));
 
	while (end > 2) 
		insert(new_node(0, 0, qremove(), qremove()));
 
	build_code(q[1], c, 0);
}
 
void encode(const char *s, char *out)
{
	while (*s) {
		strcpy(out, code[*s]);
		out += strlen(code[*s++]);
	}
}
 
void decode(const char *s, node t)
{
	node n = t;
	while (*s) {
		if (*s++ == '0') n = n->left;
		else n = n->right;
 
		if (n->c) putchar(n->c), n = t;
	}
 
	putchar('\n');
	if (t != n) printf("garbage input\n");
}
 
int main(void)
{

	int i;
	const char *str = "aaabbbcccdddaaaaaaaaabbbcccdddaaaabbbcccdddaaabbbcccdddbaabbbcccdddbbbbcccdddaaabbbcccdddbbbbcccdddb";
        char buffer[1024];
 
	init(str);
	printf("\n\n");
	printf("\tDATA SET\n\n");
	for (i = 0; i < 128; i++)
		if (code[i]) 
			printf("\t'%c': %s\n", i, code[i]);

	int len = strlen(str);
	printf("\n\tSTRING \n=====================================================================================================\n%s\n=====================================================================================================\n", str);
 	printf("\tLENGTH : %d\n",len );
	encode(str, buffer);
	printf("\n\tHuffman Compression \n=====================================================================================================\n%s\n=====================================================================================================\n", buffer);
 
	return 0;
}