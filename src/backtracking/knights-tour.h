#ifndef _H_KNIGHTS_TOUR_
#define _H_KNIGHTS_TOUR_

#include <stdio.h>
#include <stdlib.h>

/* CONSTANTS */
#define true 1;
#define false 0;

/* MACROS */
#define MAX(x, y) ((x > y) ? x : y)
#define MIN(x, y) ((x < y) ? x : y)

/* TYPES */
typedef unsigned int bool;
typedef struct {
  int x;
  int y;
} PositionSafe;

/* FUNCTIONS */

bool is_solved(int **board, int board_size);

PositionSafe *is_safe(int **board, int board_size, int x, int y);

bool knights_solver(int **board, int board_size, int x, int y);

void knights_printf_board(int **board, int board_size);

#endif