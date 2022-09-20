#include "./n-queen.h"

int main(void) {
  int **board;
  int board_size = 0;

  printf("Insert the board size (> 0): ");
  scanf("%d", &board_size);

  if (board_size <= 0) {
    assert(!(board_size <= 0) && "Invalid board size!");
  }

  board = (int **)malloc(sizeof(int *) * board_size);
  for (int irow = 0; irow < board_size; irow++) {
	board[irow] = (int *)malloc(sizeof(int) * board_size);
  }

  // solve_queen(board, board_size, 0);

  board[2][1] = 1;
  board[3][0] = 1;

  printf_board(board, board_size);

  printf("%d\n", has_collision(board, board_size, 2, 1));
  printf("%d\n", has_collision(board, board_size, 3, 0));

  return EXIT_SUCCESS;
}

bool has_collision(int **board, int board_size, int x, int y) {
  int wally = 0;
  int wallx = 0;
  // detect collision same column
  for (int xpos = 0; xpos < board_size; xpos++) {
    if (board[xpos][y] == 1 && xpos != x) return true;
  }
  // detect collision same row
  for (int ypos = 0; ypos < board_size; ypos++) {
    if (board[x][ypos] == 1 && ypos != y) return true;
  }
  // detect collision diagonal left
  wallx = x >= y ? x - y : 0;
  wally = x >= y ? 0 : y - x;
  for (wallx; wallx < board_size; wallx++, wally++) {
    if (board[wallx][wally] == 1 && wallx != x && wally != y) return true;
    if (wally > board_size) break;
  }
  // detect collision diagonal right
  wally = MIN(x + y, board_size - 1);
  wallx = MIN(x + y, board_size - 1);
  for (wally; wally < 0; wally--) {
    if (board[wally][wally] == 1 && wally != x)
      if (wally < 0) break;
    printf("%d, %d\n", wallx, wally);
  }
  return false;
}

bool solve_queen(int **board, int board_size, int column) {
  if (column >= board_size) {
    return true;
  }

  for (int i = 0; i < board_size; i++) {
    printf_board(board, board_size);
    printf("\n");
    if (!has_collision(board, board_size, i, column)) {
      board[i][column] = 1;

      if (solve_queen(board, board_size, column + 1)) {
        return true;
      }

      board[i][column] = 0;
    }
  }

  return false;
}

void printf_board(int **board, int board_size) {
  for (int irow = 0; irow < board_size; irow++) {
    for (int icol = 0; icol < board_size; icol++) {
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
