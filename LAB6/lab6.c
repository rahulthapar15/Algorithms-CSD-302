#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){

	int stationDist[6]={0, 200, 375, 550, 750, 950};
	int maxDistance = 400;
	int i;
	int curPos = 1;
    int minRefill = 0;
    int curDistance = maxDistance;

    int numRefillStations = 6; //(stationDist.length - 1);

     while (curPos <= (numRefillStations)) {
       for (curPos=1; stationDist[curPos] <= curDistance; curPos += 1){

       if (curPos > numRefillStations){
     printf("%d\n", minRefill);
     } //minRefill;

       curPos -= 1;
       minRefill += 1;
       curDistance = stationDist[curPos] + maxDistance;
     }
    }
     if (stationDist[curPos] < curDistance)
       minRefill += 1;

    printf("%d",minRefill);
   }