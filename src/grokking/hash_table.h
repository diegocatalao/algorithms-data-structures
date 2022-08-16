#ifndef _H_HASH_TABLE
#define _H_HASH_TABLE

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYWORD_INPUT 50
#define MAX_TABLE_SIZE 20

typedef struct st_Data {
  char *name;
  struct st_Data *pNext;
} Data;

int hashc(char *keyword);

void init_hash_table(Data **hash_table);

void insert_hash_table(Data **hash_table, int hash, char *name);

void pretty_print_table(Data **hash_table);

#endif