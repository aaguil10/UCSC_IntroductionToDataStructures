//Alejandro Aguilar aaguil10@ucsc.edu
//$Id: intx.c,v 1.4 2012-11-01 19:33:32-07 - - $ 

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intx.h"

static char *intx_tag = "struct intx";

struct intx {
   char *tag;
   int value;
};

intx_ref new_intx (void) {
   return new1_intx (0);
}

intx_ref new1_intx (int initvalue) {
   intx_ref new = malloc (sizeof (struct intx));
   assert (new != NULL);
   new->tag = intx_tag;
   new->value = initvalue;
   return new;
}

void free_intx (intx_ref this) {
   assert (is_intx (this));
   memset(this, 0, sizeof (struct intx));
   free (this);
}

int get_intx (intx_ref this) {
   assert (is_intx (this));
   return this->value;
}

void put_intx (intx_ref this, int newvalue) {
   assert (is_intx (this));
   this->value = newvalue;
}

bool is_intx (intx_ref this) {
   return this != NULL && this->tag == intx_tag;
}
