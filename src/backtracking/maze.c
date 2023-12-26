#include "./maze.h"

int main(int argc, char **argv) {
  Maze *maze = NULL;

  if (argc == 1) assert(!(argc == 1) && "Error: need maze filename.");

  maze_init(&maze, argv[1]);

  maze_solver(&maze, maze->start_pos[0], maze->start_pos[1]);

  maze_printf(&maze);

  maze_printf_summary(&maze);

  maze_dealoc(&maze);

  return 0;
}

void maze_init(Maze **maze, char *filepath) {
  int filepath_t = strlen(filepath);
  char buffer;
  FILE *fptr = fopen(filepath, "r");

  if (fptr == NULL) assert((fptr == NULL) && "Error: file not found.");

  /* maze allocation */
  (*maze) = (Maze *)malloc(sizeof(Maze *));
  (*maze)->rows_t = 0;
  (*maze)->cols_t = 0;

  (*maze)->filepath = malloc(strlen(filepath) + 1);
  strcpy((*maze)->filepath, filepath);

  /* count number of rows and number of columns */
  for (buffer = buffer; buffer != EOF; buffer = getc(fptr)) {
    if (buffer == '\n') (*maze)->rows_t++;
    if ((*maze)->rows_t == 0) (*maze)->cols_t++;
  }

  /* create board dynamically */
  (*maze)->board = (char **)malloc(sizeof(char *) * (*maze)->rows_t);
  for (int row = 0; row < (*maze)->rows_t; row++)
    (*maze)->board[row] = (char *)malloc(sizeof(char) * (*maze)->cols_t);

  /* go back to begin */
  fseek(fptr, 0, SEEK_SET);

  /* populate with file content */
  for (int row = 0; row < (*maze)->rows_t; row++) {
    for (int col = 0; col < (*maze)->cols_t; col++) {
      buffer = getc(fptr);

      switch (buffer) {
        case START_POINT_CHAR:
          (*maze)->start_pos[0] = row;
          (*maze)->start_pos[1] = col;
          break;
        case END_POINT_CHAR:
          (*maze)->end_pos[0] = row;
          (*maze)->end_pos[1] = col;
          break;
        case '\n':
          continue;
          break;
      }

      (*maze)->board[row][col] = buffer;
    }
  }

  fclose(fptr);
}

void maze_dealoc(Maze **maze) {
  if (maze == NULL) assert((maze == NULL) && "Error: maze are NULL pointer");

  free((*maze));
}

bool maze_solver(Maze **maze, int x, int y) {
  if (x < 0 || y < 0 || x > (*maze)->rows_t || y > (*maze)->cols_t)
    return false;

  if ((*maze)->board[x][y] == END_POINT_CHAR) return true;

  if (x - 1 > 0 && x + 1 < (*maze)->rows_t && y - 1 > 0 &&
      y + 1 < (*maze)->cols_t) {
    if ((*maze)->board[x - 1][y] == END_POINT_CHAR) return true;
    if ((*maze)->board[x][y - 1] == END_POINT_CHAR) return true;
    if ((*maze)->board[x][y + 1] == END_POINT_CHAR) return true;
    if ((*maze)->board[x + 1][y] == END_POINT_CHAR) return true;
  }

  // check right
  if ((*maze)->board[x][y + 1] == FREE_POINT_CHAR) {
    (*maze)->board[x][y + 1] = PLAYER_POINT_CHAR;
    if (!maze_solver(maze, x, y + 1)) {
      (*maze)->board[x][y + 1] = FREE_POINT_CHAR;
    } else {
      return true;
    }
  }
  // check down
  if ((*maze)->board[x + 1][y] == FREE_POINT_CHAR) {
    (*maze)->board[x + 1][y] = PLAYER_POINT_CHAR;
    if (!maze_solver(maze, x + 1, y)) {
      (*maze)->board[x + 1][y] = FREE_POINT_CHAR;
    } else {
      return true;
    }
  }
  // check left
  if ((*maze)->board[x][y - 1] == FREE_POINT_CHAR) {
    (*maze)->board[x][y - 1] = PLAYER_POINT_CHAR;
    if (!maze_solver(maze, x, y - 1)) {
      (*maze)->board[x][y - 1] = FREE_POINT_CHAR;
    } else {
      return true;
    }
  }

  // check top
  if ((*maze)->board[x - 1][y] == FREE_POINT_CHAR) {
    (*maze)->board[x - 1][y] = PLAYER_POINT_CHAR;
    if (!maze_solver(maze, x - 1, y)) {
      (*maze)->board[x - 1][y] = FREE_POINT_CHAR;
    } else {
      return true;
    }
  }

  return false;
}

void maze_printf(Maze **maze) {
  for (int row = 0; row < (*maze)->rows_t; row++) {
    printf("%s\n", (*maze)->board[row]);
  }
}

void maze_printf_summary(Maze **maze) {
  printf("----------------------------------------------------------\n");
  printf("SUMMARY:\n");
  printf("BOARD POINTER: %p\n", (*maze)->board);
  printf("BOARD ROWS QUANTITY: %d\n", (*maze)->rows_t);
  printf("BOARD COLS QUANTITY: %d\n", (*maze)->cols_t);
  printf("BOARD START POS: (%d, %d)\n", (*maze)->start_pos[0],
         (*maze)->start_pos[1]);
  printf("BOARD END POS: (%d, %d)\n", (*maze)->end_pos[0], (*maze)->end_pos[1]);
  printf("BOARD FILE PATH: %s\n", (char *)&((*maze)->filepath));
  printf("----------------------------------------------------------\n");
}