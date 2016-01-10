//Alejandro Aguilar aaguil10@ucsc.edu
//Alessio Alba acalba@ucsc.edu
//$Id: queue.c,v 1.12 2012-11-21 09:11:17-08 - - $

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

#define STUBPRINTF(...) fprintf (stderr, __VA_ARGS__);

static char *queue_tag = "struct queue";
static char *queuenode_tag = "struct queuenode";

typedef struct queuenode *queuenode_ref;

struct queuenode {
   char *tag;
   queue_item_t item;
   queuenode_ref link;
};

struct queue {
   char *tag;
   queuenode_ref front;
   queuenode_ref rear;
};

queue_ref new_queue (void) {
queue_ref myqueue = malloc(sizeof(struct queue));
myqueue->front = NULL;
myqueue->rear = NULL;
myqueue->tag = queue_tag;
//   STUBPRINTF ("return NULL\n");
   return myqueue;
}

void free_queue (queue_ref queue) {
   assert (is_queue (queue));
   assert (isempty_queue (queue));
   memset (queue, 0, sizeof(struct queue));
   free (queue);
}

void insert_queue (queue_ref queue, queue_item_t item) {
   assert (is_queue (queue));
   queuenode_ref menode = malloc(sizeof(struct queuenode));
   menode->tag = queuenode_tag;
   menode->item = item;
   menode->link = NULL;
   if (isempty_queue(queue)){
      queue->front = menode;
      queue->rear = menode;
   }
else{
   queue->rear->link = menode;
   queue->rear = menode;
}
//   STUBPRINTF ("item =\n\t\"%s\"\n", item);
}

queue_item_t remove_queue (queue_ref queue) {
   char *mys = NULL;
   assert (is_queue (queue));
   assert (! isempty_queue (queue));
   queuenode_ref tmp = queue->front;
   mys = strdup(queue->front->item);
   queue->front = queue->front->link;
   free(tmp);
//   STUBPRINTF ("return NULL\n");
   return mys;
}

bool isempty_queue (queue_ref queue) {
   assert (is_queue (queue));
   return queue->front == NULL;
}

bool is_queue (queue_ref queue) {
   return queue != NULL && queue->tag == queue_tag;
}

