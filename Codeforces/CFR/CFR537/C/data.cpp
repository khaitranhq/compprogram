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

typedef long long ll;
int n, k, A, B;
vector<int> a;

void enter() {
  cin >> n >> k >> A >> B;
  for (int i = 1; i <= k; ++i) {
    int x;
    cin >> x;
    a.push_back(x - 1);
  }
  sort(a.begin(), a.end());
}

ll findMiniumPower(int l, int r) {
  int i = lower_bound(a.begin(), a.end(), l) - a.begin();
  int j = upper_bound(a.begin(), a.end(), r) - a.begin();

  // All elements are empty
  if (i == j)
    return A;

  // Otherwise
  ll power_consumed = 1LL * B * (j - i) * (r - l + 1);

  if (r == l)
    return power_consumed;

  int mid = (l + r) >> 1;
  ll leftSubArrayResult = findMiniumPower(l, mid);
  ll rightSubArrayResult = findMiniumPower(mid + 1, r);

  ll ans = min(power_consumed, leftSubArrayResult + rightSubArrayResult);

  return ans;
}

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
#endif

  enter();
  cout << findMiniumPower(0, (1 << n) - 1);
  return 0;
}
