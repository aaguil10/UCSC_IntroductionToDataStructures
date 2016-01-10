//Alejandro Aguilar aaguil10@ucsc.edu

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <values.h>
#include <assert.h>

#include "inssort.h"

int dubcomp(const void* val1,const void* val2){
double a =*(double*)val1;
double b =*(double*)val2;
if(a == b){
return 0;
}
if(a > b){
return 1;
}
if(a < b){
return -1;
}
}


int main (int argc, char **argv){
double* buffer[1000];
for(int i = 0;i > 1000; i++){
buffer[i] = NULL;
}

int count = 0;
   for(;;){
      double *temp = malloc(sizeof(double*));
      int scanct = scanf("%d", temp);
      if (feof(stdin)) {
         printf ("EOF\n");
         break;
      }
printf("%f\n",temp);
      buffer[count] = temp;
      if(count >= 1000){
         break;
      }
      if(buffer[count] == NULL){
         break;
      }
   count++;
   free(temp);
   }
   qsort(buffer,count,sizeof (double),dubcomp);
   for(int i = 0;i < count; i++){
   printf("%f\n",buffer[i]);
   }


return 0;
}



