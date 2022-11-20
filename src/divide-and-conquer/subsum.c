#include "subsum.h"

int main(int argc, char **argv) {
  int key = 50000;
  bool result = false;
  int set[DEFAULT_SIZEOF_ARRAY];

  for (int i = 0; i < DEFAULT_SIZEOF_ARRAY; i++)
    set[i] = i + 1;

  result = subsum(set, DEFAULT_SIZEOF_ARRAY, 0, key, 0);
  if (result)
    printf("Subset found.\n");
  else
    printf("Subset not found.\n");
  return EXIT_SUCCESS;
}

bool subsum(int set[], int size, int index, int key, int count) {
  if (index == size) {
    if (key == 0)
      count++;
    return count;
  }

  count = subsum(set, size, index + 1, key - set[index], count);
  count = subsum(set, size, index + 1, key, count);

  return count > 0 ? true : false;
}