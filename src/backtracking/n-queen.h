#ifndef _H_N_QUEEN_
#define _H_N_QUEEN_

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1;
#define false 0;

#define MAX(x, y) ((x > y) ? x : y)
#define MIN(x, y) ((x < y) ? x : y)

typedef unsigned int bool;

bool has_collision(int **board, int board_size, int x, int y);

bool solve_queen(int **board, int board_size, int column);

void printf_board(int **board, int board_size);

#endif