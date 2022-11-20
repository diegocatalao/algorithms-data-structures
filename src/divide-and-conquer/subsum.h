#ifndef _H_SUBSUM_
#define _H_SUBSUM_

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZEOF_ARRAY 20
#define true 1
#define false 0

typedef int bool;

int subsum(int set[], int size, int index, int key, int count);

#endif