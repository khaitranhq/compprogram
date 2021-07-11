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
typedef pair<int, int> pii;

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;

    int l = -1, r = -1;
    
    for (size_t i = 0 ;i < s.size(); ++i)
      if (s[i] == 'a') {
        l = i;
        r = i;
        break;
      }

    if (l == -1 && r == -1) {
      cout << "NO" << endl;
      continue;
    }

    char currentChar ='a';
    bool flag = 1;
    while(l != 0 || r != s.size() -1) {
      // debug(l);debug(r);
      if (l > 0 && s[l - 1] == currentChar + 1) {
        --l;
      }
      else 
        if (r < s.size() -1 && s[r + 1] == currentChar + 1) {
          ++r;
        }
        else {
          flag = 0;
          break;
        }
      ++currentChar;
    }

    if (flag && r - l + 1 == s.size()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}
