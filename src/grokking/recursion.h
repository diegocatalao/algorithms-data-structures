#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int INT64;

/**
 * @brief Linked list memory to store values of fibonacci memory.
 */
typedef struct sMemory {
  // index of fibonacci value
  int n;
  // fibonacci number of n
  INT64 value;
  // next element in linked list
  struct sMemory *next;
} Memory;

/**
 * @brief Insert a memorized element in memo linked list.
 *
 * @param n {int} - index of fibonacci value
 * @param value {INT64} - value of fibonacci calc
 * @param memo {**Memory} - pointer to pointer of memory list
 * @return INT64 - value of fibonacci calc
 */
INT64 Memo_insertElement(int n, INT64 value, Memory **memo);

/**
 * @brief Search a element inside of memo linked list.
 *
 * @param n {int} - index of fibonacci value
 * @param memo {**Memory} - pointer to pointer of memory list
 * @return INT64 - value of fibonacci calc
 */
INT64 Memo_getElement(int n, Memory **memo);

/**
 * @brief Clear the fibonacci memory.
 *
 * @param memo {**Memory} - pointer to pointer of memory list
 */
void Memo_clear(Memory **memo);

/**
 * @brief Calculate the value of a factorial number given a N. this is the worst
 * case.
 *
 * @param n {int} - number to calc a factorial
 * @return int - fatorial number
 */
int factorial(int n);

/**
 * @brief Calculates the fibonacci number for a given N. This is the worst case
 *
 * @param n {int} - number to calc a fibonacci
 * @return int - fibonacci number
 */
int fibonacci(int n);

/**
 * @brief Calculates the fibonacci number for a given N. This is the best case
 *
 * @param n {int} - number to calc a fibonacci
 * @param memo {**Memory} - fibonacci memory
 * @return INT64 - fibonacci number
 */
INT64 memonacci(int n, Memory **memo);