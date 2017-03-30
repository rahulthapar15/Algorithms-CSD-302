//////////////////////////////////////////////////////////////////////////////////////
//Name          :mtrx_chn_mltpn.c
//Copyright     :Copyright Vivek Malik,2012
//Created on    :22-Apr-2012
//Author        :Vivek Malik
//Description   :To perform Matrix Chain Multiplication
//////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<limits.h>
#include<math.h>

int s_print[50][50];

int MatrixChainOrder(int p[], int );
void PrintOptimalParens(int s[50][50],int, int );

int main(){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    int arr[50],i,n;
    printf("Enter the length of chain order(max of 50):");
    scanf("%d",&n);
    printf("Enter the chain order:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
//  int size = (sizeof(arr)/sizeof(arr[0]))-1;
    printf("\nMinimum number of multiplications is %d\n",MatrixChainOrder(arr, (n-1)));
    printf("The Parenthesization is : ");
    PrintOptimalParens(s_print,1,(n-1));
    return(0);
}

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int n)
{
    /* For simplicity of the program, one extra row and one extra column are
    allocated in m[][].  0th row and 0th column of m[][] are not used */
    int m[n][n];
    int s[n-1][n-1];
    int i, j, k, L, q;

    /* m[i,j] = Minimum number of scalar multiplications needed to compute
       the matrix A[i]A[i+1]...A[j] = A[i..j] where dimention of A[i] is
       p[i-1] x p[i] */

    // cost is zero when multiplying one matrix.
    for (i = 1; i <=n; i++){
        m[i][i] = 0;
        s[i][i]=0;
    }
    // L is chain length.
    for (L=2; L<=n; L++){
        for (i=1; i<=n-L+1; i++){
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++){
                // q = cost/scalar multiplications
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i>j){
                s_print[i][j]=0;
            }
            else{
                s_print[i][j]=s[i][j];
            }
//          printf("%d\t\t",s_print[i][j]);
        }
//      printf("\n");
    }
    return m[1][n];
}

void PrintOptimalParens(int s[50][50],int i, int j){
    if(i==j){
        printf("A%d",i);
    }
    else{
        printf("(");
        PrintOptimalParens(s,i,s[i][j]);
        PrintOptimalParens(s,s[i][j]+1,j);
        printf(")");
    }
}