class Solution {
public:
  bool isMatch(string s, string p) {
      // Anchor case
    if (mp.count({s, p}))
      return mp[{s, p}];

    if (p == "*")
      return true;

    if (s.size() == 0 && p.size() == 0)
      return true;

    if (s.size() == 1 && p.size() == 1) {
      mp[{s, p}] = ((s[0] == p[0]) || (p[0] == '?'));
      return mp[{s, p}];
    }

    // Recursive case
    if (p[0] == '?') {
      mp[{s, p}] = s.size() > 0 && isMatch(s.substr(1), p.substr(1));
      return mp[{s, p}];
    }

    if (p[0] == '*') {
      bool ans = isMatch(s, p.substr(1));
      for (int i = 0; i < s.size(); ++i)
        ans |= isMatch(s.substr(i + 1), p.substr(1));
      mp[{s, p}] = ans;
      return ans;
    }

    bool ans = (s[0] == p[0]);
    if (!ans) {
      mp[{s, p}] = false;
      return false;
    }

    ans &= isMatch(s.substr(1), p.substr(1));
    mp[{s, p}] = ans;
    return ans;

  }

private:
  map<pair<string, string>, bool> mp;
};
