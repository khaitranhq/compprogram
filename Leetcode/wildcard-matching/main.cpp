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
    debug(startSIndex);
    debug(startPIndex);
    // Anchor case
    if (pattern == "*")
      return true;

    if (str.size() == startSIndex && pattern.size() == startPIndex)
      return true;

    if (f.count({startSIndex, startPIndex}))
      return f[{startSIndex, startPIndex}];

    if (str.size() - 1 == startSIndex && pattern.size() - 1 == startPIndex) {
      f[{startSIndex, startPIndex}] =
          ((str[startPIndex] == pattern[startPIndex]) ||
           (pattern[startPIndex] == '?'));
      return f[{startSIndex, startPIndex}];
    }

    // Recursive case
    if (pattern[0] == '?') {
      f[{startSIndex, startPIndex}] =
          startSIndex < str.size() &&
          isMatchRecursive(startSIndex + 1, startPIndex + 1);
      return f[{startSIndex, startPIndex}];
    }

    if (pattern[0] == '*') {
      bool ans = isMatchRecursive(startSIndex, startPIndex + 1);
      for (int i = 0; i < str.size() && !ans; ++i)
        ans |= isMatchRecursive(startSIndex + i + 1, startPIndex + 1);
      f[{startSIndex, startPIndex}] = ans;
      return ans;
    }

    bool ans = (str[0] == pattern[0]);
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

  // s = "baabbabababaabbabababbaabbbbaaabaaabbbbaaaaaabbbbaaabaaabbbbbabaabbbbbbb"
  //     "babbbabbabbbbabbbbabbbbbbabababbaaaabbbbaabaaababbbabaaaabaabbbabbaabbab"
  //     "bbbabaababbbbbbbabbaaaabaaabbaaabaaaaababbbaaaabbbbbabbabb";
  // p = "ba*ba*bb*a********abaa*bb**abb**b***ab**b*b*babb***a*bb*aaabb*****b*"
  //     "aabb**aa**b*a***b*bb*b*bb*a*bbbbb**";
  // expect("Test 1", s, p, true);

  s = "aa";
  p = "a";
  expect("Test 2", s, p, false);
  return 0;
}
