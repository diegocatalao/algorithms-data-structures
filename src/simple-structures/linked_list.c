#include "linked_list.h"

int main(int argc, char *argv) {
  Vector *vector = NULL;

  init_Vector(&vector);
  push_Vector(&vector, 10);
  push_Vector(&vector, 20);
  push_Vector(&vector, 30);

  pretty_print_Vector(&vector);

  remove_Vector(&vector, 40);

  pretty_print_Vector(&vector);

  return EXIT_SUCCESS;
}

void init_Vector(Vector **vector) {
  if (*vector != NULL) {
    fprintf(stderr, "Unable to reallocate an already allocated list.");
    exit(0);
  }

  (*vector) = (Vector *)malloc(sizeof(Vector));

  if (*vector == NULL) {
    fprintf(stderr, "Unable to alloc vector memory.");
    exit(0);
  }

  (*vector)->length = 0;
  (*vector)->pFirstNode = NULL;
  (*vector)->pCurrentNode = (*vector)->pFirstNode;
}

void push_Vector(Vector **vector, int value) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->pNext = NULL;
  new_node->value = value;

  if ((*vector)->pFirstNode == NULL) {
    (*vector)->pFirstNode = new_node;
    (*vector)->pCurrentNode = (*vector)->pFirstNode;
  } else {
    (*vector)->pCurrentNode = (*vector)->pFirstNode;
    while ((*vector)->pCurrentNode->pNext != NULL) {
      (*vector)->pCurrentNode = (*vector)->pCurrentNode->pNext;
    }
    (*vector)->pCurrentNode->pNext = new_node;
  }

  (*vector)->length++;
}

int pop_Vector(Vector **vector, int index) {
  int value = INT_MIN;
  Node *nodeToDelete = NULL;

  if (index > (*vector)->length) {
    fprintf(stderr, "Index out of bounds.\n");
    return INT_MIN;
  }

  (*vector)->pCurrentNode = (*vector)->pFirstNode;

  if (index == 0) {
    (*vector)->pFirstNode = (*vector)->pFirstNode->pNext;
    nodeToDelete = (*vector)->pCurrentNode;
    (*vector)->pCurrentNode = (*vector)->pFirstNode;
  } else {
    for (int i = 0; i < index - 1; i++) {
      (*vector)->pCurrentNode = (*vector)->pCurrentNode->pNext;
    }

    nodeToDelete = (*vector)->pCurrentNode->pNext;
    (*vector)->pCurrentNode->pNext = nodeToDelete->pNext;
  }

  value = nodeToDelete->value;
  free(nodeToDelete);

  (*vector)->length--;

  return value;
}

int remove_Vector(Vector **vector, int value) {
  int index = INT_MIN;
  Node *nodeToDelete = NULL;

  (*vector)->pCurrentNode = (*vector)->pFirstNode;

  if ((*vector)->pCurrentNode->value == value) {
    nodeToDelete = (*vector)->pFirstNode;
    (*vector)->pFirstNode = nodeToDelete->pNext;
    (*vector)->pCurrentNode = (*vector)->pFirstNode;
    nodeToDelete->pNext = NULL;

    index = nodeToDelete->value;
    (*vector)->length--;

  } else {
    for (int i = 0; i < (*vector)->length; i++) {
      if ((*vector)->pCurrentNode->pNext == NULL) break;

      if (value == (*vector)->pCurrentNode->pNext->value) {
        nodeToDelete = (*vector)->pCurrentNode->pNext;
        (*vector)->pCurrentNode->pNext = nodeToDelete->pNext;
        nodeToDelete->pNext = NULL;

        index = i + 1;
        (*vector)->length--;

        break;
      }

      (*vector)->pCurrentNode = (*vector)->pCurrentNode->pNext;
    }
  }

  free(nodeToDelete);

  return index;
}

void pretty_print_Vector(Vector **vector) {
  printf("[");

  (*vector)->pCurrentNode = (*vector)->pFirstNode;

  while ((*vector)->pCurrentNode != NULL) {
    printf(" %d", (*vector)->pCurrentNode->value);
    (*vector)->pCurrentNode = (*vector)->pCurrentNode->pNext;
  }

  printf(" ]\n");
}