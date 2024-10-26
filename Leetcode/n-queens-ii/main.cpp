#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<bool>> ChessBoard;

struct State {
  ChessBoard chessboard;
  int currentRow;

  vector<bool> hasQueenInColumn;
  vector<bool> hasQueenInDiagonal;        // from {0, 0} to {n - 1, n - 1}
  vector<bool> hasQueenInReverseDiagonal; // from {0, n - 1} to {n - 1, 0}

  State() {}

  State(ChessBoard chessboard, int currenRow, vector<bool> hasQueenInColumn,
        vector<bool> hasQueenInDiagonal, vector<bool> hasQueenInReverseDiagonal)
      : chessboard(chessboard), currentRow(currenRow),
        hasQueenInColumn(hasQueenInColumn),
        hasQueenInDiagonal(hasQueenInDiagonal),
        hasQueenInReverseDiagonal(hasQueenInReverseDiagonal) {}
};

class Solution {
public:
  int totalNQueens(int n) {
    numberOfResult = 0;
    ChessBoard initialChessBoard(n, vector<bool>(n, false));
    findSolution(State(initialChessBoard, 0, vector<bool>(n),
                       vector<bool>(2 * n), vector<bool>(2 * n)));

    return numberOfResult;
  }

private:
  int numberOfResult;

  void findSolution(State state) {
    ChessBoard chessboard = state.chessboard;
    int currentRow = state.currentRow;
    int n = chessboard.size();

    // Anchor case
    if (currentRow >= n) {
      ++numberOfResult;
      return;
    }

    for (int column = 0; column < n; ++column) {
      if (!state.hasQueenInColumn[column] &&
          !state.hasQueenInDiagonal[currentRow - column + n - 1] &&
          !state.hasQueenInReverseDiagonal[currentRow + column]) {
        state.chessboard[currentRow][column] = true;
        ++state.currentRow;
        state.hasQueenInColumn[column] =
            state.hasQueenInDiagonal[currentRow - column + n - 1] =
                state.hasQueenInReverseDiagonal[currentRow + column] = true;

        findSolution(state);

        state.chessboard[currentRow][column] = false;
        --state.currentRow;
        state.hasQueenInColumn[column] =
            state.hasQueenInDiagonal[currentRow - column + n - 1] =
                state.hasQueenInReverseDiagonal[currentRow + column] = false;
      }
    }
  }
};

void expect(string test, int n, int expected) {
  Solution sol;
  int result = sol.totalNQueens(n);
  if (result == expected) {
    cout << "\033[1m"
         << "\033[32m"
         << "PASS: " << test << "\033[0m"
         << "\033[0m" << endl;
  } else {
    cout << "\033[1m"
         << "\033[31m"
         << "FAIL: " << test << "\033[0m"
         << "\033[0m" << endl;
    cout << "-----------------------------" << endl;
    cout << "Result: " << result << endl;
    ;
    cout << "-----------------------------" << endl;
    cout << "Expected: " << expected << endl;
    cout << "-----------------------------" << endl;
    exit(1);
  }
}

int main() {
  expect("Test 1", 4, 2);
  expect("Test 2", 1, 1);
  return 0;
}
