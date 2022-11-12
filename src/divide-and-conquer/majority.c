#include "majority.h"

int main(int argc, char **argv) {
  int array[] = {2, 2, 2, 5, 5, 0, 3, 1, 1, 2, 2, 2};
  int array_s = sizeof(array) / sizeof(array[0]);
  int element = 0;

  // find highest frequency element
  element = majority(array, 0, array_s);
  printf("Highest frequency element is: %d\n", element);

  return 0;
}

int count_in_range(int *array, int key, int inf, int sup) {
  int count = 0;
  for (int index = inf; index <= sup; index++) {
    if (array[index] == key) count++;
  }

  return count;
}

int majority(int *array, int inf, int sup) {
  int left = 0;
  int right = 0;
  int middle = (sup - inf) / 2 + inf;

  int left_count = 0;
  int right_count = 0;

  if (inf == sup) return array[inf];

  left = majority(array, inf, middle);
  right = majority(array, middle + 1, sup);

  if (left == right) return left;

  left_count = count_in_range(array, left, inf, sup);
  right_count = count_in_range(array, right, inf, sup);

  return left_count > right_count ? left : right;
}