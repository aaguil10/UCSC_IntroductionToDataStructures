//Alejandro Agilar aaguil10@ucsc.edu
// $Id: nsort.c,v 1.1 2011-04-29 19:46:42-07 - - $

#include <assert.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node *node_ref;
struct node {
   double item;
   node_ref link;
};


int main (int argc, char **argv) {

   node_ref head = NULL;

   for(;;){
      char buffer[4096];
      int scanct = scanf ("%4095s", buffer);
      if(scanct == EOF) {
         printf("EOF\n");
         break;
      }
      
      
      assert (scanct == 1);
      size_t length = strlen (buffer);
      if(buffer[0] == '#'){
         scanf ("%4095[^\n]",buffer);
         continue;
      }
      if(scanct == '\0'){
      printf("you sayed %s\n",buffer);
      node_ref new = malloc (sizeof (struct node));
      assert (new != NULL);
      new->item = buffer;
      new->link = head;
      head = new;
      }else{
         printf("error");
         break;
      }

   }
 
   printf ("&head= %p\n", (void*) &head);
   printf ("head= %p\n", (void*) head);
   for (node_ref curr = head; curr != NULL; curr = curr->link) {
      printf ("%p -> struct node {item= %.15g, link= %p}\n",
              (void*) curr, curr->item, (void*) curr->link);
   }
   printf ("NULL= %p\n", (void*) NULL);
   while (head != NULL) {
      node_ref old = head;
      head = head->link;
      printf("you freed :%s\n",old->item);
      free (old);
   }

 returar buffer[4096];
      int scanct = scanf ("%4095s", buffer);
      if(scanct == EOF) {
         printf("EOF\n");
         break;
      }


      assert (scanct == 1);
      size_t length = strlen (buffer);
      if(buffer[0] == '#'){
         scanf ("%4095[^\n]",buffer);
         continue;
      }

      printf("you sayed %s\n",buffer);
      node_ref new = malloc (sizeof (struct node));
      assert (new != NULL);
      theitem = buffer;
      new->item = theitem;
      new->link = head;
      head = new;

   }

   printf ("&head= %p\n", (void*) &head);
   printf ("head= %p\n", (void*) head);
   for (node_ref curr = head; curr != NULL; curr = curr->link) {
      printf ("%p -> struct node {item= %.15g, link= %p}\n",
              (void*) curr, curr->item, (void*) curr->link);
   }
   printf ("NULL= %p\n", (void*) NULL);
   while (head != NULL) {
      node_ref old = head;
      head = head->link;
      printf("you freed :%s\n",old->item);
      free (old);
   }

 return 0;
}
` 0;
(
