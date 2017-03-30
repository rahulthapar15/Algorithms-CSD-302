/*
    @author : Rahul Thapar
    ID : 1410110321

    Write a program to implement Matrix Chain Multiplication 
    and test it on the following input {20, 10, 5, 35, 45, 5, 10, 15}.
*/

#include<stdio.h>
#define MAX 35000
#define SIZE 20

int m[SIZE][SIZE],s[SIZE][SIZE];

void print_Sol(int i,int j)
{

    //getch();
    if(i==j)
    printf("A%d " ,i);
    else if(j>i)
    {
    printf("(");
    print_Sol(i,s[i][j]);
    print_Sol(s[i][j]+1,j);
    printf(")");
    }
    
}

void matrix_multiply_parenthesis(int p[],int n)
{
    
    // m : store the minimum multiplcation cost
    //s[i][j] : sore the value of index k giving least multiplication cost for ai x aj

    int i,j,k,l,q=MAX,q_min_prev=MAX;
    int p_count=1;

   for(i=1;i<=n;i++)
   {
       m[i][i] = 0;
   }
   printf("\t---------------------\n");
   printf("\t Possible Solutions \n");
   printf("\t---------------------\n");


    for(l=2;l<=n;l++) //l is the length of the chain
    {
        for(i=1;i<=n-l+1;i++) //starting index of chain of length l
        {
         j=i+l-1; // ending index of chain of length l
         m[i][j] = MAX;
             for(k=i;k<j;k++)
             {
                   
                   q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                    printf("\t-> %d. %d\n",p_count,q);
                    p_count++;
                   if(q < m[i][j])
                   {
                       m[i][j] = q;
                       s[i][j] = k;
                   }
            }
        }
    }
}


int main()
{
    int p[SIZE]={20, 10, 5, 35, 45, 5, 10, 15};
    int n=7,i,j;
   
   printf("\n\t   MATRIX CHAIN MULTIPLICATION\n");
   printf("\n");

    matrix_multiply_parenthesis(p,n);
    printf("\t------------------------\n");
    printf("\tMatrix Sequence\n");
    printf("\t-------------------------\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
           printf("\t %d ",s[i][j]);
        }
        printf("\n");
    }
      printf("\t--------------------------------\n");
      printf("\t Putting Optimal Paranthesis\n");
      printf("\t---------------------------------\n");
    print_Sol(1,n);
    printf("\n\n");
}