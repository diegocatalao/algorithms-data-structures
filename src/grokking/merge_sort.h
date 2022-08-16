#ifndef _H_MERGE_SORT
#define _H_MERGE_SORT

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Splits the problem into halves for a buffer vector and reassembles
 * the original vector with the sorted buffer.
 *
 * @param array {int*} - array of numbers
 * @param left {int} - left element index
 * @param middle {int} - middle element index
 * @param right {int} - right element index
 */
void merge(int *array, int left, int middle, int right);

/**
 * @brief Merge sort recursive calls
 *
 * @param array {int*} - array of numbers
 * @param left {int} - left element index
 * @param right {int} - right element index
 */
void merge_sort(int *array, int left, int right);

/**
 * @brief Array pretty print.
 *
 * @param array {*int} - array of ints
 * @param size {int} - size of array
 */
void pretty_print_array(int *array, int size);

#endif