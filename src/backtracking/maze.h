#ifndef _H_MAZE
#define _H_MAZE

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define true 1
#define false 0

#define START_POINT_CHAR 'S'
#define END_POINT_CHAR 'E'
#define FREE_POINT_CHAR ' '
#define PLAYER_POINT_CHAR '$'

typedef int bool;

typedef struct {
  /* board matrix */
  char **board;
  /* number of rows */
  int rows_t;
  /* number of cols */
  int cols_t;
  /* start position */
  int start_pos[2];
  /* end position */
  int end_pos[2];
  /* filepath */
  char *filepath;
} Maze;

/**
 * @brief Allocate maze structure and gets the board information
 * from filepath.
 *
 * @param maze {Maze} - maze struct
 * @param filepath - maze file to solve
 */
void maze_init(Maze **maze, char *filepath);

/**
 * @brief Dealocate maze struct.
 *
 * @param maze {Maze} - maze struct
 */
void maze_dealoc(Maze **maze);

/**
 * @brief Solve maze with backtracking strategy.
 *
 * @param maze {Maze} - maze struct
 * @param x {int} - row position
 * @param y {int} - column position
 * @return true {bool} - returns true if gets an solution
 * @return false {bool} - returns false if not
 */
bool maze_solver(Maze **maze, int x, int y);

/**
 * @brief Board pretty print.
 *
 * @param maze {Maze} - maze struct
 */
void maze_printf(Maze **maze);

/**
 * @brief Maze general information.
 *
 * @param maze {Maze} - maze struct
 */
void maze_printf_summary(Maze **maze);

#endif