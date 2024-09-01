#include <cmath>
#include <iostream>
#include <string>

#define debug(x) cout << #x << " = " << x << endl
using namespace std;

class Solution {
public:
  string nearestPalindromic(string n) {
    string result = "";
    // find the nearest with n
    string answer1 = getPalindronmic(n);
    if (answer1 != n)
      result = answer1;

    long long convertedNum = stoll(n);

    long long power10HalfSize = pow(10LL, n.size() / 2);

    // find the nearest palindromic with +1 left haft
    long long addedNum = convertedNum + power10HalfSize;
    string answer2 = getPalindronmic(to_string(addedNum));
    if (isHalfNine(n))
      answer2 = getPalindronmicHalfPowOfTen(n.size() + 1);
    if (result == "" ||
        abs(stoll(answer2) - convertedNum) < abs(stoll(result) - convertedNum))
      result = answer2;

    // find the nearest palindromic -1 left haft
    long long subtractedNum = convertedNum - power10HalfSize;
    string answer3 = getPalindronmic(to_string(subtractedNum));
    if (isHalfPowOfTen(n))
      answer3 = getPalindronmicHalfNine(n.size() - 1);

    if (abs(stoll(answer3) - convertedNum) <=
        abs(stoll(result) - convertedNum)) {
      result = answer3;
    }
    return result;
  }

private:
  string getPalindronmic(string n) {
    int startRightHalfIndex = n.size() / 2;
    int currentLeftHalfIndex =
        (n.size() % 2 == 0) ? startRightHalfIndex - 1 : startRightHalfIndex;

    for (int i = startRightHalfIndex; i < n.size() && currentLeftHalfIndex >= 0;
         ++i, --currentLeftHalfIndex) {
      n[i] = n[currentLeftHalfIndex];
    }
    return n;
  }

  string getPalindronmicHalfPowOfTen(int length) {
    string result = "1";
    for (int i = 0; i < length - 2; ++i)
      result.push_back('0');
    result.push_back('1');
    return result;
  }

  string getPalindronmicHalfNine(int length) {
    string result = "";
    for (int i = 0; i < length; ++i)
      result.push_back('9');
    return result;
  }

  // check number is 1000xxxx
  bool isHalfPowOfTen(string n) {
    bool result = (n[0] == '1') && (n.size() > 1);
    for (int i = 1; result && i < (n.size() + 1) / 2; ++i) {
      result = result && (n[i] == '0');
    }
    return result;
  }

  bool isHalfNine(string n) {
    bool result = true;
    for (int i = 0; result && i < (n.size() + 1) / 2; ++i) {
      result = result && (n[i] == '9');
    }
    return result;
  }
};

// 0 1 2 3 4 5 => size/2
// 0 1 2 3 4 => (size) /2

void expect(string testDescription, string input, string expected) {
  Solution s;

  string answer = s.nearestPalindromic(input);
  if (answer == expected) {
    cout << "\033[1m" << "\033[32m" << "PASS: " << testDescription << "\033[0m"
         << "\033[0m" << endl;
  } else {
    cout << "\033[1m" << "\033[31m" << "FAIL: " << testDescription << "\033[0m"
         << "\033[0m" << endl;
    cout << "input: " << input << endl;
    cout << "answer: " << answer << endl;
    cout << "expected: " << expected << endl;
  }
  cout << "-------------------------" << endl;
}

int main() {
  expect("Test 1", "1234", "1221");
  expect("Test 2", "999", "1001");
  expect("Test 3", "1001", "999");
  expect("Test 4", "12932", "12921");
  expect("Test 5", "99800", "99799");
  expect("Test 6", "12120", "12121");
  expect("Test 7", "1", "0");
  expect("Test 8", "9", "8");
  expect("Test 9", "10", "9");
  expect("Test 10", "19991", "20002");
  expect("Test 11", "799999999999999997", "800000000000000008");
  return 0;
}
