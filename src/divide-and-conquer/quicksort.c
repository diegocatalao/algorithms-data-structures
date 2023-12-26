#include "quicksort.h"

int main(int argc, char **argv) {
  int array[] = {9, 2, 5, 3, 0, 5, 7, 10, 1, 7};
  int size = sizeof(array) / sizeof(array[0]);

  printf("Input array: ");
  pretty_print_array(array, size);

  quicksort(array, 0, size - 1);

  printf("Sorted array: ");
  pretty_print_array(array, size);

  return EXIT_SUCCESS;
}

void swap(int *array, int left, int right) {
  int temp = array[left];
  array[left] = array[right];
  array[right] = temp;
}

int split(int *array, int left, int right) {
  int i = left + 1;
  int j = right;
  int pivot = array[left];
  while (i <= j) {
    if (array[i] <= pivot)
      i++;
    else if (array[j] > pivot)
      j--;
    else if (i <= j) {
      swap(array, i, j);
      i++;
      j--;
    }
  }

  swap(array, left, j);
  return j;
}

void quicksort(int *array, int left, int right) {
  if (left < right) {
    int index = split(array, left, right);
    quicksort(array, left, index - 1);
    quicksort(array, index + 1, right);
  }
}

void pretty_print_array(int *array, int size) {
  printf("[ ");

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("] \n");
}