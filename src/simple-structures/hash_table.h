#ifndef _H_HASH_TABLE
#define _H_HASH_TABLE

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYWORD_INPUT 50
#define MAX_TABLE_SIZE 20

typedef struct st_Data {
  char *name;
  struct st_Data *pNext;
} Data;

/**
 * @brief Put the values of one string into another.
 *
 * @param left {char *} - destination string
 * @param right {char *} - input string
 */
void strswap(char *left, char *right);

/**
 * @brief Creates a hash (int) from the input string. For each char of the
 * string, the sum of the modules of the ascii integers is calculated and the
 * module of the sum is recalculated. (c = mod 11) % MAX_INPUT_SIZE.
 *
 * @param keyword {char *} - input string
 * @return int - returns the hash number
 */
int hashc(char *keyword);

/**
 * @brief Start hash table with a st_Data array.
 *
 * @param hash_table {Data **} - array of pointers of Data
 */
void init_hash_table(Data **hash_table);

/**
 * @brief Insert data into the hash table.
 *
 * @param hash_table {Data **} - hash table array pointer
 * @param hash {int} - calculated hash module
 * @param name {char *} - input name
 */
void insert_hash_table(Data **hash_table, int hash, char *name);

/**
 * @brief Hash Table pretty print
 *
 * @param hash_table {Data **} - hash table array pointer
 */
void pretty_print_table(Data **hash_table);

#endif