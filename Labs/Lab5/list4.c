

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node *node_ref;
struct node {
   char *word;
   node_ref link;
};

int main (int argc, char **argv) {
   node_ref head;
   head = NULL;
   for (int argi = 0; argi < 5; ++argi) {
      node_ref node = malloc (sizeof (struct node));
      assert (node != NULL);
      node->word = argv[argi];
      node->link = head;
      head = node;
   }

   for (node_ref curr = head; curr->link != NULL; curr = curr->link) {
      printf ("%p->node {word=%p->[%s], link=%p}\n",
              curr, curr->word, curr->word, curr->link);
   }

 free_all(head);




   return 9;
}

void free_all(node_ref curr){
   if(curr == NULL){
        return;
   }
   free_all(curr->link);
   free(curr);
}

