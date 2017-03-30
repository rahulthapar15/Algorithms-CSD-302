#include<stdio.h>
#include<stdlib.h>
int events[1000];
void main()
{
 srand(time(NULL));
 

 int i,a,b,c,num=0,face1=0,face2=0,face3=0,face4=0,face5=0,face6=0;
 float prob1,prob2,prob3,prob4,prob5,prob6;
 for( i=1;i<=1000;i++)
 {
    a = rand()%2;
    b = rand()%2;
    c = rand()%2;
    //printf("   %d %d %d   ",a,b,c);
    num=a*4+b*2+c;
    while(num==0||num==7)
    {
        a = rand()%2;
        b = rand()%2;
        c = rand()%2;
        num=a*4+b*2+c;
        
    }
    events[i]=num;
    
    
    

 }
 for(i=1;i<=1000;i++)
 {
    
    if(events[i]==1)
      face1++;
    if(events[i]==2)
      face2++;
    if(events[i]==3)
      face3++;
    if(events[i]==4)
      face4++;
    if(events[i]==5)
      face5++;
    if(events[i]==6)
      face6++;
    
    
    
 }
 prob1= (float)face1/1000;
 prob2= (float)face2/1000;
 prob3= (float)face3/1000;
 prob4= (float)face4/1000;
 prob5= (float)face5/1000;
 prob6= (float)face6/1000;
 printf("\n Event = 1 Probability = %f ",prob1);
 printf("\n Event = 2 Probability = %f ",prob2);
 printf("\n Event = 3 Probability = %f ",prob3);
 printf("\n Event = 4 Probability = %f ",prob4);
 printf("\n Event = 5 Probability = %f ",prob5);
 printf("\n Event = 6 Probability = %f ",prob6);

}