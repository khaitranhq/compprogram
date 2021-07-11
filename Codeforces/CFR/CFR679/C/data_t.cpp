#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                 \
    {                                       \
        for (int _ = 0; _ < n; ++_)        \
        {                                   \
            for (int __ = 0; __ < m; ++__) \
                cout << x[_][__] << " ";    \
            cout << endl;                   \
        }                                   \
        cout << endl;                       \
    }
#define debugarr(x, n)               \
    {                                \
        for (int _ = 0; _ < n; ++_) \
            cout << x[_] << " ";     \
        cout << endl;                \
    }
#define debugvi(x)                         \
    {                                      \
        for (int _ = 0; _ < x.size(); ++_) \
            cout << x[_] << " ";           \
        cout << endl;                      \
    }

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAX = 1e5 + 5;
const ll MAXA = 1e9;
int n;
ll a[7], b[MAX];
ll x[MAX];
ll ans = MAXA;

void Attempt(int u) {
  if (u > n) {
    ll maxNum = x[1], minNum = x[1];
    for (int i = 2; i <= n; ++i){
      maxNum = max(maxNum, x[i]);
      minNum = min(minNum, x[i]);
    }
    ans = min(ans, maxNum - minNum);
    if (ans == 2) {
      for (int i = 1 ; i <= n; ++i) cout << x[i] << " ";
      cout << endl;
    }
    return;
  }
  for (int i = 1; i <= 6; ++i) {
    x[u] = b[u] - a[i];
    Attempt(u + 1);
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.ans", "w", stdout);
#endif

  for (int i = 1; i <= 6; ++i) cin >> a[i];
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> b[i];
  sort(b + 1, b + n + 1);

  Attempt(1);
  cout << ans;
  return 0;
}
