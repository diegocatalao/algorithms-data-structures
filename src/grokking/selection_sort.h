#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Sorts a vector based on the smallest value of the vector for the i-th
 * position. Worst sorting case: O(n^2)
 *
 * @param array {*int} - array of ints
 * @param size {int} - size of array
 */
void selection_sort(int *array, int size);

/**
 * @brief Array pretty print.
 *
 * @param array {*int} - array of ints
 * @param size {int} - size of array
 */
void pretty_print_array(int *array, int size);