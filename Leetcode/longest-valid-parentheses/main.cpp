#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    stack<int> openParentheses;

    vector<bool> isValidPosition(s.size(), false);
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ')')
        if (openParentheses.size()) {
          isValidPosition[i] = true;
          isValidPosition[openParentheses.top()] = true;
          openParentheses.pop();
        }

      if (s[i] == '(')
        openParentheses.push(i);
    }
    isValidPosition.push_back(false);

    int maxLength = 0;
    int currentLength = 0;
    for (auto x : isValidPosition) {
      currentLength += x;
      if (!x) {
        maxLength = max(maxLength, currentLength);
        currentLength = 0;
      }
    }

    return maxLength;
  }
};

void expect(string test, string input, int expected) {
  Solution s;
  int result = s.longestValidParentheses(input);
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
  expect("Test 1", "()", 2);
  expect("Test 2", "", 0);
  expect("Test 3", ")()())", 4);
  expect("Test 4", "(()", 2);
  expect("Test 5", "()(()", 2);
  return 0;
}
