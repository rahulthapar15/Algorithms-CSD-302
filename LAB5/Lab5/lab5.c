#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 128

//void matrixMultiply(int, int, int [][MAX], int, int, int [][MAX], int [][MAX]);
int display(int, int, int[][MAX]);

int C[MAX][MAX] = {0}; // Resultant Matrix
/*static int row1=MAX , row2=MAX;
static int col1=MAX , col2=MAX;
*/

int main(void){
	int A[MAX][MAX]; // Matrix 1
	int B[MAX][MAX]; // Matrix 2
    int row1=MAX; int row2 = MAX;
    int col1 = MAX; int col2 = MAX;
  
	
	int random_number;
	int i,j,k;

	//Generating Random Numbers between 0-9
	srand(time(NULL));

	for (i = 0; i < row1; ++i)
	{
		for (j = 0; j < col1; ++j)
		{
			//Creating Matrix 1
			A[i][j]=rand()%10;
            B[i][j]=rand()%10;
		}
	}

clock_t begin, end;
double time_spent;

begin = clock();

 /* for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++)
            for(k = 0; k < MAX; k++)
                C[i][j] += A[i][k] * B[k][j];*/
    
    matMult(A,B);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    

printf("On matrix multiplication of A and B the result is:\n");
display(row1, col2, C);

printf("Elapsed time: %.9lf seconds.\n", time_spent);

}
matMult(int a[MAX][MAX],int b[MAX][MAX]){

    static int i=0,j=0,k=0;
    int sum;
    int x=128;
    int y=128;
    int z=128;
    //printf("Started\n");

    if(i<x) //row of first matrix
    {
      //  printf("i : %d\n",i);
      if(j<z) //column of second matrix
      {
                //printf("j : %d\n",j);
         if(k<y)
         {
                   // printf("k : %d\n",k);
             sum=sum+a[i][k]*b[k][j];
             k++;
             matMult(a,b);
            // printf("Sum : %d\n", sum);
         }
        
         C[i][j]=sum;
        // printf("%d\n", C[i][j]);
             sum=0;
             k=0;
             j++;
             matMult(a,b);
      }
        j=0;
        i++;
        matMult(a,b);
    }
   // printf("Done\n");
}
int display(int m1, int n2, int c[MAX][MAX]){
    int i, j;
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            printf("%d  ", c[i][j]);
        }
        printf("\n");
    }
    return;
}