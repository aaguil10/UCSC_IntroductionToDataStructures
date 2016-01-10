//Alejandro Aguilar aaguil10@ucsc.edu

#ifndef __INSSORT_H__
#define __INSSORT_H__

#include <stdio.h>

void inssort (void *base, size_t nelem, size_t size,int (*compar) (const void *, const void *));

#endif
