#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    // false => up
    // true => Cross
    bool direction = false;
    pair<int, int> currentPos = {1, 1};

    for (int i = 0; i < s.size(); ++i) {
      zigzag[currentPos.first][currentPos.second] = s[i];

      if (numRows == 1) {
        ++currentPos.first;
        continue;
      }

      if (!direction) {
        currentPos.second++;

        if (currentPos.second == numRows)
          direction = true;
      } else {
        ++currentPos.first;
        --currentPos.second;

        if (currentPos.second == 1)
          direction = false;
      }
    }

    string result = "";
    for (int j = 1; j <= numRows; ++j) {
      for (int i = 1; i <= currentPos.first; ++i) {
        if (zigzag[i][j] == '\0')
          continue;
        result.push_back(zigzag[i][j]);
      }
    }

    return result;
  }

private:
  static const int MAX_LENGTH = 1e3 + 5;
  char zigzag[MAX_LENGTH][MAX_LENGTH];
};

int main(int argc, char *argv[]) {
  string s;
  int numRows;

  cin >> s >> numRows;

  Solution solution;
  cout << solution.convert(s, numRows);
  return 0;
}
