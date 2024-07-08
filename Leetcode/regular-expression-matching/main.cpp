#include <assert.h>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    // cout << s << " " << p << endl;

    if (dp.count({s, p}))
      return dp[{s, p}];

    if (p.size() == 0) {
      // cout << "LL " << s.size() << endl;
      return (s.size() == 0);
    }

    bool ans = false;
    if (p[0] == '.') {
      if (p.size() > 1 && p[1] == '*') {
        for (int i = 0; i < s.size(); ++i) {
          ans = isMatch(s.substr(i, s.size() - i), p.substr(2, p.size() - 2));
          if (ans)
            break;
        }
        if (!ans) {
          string empty = "";
          ans = isMatch(empty, p.substr(2, p.size() - 2));
        }
      } else {
        ans = s.size() > 0 &&
              isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
      }
    } else {
      if (s.size() > 0 && s[0] == p[0]) {
        if (p.size() > 1 && p[1] == '*') {
          ans = isMatch(s, p.substr(2, p.size() - 2));
          for (int i = 0; i + 1 <= s.size() && s[i] == p[0] && !ans; ++i)
            ans = isMatch(s.substr(i + 1, s.size() - i - 1),
                          p.substr(2, p.size() - 2));
        } else {
          ans = isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
        }
      } else {
        ans = p.size() > 1 && p[1] == '*' &&
              isMatch(s, p.substr(2, p.size() - 2));
      }
    }

    // cout << s << " " << p << endl;
    // cout << ans << endl;
    // cout << endl;
    dp[{s, p}] = ans;
    return ans;
  }

private:
  map<pair<string, string>, bool> dp;
};

int main() {
  string s, p;

  Solution solution;

  // // .
  // cout << "case 1" << endl;
  // s = "aab";
  // p = "a.b";
  // assert(solution.isMatch(s, p));
  //
  // // character
  // cout << "case 2" << endl;
  // s = "aab";
  // p = "aab";
  // assert(solution.isMatch(s, p));
  //
  // // character *
  // cout << "case 3" << endl;
  // s = "aab";
  // p = "a*b";
  // assert(solution.isMatch(s, p));
  //
  // cout << "case 4" << endl;
  // s = "aaaaab";
  // p = "a*ab";
  // assert(solution.isMatch(s, p));
  //
  // cout << "case 5" << endl;
  // s = "aaaaab";
  // p = "a*cb";
  // assert(!solution.isMatch(s, p));
  //
  // cout << "case 6" << endl;
  // s = "aaaaab";
  // p = "a*aaaaab";
  // assert(solution.isMatch(s, p));
  //
  // // .*
  // cout << "case 7" << endl;
  // s = "aab";
  // p = "a.*";
  // assert(solution.isMatch(s, p));
  //
  // // Misc
  // cout << "case 8" << endl;
  // s = "aabcccccd";
  // p = "a.*c*d";
  // assert(solution.isMatch(s, p));
  //
  // cout << "case 9" << endl;
  // s = "aabcccccd";
  // p = "a.*d";
  // assert(solution.isMatch(s, p));
  //
  // cout << "case 10" << endl;
  // s = "aabcccccd";
  // p = "a*c";
  // assert(!solution.isMatch(s, p));
  //
  // cout << "case 11" << endl;
  // s = "aa";
  // p = "a*";
  // assert(solution.isMatch(s, p));
  //
  // cout << "case 12" << endl;
  // s = "aab";
  // p = "c*a*b";
  // assert(solution.isMatch(s, p));
  //
  // cout << "case 13" << endl;
  // s = "mississippi";
  // p = "mis*is*p*.";
  // assert(!solution.isMatch(s, p));
  //
  // cout << "case 14" << endl;
  // s = "bbab";
  // p = "b*a*";
  // assert(!solution.isMatch(s, p));

  cout << "case 15" << endl;
  s = "b";
  p = "b.*c";
  assert(!solution.isMatch(s, p));

  return 0;
}
