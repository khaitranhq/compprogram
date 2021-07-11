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
ll maxLeft[MAX], maxRight[MAX];
ll minLeft[MAX], minRight[MAX];

bool check(int diff)
{
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= 6; ++j) {
      int leftIndex = b[i] - a[j];

      for (int k = 1; k <= 6; ++k)
        if (max(maxLeft[i - 1], maxRight[i + 1]) <= leftIndex + diff + a[k]){
          return 1;
        }
    }
  return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  for (int i = 1; i <= 6; ++i) cin >> a[i];
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> b[i];

  sort(b + 1, b + n + 1);

  maxLeft[1] = b[1];
  for (int i = 2; i <= n; ++i) maxLeft[i] = max(maxLeft[i - 1], b[i]);

  maxRight[n] = b[n];
  for (int i = n - 1; i > 0; --i) maxRight[i] = max(maxRight[i + 1], b[i]);

  ll l = 0, r = MAXA, ans = -1;
  while(l <= r)
  {
    int mid = (l + r) >> 1;
    if (check(mid))
    {
      r = mid - 1;
      ans = mid;
    }
    else l = mid + 1;
  }

  cout << ans;
  return 0;
}
