#include "selection_sort.h"

int main(int argc, char **argv) {
  int array[] = {9, 2, 5, 3, 0, 5, 7, 10, 1, 7};
  int size = sizeof(array) / sizeof(array[0]);

  printf("Input array: ");
  pretty_print_array(array, size);

  selection_sort(array, size);

  printf("Sorted array: ");
  pretty_print_array(array, size);

  return EXIT_SUCCESS;
}

void selection_sort(int *array, int size) {
  int min = 0, aux = 0;

  for (int i = 0; i < size - 1; i++) {
    min = i;

    for (int j = (i + 1); j < size; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }

    if (i != min) {
      aux = array[i];
      array[i] = array[min];
      array[min] = aux;
    }
  }
}

void pretty_print_array(int *array, int size) {
  printf("[ ");

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("] \n");
}