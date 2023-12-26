#include "merge_sort.h"

int main(int argc, char **argv) {
  int array[] = {9, 2, 5, 3, 0, 5, 7, 10, 1, 7};
  int size = sizeof(array) / sizeof(array[0]);

  printf("Input array: ");
  pretty_print_array(array, size);

  merge_sort(array, 0, size);

  printf("Sorted array: ");
  pretty_print_array(array, size);

  return EXIT_SUCCESS;
}

void merge(int *array, int left, int middle, int right) {
  int seeker = 0;
  int *array_buffer;
  int left_aux = left;
  int middle_aux = middle + 1;
  int right_aux = right - left + 1;

  array_buffer = (int *)malloc(right_aux * sizeof(int));

  while (left_aux <= middle && middle_aux <= right) {
    if (array[left_aux] < array[middle_aux]) {
      array_buffer[seeker] = array[left_aux];
      left_aux++;
    } else {
      array_buffer[seeker] = array[middle_aux];
      middle_aux++;
    }
    seeker++;
  }

  // left case
  while (left_aux <= middle) {
    array_buffer[seeker] = array[left_aux];
    seeker++;
    left_aux++;
  }

  // right case
  while (middle_aux <= right) {
    array_buffer[seeker] = array[middle_aux];
    seeker++;
    middle_aux++;
  }

  // array buffer to original array
  for (seeker = left; seeker <= right; seeker++) {
    array[seeker] = array_buffer[seeker - left];
  }

  free(array_buffer);
}

void merge_sort(int *array, int left, int right) {
  if (left < right) {
    int middle = (left + right) / 2;

    merge_sort(array, left, middle);
    merge_sort(array, middle + 1, right);
    merge(array, left, middle, right);
  }
}

void pretty_print_array(int *array, int size) {
  printf("[ ");

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("] \n");
}