/*
  @author : Rahul Thapar
  ID : 1410110321
  Date : 7th Feb, 2017

  Matrix Multiplication using Recursion [128 X 128]

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 128

void matrix_multiply(int[MAX][MAX],int[MAX][MAX],int[MAX][MAX]);
void display(int[MAX][MAX]);

void matrix_multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]){

  static int i = 0, j = 0, k = 0;

  if (i >= MAX)
    return;
  else if (i < MAX){
    if (j < MAX){
      if (k < MAX){
        
        C[i][j] += A[i][k] * B[k][j];
        k++;
        matrix_multiply(A, B, C);
      }
      k = 0;
      j++;
      matrix_multiply(A, B, C);
    }
    j = 0;
    i++;
    matrix_multiply(A, B, C);
  }
}

void display(int C[MAX][MAX]){

  int i, j;
  
  for (i = 0 ; i <= MAX ; i++){
    for (j = 0 ; j <= MAX ; j++)
      printf("%d ", C[i][j]);
    printf("\n");
  }
  printf("\n");
}
 
int main(){

  int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};
  
  clock_t end_t, start_t;
  double total_t;
  srand(time(NULL));
  
  int i, j;
  for(i = 0; i < MAX; i++) {
    for(j = 0; j < MAX; j++) 
      A[i][j] = rand() % 10;
  }
  
  for(i = 0; i < MAX; i++){
    for(j = 0; j < MAX; j++)
      B[i][j] = rand() % 10;
  }

  printf("\t MATRIX A\n ");
  display(A); 
  
  printf("\t MATRIX B\n ");
  display(B);

  start_t = clock();
  
  printf("\t MATRIX C\n");
  matrix_multiply(A, B, C);
  display(C);
  
  end_t = clock();
  total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  printf("TOTAL TIME TAKEN  : %lf\n", total_t);

  return 0; 


}
 
     
