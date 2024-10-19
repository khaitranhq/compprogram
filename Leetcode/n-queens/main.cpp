#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
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
  vector<vector<string>> solveNQueens(int n) {
    ChessBoard initialChessBoard(n, vector<bool>(n, false));
    findSolution(State(initialChessBoard, 0, vector<bool>(n),
                       vector<bool>(2 * n), vector<bool>(2 * n)));

    return convertChessBoardToResultType();
  }

private:
  vector<ChessBoard> result;

  void findSolution(State state) {
    ChessBoard chessboard = state.chessboard;
    int currentRow = state.currentRow;
    int n = chessboard.size();

    // Anchor case
    if (currentRow >= n) {
      result.push_back(chessboard);

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

  vector<vector<string>> convertChessBoardToResultType() {
    vector<vector<string>> ans;
    for (ChessBoard chessboard : result) {
      ans.push_back(vector<string>());
      for (int i = 0; i < chessboard.size(); ++i) {
        {
          string resultRow = "";
          for (int j = 0; j < chessboard[i].size(); ++j)
            if (chessboard[i][j])
              resultRow.push_back('Q');
            else
              resultRow.push_back('.');
          ans.back().push_back(resultRow);
        }
      }
      assert(ans.back().size() == chessboard.size());
    }

    return ans;
  }
};

void expect(string test, int n, vector<vector<string>> expected) {
  Solution sol;
  vector<vector<string>> result = sol.solveNQueens(n);
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
    cout << "Result: \n";
    for (vector<string> row : result) {
      for (string cell : row)
        cout << cell << " ";
      cout << endl;
    }
    cout << "-----------------------------" << endl;
    cout << "Expected: \n";
    for (vector<string> row : expected) {
      for (string cell : row)
        cout << cell << " ";
      cout << endl;
    }
    cout << "-----------------------------" << endl;
    exit(1);
  }
}
int main() {
  // expect("Test 1", 4,
  //        {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q",
  //        ".Q.."}});

  Solution sol;
  vector<vector<string>> result = sol.solveNQueens(9);

  cout << "Result: \n";
  for (vector<string> row : result) {
    for (string cell : row)
      cout << cell << " ";
    cout << endl;
  }
  return 0;
}
