/*
  @author : Rahul Thapar , Sonali Shankar
  @ID : 1410110321 , 1410110425
  Date : 8th Feb,2017
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int arr[MAX];
int temp1[MAX];
int temp2[MAX];
int main(){

  int m,n,i,j,k;
  int count=0;

  printf("Enter number of Gas Stations : ");
  scanf("%d",&n);
  printf("Maximum Distance : ");
  scanf("%d",&m);
  printf("Gas stations at distances : \n");

  for(i=0;i<n;i++){
    scanf("%d",arr+i);
  }
  
  temp2[0]=1;
  j=k=count=0;
  for(i=1;i<n;i++)
    {
      while(arr[i]-arr[j] > m)
    count-=temp2[j++];
      temp1[i]=temp1[j]+1;
      while(temp1[k]==temp1[j])
    count+=temp2[k++];
      temp2[i]=count;
    }
  printf("Minimum Number of Stops : %d\n",temp1[n-1]-1);
  return 0;
} 