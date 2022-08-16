#ifndef _H_BINARY_SEARCH
#define _H_BINARY_SEARCH

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief a pretty print for 1D vector
 *
 * @param vector - a array of integers
 * @param size - size of array
 */
void print_vector(int *vector, int size);

/**
 * @brief binary search algorithm for 1D vector of ints
 *
 * @param vector - a array of integers
 * @param size - size of array
 * @param value - value to search
 * @return int - index of element (value) in array
 */
int binary_search(int *vector, int size, int value);

#endif