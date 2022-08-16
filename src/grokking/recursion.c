#include "recursion.h"

int factorial(int n) {
  if (n <= 1)
    return 1;
  else
    return (n * factorial(n - 1));
}

INT64 Memo_insertElement(int n, INT64 value, Memory **memo) {
  if (*memo) {
    Memo_insertElement(n, value, &((*memo)->next));
  } else {
    (*memo) = (Memory *)malloc(sizeof(Memory));
    (*memo)->n = n;
    (*memo)->value = value;
    (*memo)->next = NULL;

    return value;
  }
}

INT64 Memo_getElement(int n, Memory **memo) {
  if (*memo) {
    if ((*memo)->n == n) {
      return (*memo)->value;
    } else {
      Memo_getElement(n, &((*memo)->next));
    }
  } else {
    return -1;
  }
}

void Memo_clear(Memory **memo) {
  if ((*memo)->next) {
    Memo_clear(&((*memo)->next));
  }
  free(*memo);
  (*memo) = NULL;
}

int fibonacci(int n) {
  if (n < 2) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

INT64 memonacci(int n, Memory **memo) {
  INT64 result = 0;
  INT64 cache_value = Memo_getElement(n, memo);

  if (cache_value != -1) {
    return cache_value;
  }
  if (n <= 2) {
    return 1;
  }

  result = memonacci(n - 1, memo) + memonacci(n - 2, memo);
  return Memo_insertElement(n, result, memo);
}

int main(int argc, char *argv) {
  Memory *memory = NULL;

  printf("Factorial implementation (bad case):\n");

  // [1, 2, …, 50]
  for (int n = 1; n < 50; n += 1) {
    printf("factorial of %d: %d\n", n, factorial(n));
  }

  printf("\nFibonacci implementation (bad case):\n");

  // [1, 2, …, 45]
  for (int n = 1; n < 45; n += 1) {
    printf("fibonacci of %d: %d\n", n, fibonacci(n));
  }

  printf("\nFibonacci with memory implementation (best case):\n");

  // [10, 20, …, 90]
  for (int n = 10; n < 100; n += 10) {
    printf("fibonacci of %d: %lld\n", n, memonacci(n, &memory));
    Memo_clear(&memory);
  }

  // [ 100, 200, …, 1000 ]
  for (int n = 100; n <= 1000; n += 100) {
    printf("fibonacci of %d: %lld\n", n, memonacci(n, &memory));
    Memo_clear(&memory);
  }

  printf("\nCheck for integer overflow...\n");

  return EXIT_SUCCESS;
}