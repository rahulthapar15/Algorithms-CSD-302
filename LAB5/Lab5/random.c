#include <stdio.h>
#include <time.h>
#define MAX 128
int main()
{
	int array[MAX][MAX];
	int array2[MAX][MAX];
	int n;int j;
	srand(time(NULL));
	int i;
	
	int row=100,col=100;
      for (i = 0; i < row; i++) {
         for (j = 0; j < col; j++) {
         	n = rand()%10;
            array[i][j]=n;
         }
      }

        printf("\nThe First matrix is:");
      for (i = 0; i < row; i++) {
         printf("\n");
         for (j = 0; j < col; j++) {
            printf("%d ",array[i][j]);
         }
      }

        for (i = 0; i < row; i++) {
         for (j = 0; j < col; j++) {
         	n = rand()%10;
            array2[i][j]=n;
         }
      }

          printf("\nThe Second matrix is:");
      for (i = 0; i < row; i++) {
         printf("\n");
         for (j = 0; j < col; j++) {
            printf("%d ",array2[i][j]);
         }
      }
	
	return 0;
}