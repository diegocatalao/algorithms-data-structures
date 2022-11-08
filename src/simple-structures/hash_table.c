#include "./hash_table.h"

int main(int argc, char *argv) {
  Data *hash_table[MAX_TABLE_SIZE];
  int hashpos = 0;
  char hash_buffer_c[MAX_KEYWORD_INPUT];

  init_hash_table(hash_table);

  while (hash_buffer_c != "\\q") {
    scanf("%s", hash_buffer_c);
    hashpos = hashc(hash_buffer_c);
    insert_hash_table(hash_table, hashpos, hash_buffer_c);
    pretty_print_table(hash_table);
    hash_buffer_c[0] = 0;
  }

  return EXIT_SUCCESS;
}

void strswap(char *left, char *right) {
  for (int i = 0; i < MAX_KEYWORD_INPUT; i++) {
    left[i] = right[i];
  }
}

int hashc(char *keyword) {
  int buffer = 0;

  for (int i = 0; i < MAX_KEYWORD_INPUT; i++) {
    buffer += keyword[i] % 11;
  }

  return buffer % MAX_TABLE_SIZE;
}

void init_hash_table(Data **hash_table) {
  for (int i = 0; i < MAX_TABLE_SIZE; i++) {
    hash_table[i] = malloc(sizeof(Data));
    hash_table[i]->name = malloc(sizeof(char) * MAX_KEYWORD_INPUT);
    (*hash_table[i]).pNext = NULL;
  }
}

void insert_hash_table(Data **hash_table, int hash, char *name) {
  Data *hash_line = hash_table[hash];

  while (hash_line) {
    if (hash_line->name[0] == '\0') {
      strswap(hash_line->name, name);
      break;
    } else {
      hash_line->pNext = malloc(sizeof(Data));
      hash_line->pNext->name = malloc(sizeof(char) * MAX_KEYWORD_INPUT);
      strswap(hash_line->pNext->name, name);
      break;
    }

    hash_line = hash_line->pNext;
  }
}

void pretty_print_table(Data **hash_table) {
  Data *hash_line = NULL;

  for (int i = 0; i < MAX_TABLE_SIZE; i++) {
    hash_line = hash_table[i];

    printf("[%d]: ", i);

    while (hash_line) {
      if (hash_line->name[0] != '\0') {
        printf("\t| %s", hash_line->name);
      }
      hash_line = hash_line->pNext;
    }

    printf("\n");
  }
}