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

const int MAX = 5e5 + 5;
string S;
int k;

int f[MAX];

int main() {
  cin >> S;

  cin >> k;
  for (int i = 1; i <= k; ++i) {
    int n, x, y;
    cin >> n >> x >> y;
    f[x] += n;
    f[y + 1] -= n;
  }


  int sum = 0;
  for (int i = 1; i <= S.size(); ++i) {
    sum += f[i];
    cout << (char) ((sum + S[i - 1] - 'A') % 26 + 'A');
  }

  return 0;
}
