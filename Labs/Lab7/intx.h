//Alejandro Aguilar aaguil10@ucsc.edu
/* $Id: intx.h,v 1.4 2012-02-15 20:47:04-08 - - $ */

#ifndef __INTX_H__
#define __INTX_H__

#include <stdbool.h>

/*
 * * NAME
 * *    intx ADT
 * *
 * * DESCRIPTION
 * *    A simple ADT that permits the holding of an integer in a box
 * *    similar to the way Java uses an `Integer' to box an `int'.
 * */

typedef struct intx *intx_ref;
   /*
 *    * The handle pointing at the `intx' box.
 *       */

intx_ref new_intx (void);
   /*
 *    * Constructor: create a new `intx' box initialized to 0.
 *       * Postcond:    new intx box is returned.
 *          */

intx_ref new1_intx (int initvalue);
   /*
 *    * Constructor: create a new `intx' box initialized by caller.
 *       * Postcond:    new intx box is returned.
 *          */

void free_intx (intx_ref this);
   /*
 *    * Destructor: destroys an allocated box
 *       * Precond:    box created by new_intx/1.
 *          * Postcond:   this pointer is dangling.
 *             */

int get_intx (intx_ref this);
   /*
 *    * Accessor:   retrieves the integer from the box.
 *       * Precond:    valid handle to an intx.
 *          * Postcond:   returns the value in the box.
 *             */

void put_intx (intx_ref this, int newvalue);
   /*
 *    * Mutator:    replaces the integer in the box with a new one.
 *       * Precond:    valid handle to an intx.
 *          * Postcond:   old value is lost, new value is kept
 *             */

bool is_intx (intx_ref this);
   /*
 *    * Accessor:   check to see if this is really an intx.
 *       */

#endif
