#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int _ = 0; _ < n; ++_) {                                              \
      for (int __ = 0; __ < m; ++__)                                           \
        cout << x[_][__] << " ";                                               \
      cout << endl;                                                            \
    }                                                                          \
    cout << endl;                                                              \
  }
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<char, char> cc;

map<cc, char> mp;

void init() {
  for (int i = 0; i <= 'Z' - 'A'; ++i) {
    for (int j = 0; j <= 'Z' - 'A'; ++j) {
      char currentChar = (i + j) % 26 + 'A';
      mp[cc(i + 'A', j + 'A')] = currentChar;
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  init();

  string s, key;
  cin >> s;
  cin >> key;


  for(int i = 0, k = 0; i < s.size(); ++i) {
    for (int j = 0; j <= 'Z' - 'A'; ++j) {
      if (mp[cc(j + 'A', key[k])] == s[i]) {
        cout << (char)(j + 'A');
      }
    }
    k = (k + 1) % key.size();
  }
  return 0;
}
