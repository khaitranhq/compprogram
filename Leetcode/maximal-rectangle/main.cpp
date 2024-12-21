#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

const int LOG_LEVEL = 0; // 0: for submit, 1: for debug

void log(string message) {
  if (LOG_LEVEL == 1) {
    cout << message << endl;
  }
}
class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0) {
      return 0;
    }

    int maxArea = 0;
    vector<int> heights(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == '1') {
          heights[j] += 1;
        } else {
          heights[j] = 0;
        }
      }

      maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
  }

private:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= heights.size(); ++i) {
      int currentHeight = i == heights.size() ? 0 : heights[i];

      while (!st.empty() && currentHeight < heights[st.top()]) {
        int height = heights[st.top()];
        st.pop();
        int width = st.empty() ? i : i - st.top() - 1;
        maxArea = max(maxArea, height * width);
      }

      st.push(i);
    }
    return maxArea;
  }
};

void expect(string testCase, vector<vector<char>> input, int expected) {
  Solution s;
  int result = s.maximalRectangle(input);

  if (result == expected) {
    cout << "\033[1m"
         << "\033[32m"
         << "PASS: " << testCase << "\033[0m"
         << "\033[0m" << endl;
  } else {
    cout << "\033[1m"
         << "\033[31m"
         << "FAIL: " << testCase << "\033[0m"
         << "\033[0m" << endl;
    cout << "-----------------------------" << endl;

    cout << "Result: " << result << endl;

    cout << "Expected: " << expected << endl;
    exit(1);
  }
}

int main() {
  expect("Test Case 1",
         {{'1', '0', '1', '0', '0'},
          {'1', '0', '1', '1', '1'},
          {'1', '1', '1', '1', '1'},
          {'1', '0', '0', '1', '0'}},
         6);

  expect("Test Case 2", {{'0'}}, 0);

  expect("Test Case 3", {{'1'}}, 1);
  return 0;
}
