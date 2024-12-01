#include <iostream>
#include <string>
using namespace std;

const int LOG_LEVEL = 0; // 0: for submit, 1: for debug

void log(string message) {
  if (LOG_LEVEL == 1) {
    cout << message << endl;
  }
}

void expect(string testCase, int input, int expected) {
  // TODO: change this
  int result = input;

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

int main() { return 0; }
