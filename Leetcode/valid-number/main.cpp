#include <iostream>
#include <regex>
#include <string>
using namespace std;

class Solution {
public:
  bool isNumber(string s) {
    return regex_match(s, regex("[-+]?((\\d+)|(\\d+\\.)|(\\.\\d+)|(\\d+\\.\\d+))([eE][-+]?\\d+)?"));
  }
};

void expect(string test, string s, bool expected) {
  Solution sol;
  bool result = sol.isNumber(s);
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
    cout << "result: " << result << endl;
    cout << "-----------------------------" << endl;
    cout << "expected: " << expected << endl;
    cout << "-----------------------------" << endl;
    exit(1);
  }
}

int main() {
  expect("Test 1", "5", true);
  expect("Test 2", "+2", true);
  expect("Test 3", "00382", true);
  expect("Test 4", "-532", true);
  expect("Test 5", "-532e3", true);
  expect("Test 6", "-90E3", true);
  expect("Test 7", "95a54e53", false);
  expect("Test 8", "abc", false);
  expect("Test 9", "1a", false);
  expect("Test 10", "1e", false);
  expect("Test 11", "e3", false);
  expect("Test 12", "--6", false);
  expect("Test 13", "-+6", false);

  expect("Test 14", ".", false);

  expect("Test 15", "-.9", true);
  expect("Test 16", ".9", true);
  expect("Test 16", "-5.", true);
  expect("Test 16", "+5.", true);
  expect("Test 17", "5.", true);
  expect("Test 18", "-5.93", true);
  expect("Test 19", "-5.93e5", true);
  expect("Test 20", "46.e3", true);
  expect("Test 21", "46e-3", true);
  return 0;
}
