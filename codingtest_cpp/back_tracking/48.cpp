#include<vector>

using namespace std;

vector<vector<int>> board;

bool is_valid(int num, int row, int col) {
  for(int i=0; i<9; i++) {
    if(board[row][i] == num || board[i][col] == num) {
      return false;
    }
  }

  int startRow = row - row % 3, startCol = col - col % 3;
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      if(board[i + startRow][j + startCol] == num) {
        return false;
      }
    }
  }
  
  return true;
}

pair<int, int> find_empty_position() {
  for(int row = 0; row<9; row++) {
    for(int col = 0; col<9; col++) {
      if(board[row][col] == 0) {
        return {row, col};
      }
    }
  }
  return {-1, -1};
}

void solve_sudoku() {
  pair<int, int> pos = find_empty_position();

  if(pos.first == -1) {
    return;
  }

  for(int num = 1; num <=9; num++) {
    if(is_valid(num, pos.first, pos.second)) {
      board[pos.first][pos.second] = num;
      solve_sudoku();
      if(find_empty_position().first == -1) {
        return;
      }
      board[pos.first][pos.second] = 0;
    }
  }
}

vector<vector<int>> solution(vector<vector<int>> input_board) {
  board = input_board;
  solve_sudoku();
  return board;
}