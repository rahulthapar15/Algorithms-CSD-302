#include <stdio.h>
#define SIZE 1

//Protoype
int moveTower(int, int, int, int);

main()
{
	//Declaration
	int input=0;
	int i=0;
	
	while (input < SIZE)
	{
		printf("Please enter the number of discs you would like within the tower:\n");
		scanf("%d", &input);
		
		if (input < SIZE)
		{
			printf("You must enter a number of discs great than zero!\n");
		}//end if
		
	}//end while
		
	//Call function moveTower to begin recursion
	i = moveTower(input, 1, 3, 2);

	printf("\n\nYour tower is now complete!");
	printf("\nThe number of movies is %d", i);
	
}//end main

int moveTower(int disc, int source, int dest, int spare)
{
	//Declaration
	static int i=0;
	
	i++;
	
	if (disc == 1)
	{
		printf("\nMove a disc from Tower %d to tower %d", source, dest);
		return i;
	}//end if
	
	else
	{
		//Recursive Call
		moveTower(disc - 1, source, spare, dest);
			
		printf("\nMove a disc from Tower %d to tower %d", source, dest);
		
		//Recursive Call
		moveTower(disc - 1, spare, dest, source);
	}//end else
	
}//end tower()
