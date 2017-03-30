#include<stdio.h>
#include<math.h>

void TowerOfHanoi(int,char,char,char);

void main(){
	int disk;
	int steps;

	printf("Number of Disks : ");
	scanf("%d",&disk);

	steps = pow(2,disk)-1;
	printf("%d steps required to complete.\n",steps);

	TowerOfHanoi(disk,'A','B','C');
}

void TowerOfHanoi(int n,char source,char dest, char aux){

	if(n==1){
		printf("Disk %d from %c to %c \n",n,source,dest);	
	}else
	if(n==0){printf("Try Again!");}
	else{
		TowerOfHanoi(n-1,source,aux,dest);
		printf("Disk %d from %c to %c \n",n,source,aux);
		TowerOfHanoi(n-1,aux,dest,source);	
	}
}
