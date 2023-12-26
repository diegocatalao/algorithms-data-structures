#include "boolean-counter.h"

int main(int argc, char **argv) {
  bool array[] = {true, true, false, false, false, true, false, true, true};
  bool array_s = sizeof(array) / sizeof(array[0]);
  int key_count = 0;

  /* Count false elements */
  key_count = boolean_counter(array, false, 0, array_s);
  printf("False elements quantity: %d\n", key_count);

  return 0;
}

int boolean_counter(bool *array, bool key, int inf, int sup) {
  if (sup - inf == 1) {
    printf("Saída: %d\n", array[inf]);
    return array[inf] == key ? 1 : 0;
  }

  int middle = (inf + sup) / 2;
  int left = boolean_counter(array, key, inf, middle);
  int right = boolean_counter(array, key, middle, sup);

  return left + right;
}