
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugf.h"
#include "hashset.h"
#include "strhash.h"

#define HASH_NEW_SIZE 15

struct hashset {
   size_t length;
   int load;
   char **array;
};

hashset_ref new_hashset (void) {
   hashset_ref new = malloc (sizeof (struct hashset));
   assert (new != NULL);
   new->length = HASH_NEW_SIZE;
   new->load = 0;
   new->array = malloc (new->length * sizeof (char*));
   assert (new->array != NULL);
   for (size_t index = 0; index < new->length; ++index) {
      new->array[index] = NULL;
   }
   DEBUGF ('h', "%p -> struct hashset {length = %d, array=%p}\n",
                new, new->length, new->array);
   return new;
}

void free_hashset (hashset_ref hashset) {
   DEBUGF ('h', "free (%p), free (%p)\n", hashset->array, hashset);
   memset (hashset->array, 0, hashset->length * sizeof (char*));
   free (hashset->array);
   memset (hashset, 0, sizeof (struct hashset));
   free (hashset);
}

void put_hashset (hashset_ref hashset, char *item) {
//   STUBPRINTF ("hashset=%p, item=%s\n", hashset, item);
   size_t le_load = hashset->load * 4;
   if((le_load * 4) > hashset->length){
      hashset->length = (hashset->length*2)+1;
      char** myarray = malloc(hashset->length*sizeof(char*));
      for (size_t dex = 0; dex < hashset->length; ++dex) {
         hashset->array[dex] = NULL;
      }
      for(size_t index = 0; index < hashset->length; index++){
         if(hashset->array[index] != NULL){
            int a = strhash(hashset->array[index]) % hashset->length;
printf("array index is = to %d\n",a);
            myarray[a] = strdup(hashset->array[index]);
         }
      }
      hashset_ref temp = hashset;
      temp->length = 0;
      temp->load = 0;
      hashset->array = myarray;
      free_hashset (temp);
      }
   int le_item_index = strhash(item) % hashset->length;
   int count = 1;
   while(hashset->array[le_item_index] != NULL){
   if(strcmp(hashset->array[le_item_index],item) == 0){
      return;
   }
   le_item_index = (strhash(item) + count) % hashset->length;
   count = count + 1;
   }
   hashset->array[le_item_index] = item;
   hashset->load = (hashset->load + 1);
   }




bool has_hashset (hashset_ref hashset, char *item) {
//   STUBPRINTF ("hashset=%p, item=%s\n", hashset, item);
   int index = strhash(item) % hashset->length;
   int count = 1;
printf("inside has next\n");
printf("hashset->array[index]: %s index: %d\n",hashset->array[index], index);
   while(hashset->array[index] != NULL){
printf("inside while\n");
      if(strcmp(hashset->array[index],item) == 0){
printf("true\n");
         return true;
      }else{
printf("was not true\n");
         index = (strhash(item) + count) % hashset->length;
         count = count + 1;
      }

   }
   return false;
}


size_t return_length(hashset_ref hashset){
   return hashset->length;
}

char** return_array(hashset_ref hashset){
   return hashset->array;
}

void option_x (hashset_ref hashset){
   printf("%d words in the hash set", hashset->load);
   int array_size = hashset->length;
   printf("%d length of the hash array", array_size);
   int count_of_cluster[hashset->length];
   for(int q = 0; q < array_size; q++){
      count_of_cluster[q] = 0;
   }

   int size_of_cluster = 0;
   for(int i = 0; i < array_size; i++){
      while(hashset->array[i] != NULL){
         size_of_cluster = size_of_cluster + 1;
      }
      for(int k = 0; k < i; k++){
         if(size_of_cluster == k){
            count_of_cluster[k] = count_of_cluster[k] + 1;
         }
      }   
      i = i + size_of_cluster;
      size_of_cluster = 0;
   }
   for(int f = 0; f < array_size; f++){
      if(count_of_cluster[f] != 0){
         printf("%d clusters of size %d\n",count_of_cluster[f],f);
      }

   }




}
