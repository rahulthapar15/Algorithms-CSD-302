/***
  
  NAME : Rahul Thapar
  ID : 1410110321
  DATE : 18-01-2017

***/


#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void main(){

	srand(time(NULL));
	int i;
	int events[MAX];
	int outcome_1, outcome_2, outcome_3;
	int number =0;
	int f1=0,f2=0,f3=0,f4=0,f5=0,f6=0;
	float p1, p2, p3, p4, p5, p6;

	for(i=0;i<MAX;i++){
		outcome_1 = rand()%2;
    	outcome_2 = rand()%2;
   		outcome_3 = rand()%2;

   		number = (outcome_1*4)+(outcome_2*2)+outcome_3;


   	while(number==0||number==7)
    {
        outcome_1 = rand()%2;
        outcome_2 = rand()%2;
        outcome_3 = rand()%2;
        number = (outcome_1*4)+(outcome_2*2)+outcome_3;
        
    }
    events[i]=number;
}

	for(i=1;i<=MAX;i++){
	    if(events[i]==1)
    	  f1++;
    	if(events[i]==2)
      		f2++;
    	if(events[i]==3)
      		f3++;
   		 if(events[i]==4)
      		f4++;
   		 if(events[i]==5)
      		f5++;
    	if(events[i]==6)
      		f6++;
 }
 printf("\n Probability for Event 1:  %f ",(float)f1/1000);
 printf("\n Probability for Event 2:  %f ",(float)f2/1000);
 printf("\n Probability for Event 3:  %f ",(float)f3/1000);
 printf("\n Probability for Event 4:  %f ",(float)f4/1000);
 printf("\n Probability for Event 5:  %f ",(float)f5/1000);
 printf("\n Probability for Event 6:  %f ",(float)f6/1000);
 printf("\n");
}