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

/**
 * @brief Detect collision diagonally left up and left down
 *
 * @param board {vector} - board matrix (multidimentional array)
 * @param size_b {int} - board size
 * @param x {int} - row position
 * @param y {int} - column position
 * @return {bool} - true if has collision and false if not
 */
bool has_collision(int **board, int size_b, int x, int y);

/**
 * @brief
 *
 * @param board {vector} - board matrix (multidimentional array)
 * @param size_b {int} - board size
 * @param column {int} - column number
 * @return {bool} - true if is a valid board and false if not
 */
bool solve_queen(int **board, int size_b, int column);

/**
 * @brief Board pretty print
 *
 * @param board {vector} - board matrix (multidimentional array)
 * @param size_b {int} - board size
 */
void printf_board(int **board, int size_b);

#endif