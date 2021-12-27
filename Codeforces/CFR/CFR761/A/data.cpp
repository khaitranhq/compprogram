#include <bits/stdc++.h>

#define debug(x) cerr << #x << " = " << x << endl;
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 1; _ <= n; ++_)                                               \
      cerr << x[_] << " ";                                                     \
    cerr << endl;                                                              \
  }
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int __ = 1; __ <= n; ++__)                                            \
      debugarr(x[__], m);                                                      \
    cerr << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cerr << x[_] << " ";                                                     \
    cerr << endl;                                                              \
  }

using namespace std;

int main() {

  int numTest;
  cin >> numTest;
  while (numTest--) {
    string S, T;
    cin >> S >> T;
    sort(S.begin(), S.end());

    for (int i = 0; i + 2 < S.size(); ++i) {
      bool flag = 0;
      for (int j = 0; j < T.size(); ++j)
        if (S[i + j] == T[j])
          flag = 1;

      if (flag) {
        swap(S[i + 1], S[i + 2]);
        break;
      }
    }

    cout << S << endl;
  }

  return 0;
}
