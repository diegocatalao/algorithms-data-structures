#ifndef _H_DC_SUM
#define _H_DC_SUM

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Split an array into smaller arrays and recursively sum their elements.
 *
 * @param array {int*} - array to sum
 * @param size {int} - array length
 * @return int - sum of elements
 */
int dc_sum(int *array, int size);

/**
 * @brief Array pretty print.
 *
 * @param array {*int} - array of ints
 * @param size {int} - size of array
 */
void pretty_print_array(int *array, int size);

#endif