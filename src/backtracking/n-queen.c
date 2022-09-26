#include "./n-queen.h"

int main(void) {
  int **board;
  int size_b = 0;

  /* request user board size */
  printf("Insert the board size (> 0): ");
  scanf("%d", &size_b);

  if (size_b <= 0) {
    assert(!(size_b <= 0) && "Invalid board size!");
  }

  /* create board dynamically */
  board = (int **)malloc(sizeof(int *) * size_b);
  for (int irow = 0; irow < size_b; irow++) {
    board[irow] = (int *)malloc(sizeof(int) * size_b);
  }

  /* show queen possibles boards */
  solve_queen(board, size_b, 0);

  return EXIT_SUCCESS;
}

bool has_collision(int **board, int size_b, int x, int y) {
  int xpos, ypos;

  // detect collision same column
  for (xpos = 0; xpos < x; xpos++) {
    if (board[xpos][y] == 1 && xpos != x) return true;
  }

  // detect collision same row
  for (ypos = 0; ypos < y; ypos++) {
    if (board[x][ypos] == 1 && ypos != y) return true;
  }

  // detect collision diagonal left up
  for (xpos = x, ypos = y; xpos >= 0 && ypos >= 0; xpos--, ypos--) {
    if (board[xpos][ypos] == 1 && xpos != x && ypos != y) return true;
  }

  // detect collision diagonal left down
  for (xpos = x, ypos = y; xpos < size_b && ypos >= 0; xpos++, ypos--) {
    if (board[xpos][ypos] == 1 && xpos != x && ypos != y) return true;
  }

  return false;
}

bool solve_queen(int **board, int size_b, int column) {
  if (column == size_b) {
    printf("-\n");
    printf_board(board, size_b);
    return true
  };

  for (int i = 0; i < size_b; i++) {
    if (!has_collision(board, size_b, i, column)) {
      board[i][column] = 1;
      solve_queen(board, size_b, column + 1);
      /* - backtracking - */
      board[i][column] = 0;
    }
  }

  return false;
}

void printf_board(int **board, int size_b) {
  for (int irow = 0; irow < size_b; irow++) {
    for (int icol = 0; icol < size_b; icol++) {
      if (board[irow][icol]) {
        printf("♛ ");
      } else {
        if ((irow + icol) % 2 == 0) {
          printf("□ ");
        } else {
          printf("■ ");
        }
      }
    }

    printf("\n");
  }
}
