#include "knights-tour.h"

int main(int argc, char **argv) {
  int **board = NULL;
  int board_size = 0;
  int row, column;

  printf("Input the board size: ");
  scanf("%d", &board_size);

  board = (int **)malloc(sizeof(int *) * board_size);
  for (row = 0; row < board_size; row++) {
    board[row] = (int *)malloc(sizeof(int) * board_size);

    for (column = 0; column < board_size; column++) {
      board[row][column] = 0;
    }
  }

  knights_solver(board, board_size, 0, 0);

  knights_printf_board(board, board_size);

  return EXIT_SUCCESS;
}

bool is_solved(int **board, int board_size) {
  int sum = 0;

  for (int row = 0; row < board_size; row++) {
    for (int col = 0; col < board_size; col++) {
      sum += board[row][col];
    }
  }

  return sum == board_size * board_size;
}

bool knights_solver(int **board, int board_size, int x, int y) {
  if (is_solved(board, board_size)) {
    return true;
  }

  return false;
}

void knights_printf_board(int **board, int board_size) {
  for (int row = 0; row < board_size; row++) {
    for (int column = 0; column < board_size; column++) {
      if (board[row][column] == -1) {
        printf("♘ ");
      } else {
        printf("%d ", board[row][column]);
      }
    }

    printf("\n");
  }
}