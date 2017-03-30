/*
    @author : Rahul Thapar
    ID : 1410110321
    Date : 15 Feb, 2017

    1. Prim's Algorithm
    2. Kruskal's Algorithm

*/
#include <stdio.h>
#include <stdlib.h>

void main(){

	printf("\n\t Implement :\n");
	printf("\t ++++++++++++++\n");
	printf("\n\t 1. Prim's Algorithm\n");
	printf("\t 2. Kruskal's Algorithm\n");

	int choice;
	printf("\n\t CHOICE : ");
	scanf("%d",&choice);

	switch(choice){
		case 1: PrimsFileChose();
				break;

		case 2 : printf("\n\t PENDING\n" );
				break;

		default : printf("Enter the correct option\n");
					break;
	}
}

PrimsFileChose(){
	printf("\t Take input from : \n");
	printf("\t 1. Graph 1 : Node = 4\n");
	printf("\t 2. Graph 2 : Node = 5 \n");
	/*printf("\t 3. Graph 3 : Node = 6\n");*/
	int prim_file;
	printf("\n \t FILE NUMBER : ");
	scanf("%d",&prim_file);

	printf("\t File Loaded : %d\n",prim_file);

	Prim_Implement(prim_file);
}
Prim_Implement(int file_number){

	FILE *file1;
    int d[50][50];
    int a[10];
    int i,j,ch,data,first,zz=0,xx,k,yy,y1=0,y2=0;
   	int title=0,titlecc=0;
   	int total_distance =0, p=0;
	char c;
	for(i=0;i<10;i++){
     a[i]=100;
	}
	switch(file_number){
			case 1: /*printf("Case 1\n");*/
					file1=fopen("graph1.txt","r");
          Implement_Algorithm(file1);
					break;

			case 2 : //printf("Case 2 \n");
              file1=fopen("graph2.txt","r");
              Implement_Algorithm(file1);
					break;

			default : printf("File doesn't exists\n");
					break;

	}
}
Implement_Algorithm(FILE *file1){

    int d[50][50];
    int a[10];
    int i,j,ch,data,first,zz=0,xx,k,yy,y1=0,y2=0;
    int title=0,titlecc=0;
    int total_distance =0, p=0;
  char c;

  while((c=getc(file1))!=EOF){
              
              if(c=='\n'){
                   if(titlecc==1){
                      first++; 
                    }
                      data=0;
                      ch=0;
                      titlecc=1;
                      continue;
                }
                if(c=='\t'){
                  data++;
                  ch=0;
                   continue;
                 }   
       
                  if(ch==0){
                   if(titlecc==1){
                        d[first][data]=c-'0'; 
                    }
                  else{
                  title=c-'0';
                }
        
              ch=1;
             }else  {
                 d[first][data]=(c-'0')+d[first][data]*10;
              }
      }
      fclose(file1);
printf("\t Number of Nodes = %d\n\n",title);
printf("\t ==============================================================================================\n");
for(i=0;i<title;i++){
for(j=0;j<title;j++){
printf("\t d[%d][%d]=%d\t",i+1,j+1,d[i][j]);
}
printf("\n");
}
printf("\t ==============================================================================================\n");
//main

for(k=1;k<9;k++){
    for(i=0;i<title;i++){
        for(j=0;j<title;j++){
                             
            if(d[i][j]==k){
            
            a[zz]=i+1;
            a[zz+1]=j+1;                 
            y1=0;
            y2=0; 
                            
            /*for(yy=0;yy<8;yy++){
                 if((i+1)==a[yy]){y1=y1+1;}
                 if((j+1)==a[yy]){y2=y2+1;}
                 printf("a[%d]=%d\n",yy,a[yy]);                                      
            }                    
            printf("\n");*/
            if(y1==2 && y2==2 && a[7]==4){
              printf("be a ...loop \n\n");
            }
            else
            {                
                //printf("aa=%d\n\n",aa); 
                          
                zz=zz+2;          
                total_distance=total_distance+k;
                
                printf("\n\tEdge : d[%d][%d]=%d\n",i+1,j+1,d[i][j]);
                d[j][i]=100;
                d[i][j]=100;               
                printf("\tTotal Distance = %d\n\n",total_distance);
                p=p+1;
                i=title;
                j=title;
                if(p==(title-1)){
                    k=15;
                    printf("\n.................\n");
                }
            }
            }
                                            
                      
        }
    }
    
}

}