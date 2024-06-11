#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    cout << s << " " << p << endl;
    cout << s.size() << " " << p.size() << endl;
    if (p.size() == 0 || s.size() == 0)
      return s.size() == 0 && p.size() == 0;

    // if (p[0] == '.' && p[1] == '*' && p.size() == 2)
    //   return true;
    //
    if (f.count({s, p}))
      return f[{s, p}];

    if (s[0] != p[0] && p[0] != '.' && p[1] != '*') {
      f[{s, p}] = false;
      return false;
    }

    bool ans = false;
    if (p.size() > 1 && p[1] == '*') {
      ans |= isMatch(s, p.substr(2));
      for (int i = 0; ( p[0] == '.' || (i < s.size() && s[i] == s[0]) ); ++i) {
        ans |= isMatch(s.substr(i + 1), p.substr(2));

        if (ans)
          break;
      }
    } else
      ans |= isMatch(s.substr(1), p.substr(1));

    f[{s, p}] = ans;
    return ans;
  }

private:
  map<pair<string, string>, bool> f;
};

int main() {
  freopen("test/4.inp", "r", stdin);
  string s, p;
  cin >> s >> p;

  Solution solution;
  if (solution.isMatch(s, p))
    cout << "true";
  else
    cout << "false";
  return 0;
}
