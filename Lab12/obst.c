/*
	@author : Rahul Thapar
	ID 		: 1410110321

	------------------------
	
*/
#include <stdio.h>
#include<stdlib.h>

#define MAX 20

typedef struct OBST{
	int KEY;
	struct OBST *left, *right;
}OBST;

int C[MAX][MAX]; //cost matrix
int W[MAX][MAX]; //weight matrix
int R[MAX][MAX]; //root matrix
int q[MAX]; //unsuccesful searches
int p[MAX]; //frequencies 7

int NUMBER_OF_KEYS; //number of keys in the tree
int KEYS[MAX];
OBST *ROOT;

void COMPUTE_W_C_R(){
	int x, min;
	int i, j, k, h, m;

	//Construct weight matrix W
	for(i = 0; i <= NUMBER_OF_KEYS; i++) {
		W[i][i] = q[i];
		for(j = i + 1; j <= NUMBER_OF_KEYS; j++)
			W[i][j] = W[i][j-1] + p[j] + q[j];
	}

	//Construct cost matrix C and root matrix R
	for(i = 0; i <= NUMBER_OF_KEYS; i++)
		C[i][i] = W[i][i];
	for(i = 0; i <= NUMBER_OF_KEYS - 1; i++) {
		j = i + 1;
		C[i][j] = C[i][i] + C[j][j] + W[i][j];
		R[i][j] = j;
	}
	for(h = 2; h <= NUMBER_OF_KEYS; h++)
		for(i = 0; i <= NUMBER_OF_KEYS - h; i++) {
			j = i + h;
			m = R[i][j-1];
			min = C[i][m-1] + C[m][j];
			for(k = m+1; k <= R[i+1][j]; k++){
				x = C[i][k-1] + C[k][j];
				if(x < min) {
					m = k;
					min = x;
				}
			}
			C[i][j] = W[i][j] + min;
			R[i][j] = m;
		}

	//Display weight matrix W
	printf("\nThe weight matrix W:\n");
	for(i = 0; i <= NUMBER_OF_KEYS; i++){
		for(j = i; j <= NUMBER_OF_KEYS; j++)
			printf("%d ", W[i][j]);
		printf("\n");
	}

	//Display Cost matrix C
	printf("\nThe cost matrix C:\n");
	for(i = 0; i <= NUMBER_OF_KEYS; i++) {
		for(j = i; j <= NUMBER_OF_KEYS; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}

	//Display root matrix R 8

	printf("\nThe root matrix R:\n");
	for(i = 0; i <= NUMBER_OF_KEYS; i++) {
		for(j = i; j <= NUMBER_OF_KEYS; j++)
			printf("%d ", R[i][j]);
		printf("\n");
	}
}

//Construct the optimal binary search tree
OBST *CONSTRUCT_OBST(int i, int j){
	OBST *p;

	if(i == j)
		p = NULL;
	else{
		p = (OBST*) calloc(1, sizeof(OBST));
		p->KEY = KEYS[R[i][j]];
		p->left = CONSTRUCT_OBST(i, R[i][j] - 1); //left subtree
		p->right = CONSTRUCT_OBST(R[i][j], j); //right subtree
	}
	return p;
}

//Display the optimal binary search tree
void DISPLAY(OBST *ROOT, int nivel){
	int i;
	if(ROOT != 0) {
		DISPLAY(ROOT->right, nivel+1);
		for(i = 0; i <= nivel; i++)
			printf(" ");
		printf("%d\n", ROOT->KEY);
		DISPLAY(ROOT->left, nivel + 1);
	}
}
void OPTIMAL_BINARY_SEARCH_TREE()
{
	float average_cost_per_weight;

	COMPUTE_W_C_R();
	printf("C[0] = %d W[0] = %d\n", C[0][NUMBER_OF_KEYS], W[0][NUMBER_OF_KEYS]);
	/*average_cost_per_weight = C[0][NUMBER_OF_KEYS]/(float)W[0][NUMBER_OF_KEYS];
	printf("The cost per weight ratio is: %f\n", average_cost_per_weight);*/
	ROOT = CONSTRUCT_OBST(0, NUMBER_OF_KEYS);
}
int main(){
	int i, k;

	setbuf(stdout,NULL);
	printf("Input number of keys: ");
	scanf("%d", &NUMBER_OF_KEYS);
	for(i = 1; i <= NUMBER_OF_KEYS; i++) {
		printf("key[%d]= ",i);
		scanf("%d", &KEYS[i]);
		printf(" frequency = ");
		scanf("%d",&p[i]);
	}
	for(i = 0; i <= NUMBER_OF_KEYS; i++) {
		printf("q[%d] = ", i);

		scanf("%d",&q[i]);
	}
	do {
		printf("1.Construct tree\n2.Display tree\n3.Exit\n");
		scanf("%d", &k);
		switch(k) {
		case 1:
			OPTIMAL_BINARY_SEARCH_TREE();
			break;
		case 2:
			DISPLAY(ROOT, 0);
			break;
		case 3:
			k = -1;
			break;
		}
	} while (k != -1);
}