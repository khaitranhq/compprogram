#include <cstring>
#include <iostream>
#include <map>

#define debug(x) cout << #x << "=" << x << endl
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    str = s;
    pattern = p;
    return isMatchRecursive(0, 0);
  }

private:
  const static int MAX = 2005;
  string str, pattern;
  map<pair<int, int>, int> f;

  bool isMatchRecursive(int startSIndex, int startPIndex) {
    // Anchor case
    if (pattern == "*")
      return true;

    if (pattern.size() == startPIndex)
      return str.size() == startSIndex;

    if (f.count({startSIndex, startPIndex}))
      return f[{startSIndex, startPIndex}];

    // Recursive case
    if (pattern[startPIndex] == '?') {
      f[{startSIndex, startPIndex}] =
          startSIndex < str.size() &&
          isMatchRecursive(startSIndex + 1, startPIndex + 1);
      return f[{startSIndex, startPIndex}];
    }

    if (pattern[startPIndex] == '*') {
      bool ans = isMatchRecursive(startSIndex, startPIndex + 1);
      for (int i = startSIndex; i < str.size() && !ans; ++i)
        ans |= isMatchRecursive(i + 1, startPIndex + 1);
      f[{startSIndex, startPIndex}] = ans;
      return ans;
    }

    bool ans = (str[startSIndex] == pattern[startPIndex]);
    if (!ans) {
      f[{startSIndex, startPIndex}] = false;
      return false;
    }

    ans &= isMatchRecursive(startSIndex + 1, startPIndex + 1);
    f[{startSIndex, startPIndex}] = ans;
    return ans;
  }
};

void expect(string test, string s, string p, bool expected) {
  Solution sol;
  bool result = sol.isMatch(s, p);
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

int main(int argc, char *argv[]) {
  string s, p;

  s =
  "baabbabababaabbabababbaabbbbaaabaaabbbbaaaaaabbbbaaabaaabbbbbabaabbbbbbb"
      "babbbabbabbbbabbbbabbbbbbabababbaaaabbbbaabaaababbbabaaaabaabbbabbaabbab"
      "bbbabaababbbbbbbabbaaaabaaabbaaabaaaaababbbaaaabbbbbabbabb";
  p = "ba*ba*bb*a********abaa*bb**abb**b***ab**b*b*babb***a*bb*aaabb*****b*"
      "aabb**aa**b*a***b*bb*b*bb*a*bbbbb**";
  expect("Test 1", s, p, true);

  s = "aa";
  p = "a";
  expect("Test 2", s, p, false);

  s = "aa";
  p = "*";
  expect("Test 3", s, p, true);

  s = "cb";
  p = "?a";
  expect("Test 4", s, p, false);

  s = "adceb";
  p = "*a*b";
  expect("Test 5", s, p, true);

  s = "acdcb";
  p = "a*c?b";
  expect("Test 6", s, p, false);
  return 0;
}
