#include "sum.h"

int main(int argc, char *argv) {
  int array[] = {9, 2, 5, 3, 0, 5, 7, 10, 1, 7};
  int size = sizeof(array) / sizeof(array[0]);
  int sum = 0;

  sum = dc_sum(array, size);

  printf("Input array: ");
  pretty_print_array(array, size);

  printf("Division conquer array sum: %d\n", sum);

  return EXIT_SUCCESS;
}

int dc_sum(int *array, int size) {
  if (size == 0) {
    return 0;
  } else if (size == 1) {
    return array[0];
  }

  int middle = size / 2;
  int rsize = size - middle;
  int left_sum = dc_sum(array, middle);
  int right_sum = dc_sum(array + middle, rsize);
  return left_sum + right_sum;
}

void pretty_print_array(int *array, int size) {
  printf("[ ");

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("] \n");
}