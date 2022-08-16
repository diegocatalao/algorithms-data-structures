#include "./hash_table.h"

int main(int argc, char *argv) {
  Data *hash_table[MAX_TABLE_SIZE];
  int hashpos = 0;
  char hash_buffer_c[MAX_KEYWORD_INPUT];

  hashpos = hashc(hash_buffer_c);

  init_hash_table(hash_table);

  while (hash_buffer_c != "\\q") {
    scanf("%s", hash_buffer_c);
    insert_hash_table(hash_table, hashpos, hash_buffer_c);
    pretty_print_table(hash_table);
    hash_buffer_c[0] = '\0';
  }

  return EXIT_SUCCESS;
}

int hashc(char *keyword) {
  int buffer = 0;
  int keyword_length = sizeof(keyword) / sizeof(keyword[0]);

  for (int i = 0; i < keyword_length; i++) {
    buffer += ((int)keyword[i]) % MAX_TABLE_SIZE;
  }

  return buffer % MAX_TABLE_SIZE;
}

void init_hash_table(Data **hash_table) {
  for (int i = 0; i < MAX_TABLE_SIZE; i++) {
    hash_table[i] = malloc(sizeof(Data));
    (*hash_table[i]).name = "\0";
    (*hash_table[i]).pNext = NULL;
  }
}

void insert_hash_table(Data **hash_table, int hash, char *name) {
  Data *new_data = malloc(sizeof(Data));
  new_data->name = name;
  new_data->pNext = NULL;

  Data *hash_line = hash_table[hash];
  while (hash_line) {
    if (hash_line->name == "\0") {
      hash_line->name = name;
      break;
    } else if (!hash_line->pNext) {
      hash_line->pNext = malloc(sizeof(Data));
      hash_line->pNext->name = name;
      hash_line->pNext->pNext = NULL;
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
      if (hash_line->name != "\0") {
        printf("\t| %s", hash_line->name);
      }
      hash_line = hash_line->pNext;
    }

    printf("\n");
  }
}