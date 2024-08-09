#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int numMagicSquaresInside(vector<vector<int>> &grid) {
    int ans = 0;
    for (int startRow = 0; startRow < int(grid.size()) - 2; startRow++) {
      for (int startCol = 0; startCol < int(grid[0].size()) - 2; startCol++) {
        vector<int> square;
        for (int i = 0; i < 3 && startRow + i < grid.size(); i++) {
          for (int j = 0; j < 3 && startCol + j < grid[0].size(); j++) {
            square.push_back(grid[startRow + i][startCol + j]);
          }
        }

        if (square.size() == 9 && this->isMagicSquare(square)) {
          cout << startRow << " " << startCol << endl << endl;
          ans++;
        }
      }
    }
    return ans;
  }

private:
  bool isMagicSquare(vector<int> &square) {
    int initialSize = square.size();
    square.resize(unique(square.begin(), square.end()) - square.begin());

    int sum = square[0] + square[1] + square[2];
    bool isEqualSum = (square[3] + square[4] + square[5] == sum) &&
                      (square[6] + square[7] + square[8] == sum) &&
                      (square[0] + square[3] + square[6] == sum) &&
                      (square[1] + square[4] + square[7] == sum) &&
                      (square[2] + square[5] + square[8] == sum) &&
                      (square[0] + square[4] + square[8] == sum) &&
                      (square[2] + square[4] + square[6] == sum);

    cout << square[0] + square[1] + square[2] << " "
         << square[3] + square[4] + square[5] << " "
         << square[6] + square[7] + square[8] << " "
         << square[0] + square[3] + square[6] << " "
         << square[1] + square[4] + square[7] << " "
         << square[2] + square[5] + square[8] << " "
         << square[0] + square[4] + square[8] << " "
         << square[2] + square[4] + square[6] << endl;

    return initialSize == square.size() &&
           *max_element(square.begin(), square.end()) == 9 &&
           *min_element(square.begin(), square.end()) == 1 && isEqualSum;
  }
};

void expect(string test, vector<vector<int>> input, int expected) {
  Solution s;
  int result = s.numMagicSquaresInside(input);
  if (result == expected) {
    cout << "\033[1m" << "\033[32m" << "PASS: " << test << "\033[0m"
         << "\033[0m" << endl;
  } else {
    cout << "\033[1m" << "\033[31m" << "FAIL: " << test << "\033[0m"
         << "\033[0m" << endl;
    cout << "-----------------------------" << endl;
    cout << "result: " << result << endl;
    cout << "-----------------------------" << endl;
    cout << "expected: " << expected << endl;
    cout << "-----------------------------" << endl;
    exit(1);
  }
}

int main() {
  vector<vector<int>> input;
  int output;

  input = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
  output = 1;
  expect("Test 1", input, output);

  input = {{8}};
  output = 0;
  expect("Test 2", input, output);
  return 0;
}
