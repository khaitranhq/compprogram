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

typedef long long ll;
const int MAX = 1e3 + 5;
const ll BASE = 1e9 + 7;
int n;
int a[MAX];

ll mul(vector<int> exclusion) {
  int j = exclusion.size() ? 0 : -1;
  ll ans = 1;
  for (int i = 1; i <= n; ++i) {
    if (j >= 0 && i == exclusion[j]) {
      ++j;
      continue;
    }
    ans = ans * a[i] % BASE;
  }
  return ans;
}

int main() {
  cin >> n;
  int numberZeros = 0;
  int numberPos = 0;
  int numberNeg = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    numberNeg += a[i] < 0;
    numberPos += a[i] > 0;
    numberZeros += a[i] == 0;
  }

  if (numberZeros > 1) {
    cout << 0;
    return 0;
  }

  vector<int> exclusion;
  if (numberZeros == 1) {

    for (int i = 1; i <= n; ++i)
      if (!a[i])
        exclusion.push_back(i);
    if (numberNeg % 2) {
      cout << 0;
      return 0;
    }
    cout << mul(exclusion);
    return 0;
  }

  if (numberNeg % 2) {

    int maxNeg = -BASE, maxNegId;
    for (int i = 1; i <= n; ++i)
      if (a[i] < 0 && maxNeg < a[i]) {
        maxNeg = a[i];
        maxNegId = i;
      }
    exclusion.push_back(maxNegId);

    cout << mul(exclusion);
    return 0;
  }

  cout << mul(exclusion);

  return 0;
}
