//Alejandro Aguilar aaguil10@ucsc.edu

//#include <ctype.h>
//#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <values.h>
#include <assert.h>

#include "inssort.h"

int charcmp(const void* val1,const void* val2){

return (strcmp (*(char**)val1, *(char**)val2));
} 

int main (int argc, char **argv){
char* buffer[1000];
for(int i = 0;i > 1000; i++){
buffer[i] = NULL;
}

int count = 0;
   for(;;){
      char *temp = malloc(sizeof(char*));
      int scanct = scanf("%s",temp);
      if (feof(stdin)) {
         printf ("EOF\n");
         break;
      }
      if(count >= 1000){
         break;
      }
      buffer[count] = strdup(temp);
      if(buffer[count] == NULL){
         break;
      }
	count++;
	free(temp);
   }
   inssort(buffer,count,sizeof (double *),charcmp);
   for(int i = 0;i < 1000; i++){
   if(buffer[i] == NULL){
   break;
   }
  // printf("write sum'in");
   printf("%s\n",buffer[i]);
   }


return 0;
}


