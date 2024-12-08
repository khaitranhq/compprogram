#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> SubStringIndex; // first: left, second: right

class AdvanceString {
private:
  string s;
  vector<vector<int>> numberOfChars; // Using array of size 128 for ASCII chars

public:
  AdvanceString(string s) {
    this->s = s;

    for (int i = 0; i < s.size(); i++) {
      if (i == 0)
        numberOfChars.push_back(vector<int>(128, 0));
      else {
        numberOfChars.push_back(numberOfChars[i - 1]);
      }

      numberOfChars[i][s[i]]++;
    }
  }

  vector<int> getNumberOfChars(int left, int right) {
    assert(left <= right);
    vector<int> result = numberOfChars[right];
    if (left > 0) {
      for (int i = 0; i < 128; i++) {
        result[i] -= numberOfChars[left - 1][i];
      }
    }
    return result;
  }
};

class Solution {
public:
  string minWindow(string s, string t) {
    // cout << "s: " << s << " t: " << t << endl;
    // cout << "s size: " << s.size() << " t size: " << t.size() << endl;
    // cout << "-----------------------------" << endl;
    vector<SubStringIndex> poentialResult;
    AdvanceString advanceStringT(t);
    AdvanceString advanceStringS(s);

    int leftPoint = 0, rightPoint = 0;
    vector<int> numberOfCharsT =
        advanceStringT.getNumberOfChars(0, t.size() - 1);
    while (rightPoint < s.size()) {
      // cout << "leftPoint: " << leftPoint << " rightPoint: " << rightPoint
      //      << endl;

      vector<int> numberOfChars =
          advanceStringS.getNumberOfChars(leftPoint, rightPoint);

      bool isEnough = checkEnough(numberOfChars, numberOfCharsT);
      if (isEnough) {
        while (leftPoint < rightPoint &&
               checkEnough(
                   advanceStringS.getNumberOfChars(leftPoint + 1, rightPoint),
                   numberOfCharsT)) {
          ++leftPoint;
        }
        poentialResult.push_back({leftPoint, rightPoint});
      }

      ++rightPoint;
      // cout << "-----------------------------" << endl;
    }

    sort(poentialResult.begin(), poentialResult.end(),
         [](SubStringIndex a, SubStringIndex b) {
           return a.second - a.first < b.second - b.first;
         });

    if (poentialResult.size() == 0) {
      return "";
    }

    string result =
        s.substr(poentialResult[0].first,
                 poentialResult[0].second - poentialResult[0].first + 1);
    return result;
  }

private:
  bool checkEnough(vector<int> numberOfChars, vector<int> numberOfCharsT) {
    for (int i = 0; i < 128; i++) {
      if (numberOfChars[i] < numberOfCharsT[i]) {
        return false;
      }
    }
    return true;
  }
};

void expect(string test, string s, string t, string expectedOutput) {
  Solution solution;
  string output = solution.minWindow(s, t);
  if (output == expectedOutput) {
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

    cout << "Result: " << output << endl;

    cout << "Expected: " << expectedOutput << endl;
    exit(1);
  }
}

int main() {
  expect("Test 1", "ADOBECODEBANC", "ABC", "BANC");
  expect("Test 2", "a", "a", "a");
  expect("Test 3", "a", "aa", "");

  return 0;
}
