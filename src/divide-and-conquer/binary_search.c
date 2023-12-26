/**
 * @file binary_search.c
 * @author Diego Catalão (catalao.diego@graduacao.uerj.br)
 * @brief Finds the position of a target value within a sorted array.
 * @version 0.0.1
 * @date 2022-08-07
 */

#include "./binary_search.h"

int main(int argc, char **argv) {
  int *vector;
  int vector_size = 0;
  int random_number = 0;
  int finded_number = 0;

  // user input
  printf("Tell me the array size: ");
  scanf("%d", &vector_size);

  // allocate vector
  vector = (int *)malloc(sizeof(int) * vector_size);

  if (vector == NULL) {
    assert(!(vector == NULL) && "Fail to allocate memory.");
  }

  // create a sorted list
  for (int index = 0; index < vector_size; index++) {
    vector[index] = rand() % (index + 1);
  }

  // show the ordered list
  print_vector(vector, vector_size);

  // find a random number without overflow
  random_number = rand() % vector_size;

  printf("Trying to find '%d'...\n", random_number);

  // binary find an element
  finded_number = binary_search(vector, vector_size, random_number);

  printf("Number index position: %d\n", finded_number);

  return EXIT_SUCCESS;
}

void print_vector(int *vector, int size) {
  printf("[");

  for (int index = 0; index < size; index++) {
    printf(" %d", vector[index]);
  }

  printf(" ]\n");
}

int binary_search(int *vector, int size, int value) {
  int first = vector[0];
  int last = vector[size - 1];
  int middle = 0;

  while (first <= last) {
    middle = (first + last) / 2;

    if (vector[middle] == value) {
      return middle;
    } else {
      if (vector[middle] > value) {
        last = middle - 1;
      } else {
        first = middle + 1;
      }
    }
  }

  printf("'%d' not found in array.\n", value);
  return -1;
}