// $Id: list.c,v 1.18 2012-11-27 07:58:45-08 - - $

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "debugf.h"
#include "list.h"

static char *list_tag = "struct list";
static char *listnode_tag = "struct listnode";

typedef struct listnode *listnode_ref;

struct list {
   //
   // INVARIANT:  Both head and last are NULL or neither are NULL.
   // If neither are null, then following listnode next links from
   // head will get to last, and prev links from last gets to head.
   //
   char *tag;
   listnode_ref head;
   listnode_ref curr;
   listnode_ref last;
};

struct listnode {
   char *tag;
   char *line;
   listnode_ref prev;
   listnode_ref next;
};

void debugdump_list (list_ref list) {
   listnode_ref itor = NULL;
   assert (is_list (list));
   fflush (NULL);
   fprintf (stderr,
            "\n[%p]->struct list {tag=[%p]->[%s];"
            " head=[%p]; curr=[%p]; last=[%p]; }\n",
            list, list->tag, list->tag,
            list->head, list->curr, list->last);
   for (itor = list->head; itor != NULL; itor = itor->next) {
      fprintf (stderr,
               "[%p]->struct listnode {tag=[%p]->[%s];"
               " line=[%p]=[%s]; prev=[%p]; next=[%p]; }\n",
               itor, itor->tag, itor->tag, itor->line, itor->line,
               itor->prev, itor->next);
   }
   fflush (NULL);
}


list_ref new_list (void) {
   //
   // Creates a new struct list.
   //
   list_ref list = malloc (sizeof (struct list));
   assert (list != NULL);
   list->tag = list_tag;
   list->head = NULL;
   list->curr = NULL;
   list->last = NULL;
   return list;
}

void free_list (list_ref list) {
   assert (is_list (list));
   assert (empty_list (list));
   STUBPRINTF ("list=[%p]\n", list);
}

bool setmove_list (list_ref list, list_move move) {
   assert (is_list (list));
   switch (move) {
      case MOVE_HEAD:
           move_head(list);
           break;
      case MOVE_PREV:
           move_prev(list);
           break;
      case MOVE_NEXT:
           move_next(list);
           break;
      case MOVE_LAST:
           move_last(list);
           break;
      default: assert (false);
   }
   return false;
}

void move_head(list_ref list){
   list->curr = list->head;
   printf("%s\n",list->curr->line);
}
void move_prev(list_ref list){
   list->curr = list->curr->prev;
}
void move_next(list_ref list){
   list->curr = list->curr->next;
}
void move_last(list_ref list){
   list->curr = list->last;
   printf("%s\n",list->curr->line);
}

void printcurrln(list_ref list){
   printf("%s\n",list->curr->line);
}

void print_recur(listnode_ref node){   
   if(node->next = NULL){
      return;
   }else{
   printf("%s\n",node->line);
   print_recur(node->next);
   }
}

void print_file(list_ref list,char *name){
   FILE *outfile;
   outfile = fopen(name, "w");
   if(!outfile){
      printf("Can't open file D="); 
   }else{
      list->curr = list->head;
      for(list->curr = list->head; list->curr != NULL; list->curr = list->curr->next){
         printf("%s\n",list->curr->line);

      }
   fclose(name); 
   }

}

char *viewcurr_list (list_ref list) {
   assert (is_list (list));
//   STUBPRINTF ("list=[%p]\n", list);
   printf("Attempting to print your list Master\n");
   if(list->head->line == list->last->line){
   printf("%s\n",list->head->line);
   }else{
      print_recur(list->head);
   }

   return NULL;
}

void deletenode(list_ref list){
   if(list->head == NULL){
      printf("Nothing here!");
   }
   if(list->curr->line == list->last->line){
     list->curr = list->curr->prev;
     list->curr->next->prev = NULL;
     list->curr->next = NULL;
   }
   if(list->curr == list->head){
      list->curr = list->curr->next;
      list->head = list->head->next;
      list->curr->prev = NULL;
   }

   if(list->curr != list->last && list->curr != list->head){
      list->curr->prev->next = list->curr->next;
      list->curr = list->curr->next;
      list->curr->prev = list->curr->prev->prev;
   }

}


void insert_list (list_ref list, char *liner) {
   assert (is_list (list));
//   STUBPRINTF ("list=[%p], line=[%p]=%s\n", list, line, line);
   printf("You Are Puting Something in the list\n");
   listnode_ref node = malloc (sizeof (struct listnode));
   node->tag = listnode_tag;
   node->line = liner;
   if(list->head == NULL){
   node->prev = NULL;
   node->next = NULL;
   list->head = node;
   list->curr = node;
   list->last = node;
   }else{
   list->last->next = node;
   node->prev = list->last;
   node->next = NULL;
   list->last = node;
   printf("%s\n",node->prev->line);

   }
    
   

}

bool setopt_list (list_ref list, list_opt opt,char *line){
   assert (is_list (list));
   switch(opt) {
      case A_OPT:
           a_opt(list,line);
           break;
      case I_OPT:
           i_opt(list,line);
           break;
      case R_OPT:
           STUBPRINTF ("R_OPT: list=[%p]\n",list);
           break;
      default: assert (false);
   }
   return false;
}

void a_opt(list_ref list,char *liner){
   listnode_ref node = malloc (sizeof (struct listnode));
   node->tag = listnode_tag;
   node->line = liner;
   if(list->curr == NULL){
      list->head = node;
      list->curr = node;
      list->last = node;
      node->prev = NULL;
      node->next = NULL;
   }else{
      if(list->curr->line == list->last->line){
         list->curr->next = node;
         node->prev = list->curr;
         node->next = NULL;
         list->curr = node;
         list->last = node;
      }else{
         node->next = list->curr->next;
         node->prev = list->curr;
         list->curr->next = node;
         list->curr->next->next->prev = node;
         list->curr = node;
      }
   }
}
void i_opt(list_ref list,char *liner){
   listnode_ref node = malloc (sizeof (struct listnode));
   node->tag = listnode_tag;
   node->line = liner;
   if(list->curr == NULL){
      list->head = node;
      list->curr = node;
      list->last = node;
      node->prev = NULL;
      node->next = NULL;
   }else{
      if(list->curr->line == list->head->line){
         list->curr->prev = node;
         node->next = list->curr;
         node->prev = NULL;
         list->head = node;
         list->curr = node;
      }else{
         node->next = list->curr;
         node->prev = list->curr->prev;
         list->curr->prev = node;
         list->curr->prev->prev->next = node;
         list->curr = node;
      }
   }
}



void delete_list (list_ref list) {
   assert (is_list (list));
   assert (! empty_list (list));
   STUBPRINTF ("list=[%p]\n", list);
}

bool empty_list (list_ref list) {
   assert (is_list (list));
   return list->head == NULL;
}

bool is_list (list_ref list) {
   return list != NULL && list->tag == list_tag;
}

