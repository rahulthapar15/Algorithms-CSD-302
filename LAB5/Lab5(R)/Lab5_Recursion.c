/*
Lab 5
RECURSION
Radhika Raghu
1410110317
*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 128

void multiply(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]){

  static int i = 0, j = 0, k = 0;

  if (i >= SIZE)
    return;
  else if (i < SIZE){
    if (j < SIZE){
      if (k < SIZE){
        
        C[i][j] += A[i][k] * B[k][j];
        k++;
        multiply(A, B, C);
      }
      k = 0;
      j++;
      multiply(A, B, C);
    }
    j = 0;
    i++;
    multiply(A, B, C);
  }
}

void display(int C[SIZE][SIZE]){

  int i, j;
  
  for (i = 0 ; i <= SIZE ; i++){
    for (j = 0 ; j <= SIZE ; j++)
      printf("%d ", C[i][j]);
    printf("\n");
  }
  printf("\n");
}
 
int main(){

  int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE] = {0};
  
  clock_t end_t, start_t;
  double total_t;

  /*Initialising matrix A*/
  int i, j;
  for(i = 0; i < SIZE; i++) {
    for(j = 0; j < SIZE; j++) 
      A[i][j] = rand() % 10;
  }
  
  /*Initialising matrix B*/
  for(i = 0; i < SIZE; i++){
    for(j = 0; j < SIZE; j++)
      B[i][j] = rand() % 10;
  }

  printf("----------Matrix A---------- \n ");
  display(A); 
  
  printf("----------Matrix B---------- \n ");
  display(B);

  start_t = clock();
  
  printf("----------RESULT---------- \n");
  multiply(A, B, C);
  display(C);
  
  end_t = clock();
  total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  printf("Time Taken for performing Matrix Multipicaiton using Recursion : %lf\n", total_t);

  return 0; 


}
 
     
