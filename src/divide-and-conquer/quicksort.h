#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Swap from two array positions.
 *
 * @param array {int *} - array of elements
 * @param left {int} - left element inside array
 * @param right {int} - right element inside array
 */
void swap(int *array, int left, int right);

/**
 * @brief Split array into smaller cases and swap larger and smaller ones on
 * either side.
 *
 * @param array {int *} - array of elements
 * @param left {int} - left element inside array
 * @param right {int} - right element inside array
 * @return int - pivot element
 */
int split(int *array, int left, int right);

/**
 * @brief Sort an array with O(n²) complexity
 *
 * @param array {int *} - array of elements
 * @param left {int} - left element inside array
 * @param right {int} - right element inside array
 */
void quicksort(int *array, int left, int right);

/**
 * @brief Array pretty print.
 *
 * @param array {*int} - array of ints
 * @param size {int} - size of array
 */
void pretty_print_array(int *array, int size);