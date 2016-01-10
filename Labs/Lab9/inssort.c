//Alejandro Aguilar aaguil10@ucsc.edu
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <values.h>


void inssort (void *base, size_t nelem, size_t size, int (*compar) (const void *, const void *)){
   for(int sorted = 1; sorted < nelem; ++sorted){
      int slot = sorted;
      void* copy = base + (slot*size);
      for(; slot > 0; -- slot){
         int cmp = compar(copy, slot);
         if(cmp > 0) break;
         void* var1 = memcpy((base + (slot*size)),(base + ((slot-1)*size)),size);
      }
    void* var2 = memcpy(copy, (base + (slot*size)), size);
   }
}
