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

int pos[4];
const char ch[4] = {'e', 'z', 'p', 'c'};

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;

    for (int i = 0; i < 4; ++i) {
      for (size_t j = 0; j < s.size(); ++j)
        if (s[j] == ch[i]) {
          pos[i] = j;
          break;
        }
    }

    if (pos[1] < pos[2] && pos[2] < pos[3] && pos[0] < pos[3])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
