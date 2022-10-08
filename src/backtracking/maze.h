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

void maze_init(Maze **maze, char *filepath);

void maze_dealoc(Maze **maze);

bool maze_solver(Maze **maze, int x, int y);

bool maze_enable_walk(Maze **maze, int x, int y);

void maze_printf(Maze **maze);

void maze_printf_summary(Maze **maze);

#endif