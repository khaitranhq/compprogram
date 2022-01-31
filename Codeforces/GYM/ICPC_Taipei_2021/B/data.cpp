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

const int MAX = 1e3 + 5;
int f[MAX][MAX], numCommonCharsLeft[MAX], numCommonCharsRight[MAX];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s1, s2;
    cin >> n;
    cin >> s1 >> s2;

    numCommonCharsLeft[0] = s1[0] == s2[0];
    for (int i = 1; i < n; ++i)
      numCommonCharsLeft[i] = numCommonCharsLeft[i - 1] + (s1[i] == s2[i]);

    numCommonCharsRight[n - 1] = s1[n - 1] == s2[n - 1];
    for (int i = n - 2; i >= 0; --i)
      numCommonCharsRight[i] = numCommonCharsRight[i + 1] + (s1[i] == s2[i]);

    for (int i = 0; i < n; ++i)
      f[i][1] = s1[i] == s2[i];
    for (int i = 0; i < n - 1; ++i)
      f[i][2] = (s1[i] == s2[i + 1]) + (s1[i + 1] == s2[i]);

    for (int len = 3; len <= n; ++len)
      for (int i = 0; i + len - 1 < n; ++i)
        f[i][len] = f[i + 1][len - 2] + (s1[i] == s2[i + len - 1]) +
                    (s1[i + len - 1] == s2[i]);

    int maxCommonReversedChars = 0, a = 0, b = 0;
    for (int len = 1; len <= n; ++len)
      for (int i = 0; i + len - 1 < n; ++i) {
        int totalNumCommonReversedChars = f[i][len];
        if (i > 0)
          totalNumCommonReversedChars += numCommonCharsLeft[i - 1];
        if (i + len < n)
          totalNumCommonReversedChars += numCommonCharsRight[i + len];

  /*       debug(i); */
        /* debug(len); */
        /* debug(f[i][len]); */
        if (maxCommonReversedChars < totalNumCommonReversedChars) {
          maxCommonReversedChars = totalNumCommonReversedChars;
          a = i;
          b = i + len - 1;
        }
      }
    int maxCommonChars = 0;
    for (int i = 0; i < n; ++i)
      if (s1[i] == s2[i])
        ++maxCommonChars;

    printf("%d %d %d %d\n", maxCommonChars, maxCommonReversedChars, a + 1, b + 1);
  }

  return 0;
}
