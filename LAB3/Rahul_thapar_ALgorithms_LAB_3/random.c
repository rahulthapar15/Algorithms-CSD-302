

#include <stdio.h>
#include <stdlib.h>
 
int main() {
  int c, n;
   FILE *file_ptr1; 
   // open the file "name_of_file.txt" for writing
   file_ptr1 = fopen("Random_1.txt", "w"); 
 
  for (c = 1; c <= 1000000; c++) {
    n = rand() % 1000000 + 1;
    fprintf(file_ptr1, "%d,", n);
    //printf("%d\n", n);
  }
 
  return 0;
}