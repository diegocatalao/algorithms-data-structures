#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Linked list base node. It is used to store values.
 */
typedef struct sNode {
  // linked list value
  int value;

  // next node
  struct sNode *pNext;
} Node;

/**
 * @brief Vector with first and current elements of linked list. Used for linked
 * list manipulation.
 */
typedef struct sVector {
  // size of storage linked list
  int length;

  // first node of linked list
  Node *pFirstNode;

  // current node of linked list
  Node *pCurrentNode;
} Vector;

/**
 * @brief Start linked list pointer and first value.
 *
 * @param vector {**Vector} pointer of pointer of a vector
 */
void init_Vector(Vector **vector);

/**
 * @brief Push a value on topo of linked list.
 *
 * @param vector {**Vector} pointer of pointer of a vector
 * @param value {int} value of node
 */
void push_Vector(Vector **vector, int value);

/**
 * @brief Remove some element based on index.
 *
 * @param vector {**Vector} pointer of pointer of a vector
 * @param value {int} index of node
 */
int pop_Vector(Vector **vector, int index);

/**
 * @brief Remove some element based on value.
 *
 * @param vector {**Vector} pointer of pointer of a vector
 * @param value {int} index of node
 * @return int
 */
int remove_Vector(Vector **vector, int value);

/**
 * @brief Formatted print of a list.
 *
 * @param vector {**Vector} pointer of pointer of a vector
 */
void pretty_print_Vector(Vector **vector);