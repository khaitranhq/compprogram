#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int __ = 0; __ < n; ++__)                                             \
      debugarr(x[__], m);                                                      \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }

using namespace std;

int main(int argc, const char *argv[]) {
#ifdef LOCAL
  freopen(argv[1], "r", stdin);
#endif

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int halfN = n / 2;

    bool flag = 0;
    for (int i = 0; i < halfN; ++i)
      if (s[i] == '0') {
        printf("%d %d %d %d\n", i + 2, n, i + 1, n);
        flag = 1;
        break;
      }

    if (flag) continue;

    for (int i = n / 2; i < n ; ++i)
      if (s[i] == '0') {
        printf("%d %d %d %d\n", i - halfN + 1, i + 1, i - halfN + 1, i);
        flag=  1;
      }

    if (flag) continue;

    cout << 1 << " " << n /2 << " " << 2 << " " << n / 2 + 1 << endl;
  }
  return 0;
}
