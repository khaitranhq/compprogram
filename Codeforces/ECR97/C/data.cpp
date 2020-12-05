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
        for (int _ = 1; _ <= n; ++_) \
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

const int MAX = 202;
const int INF = 0x3f3f3f3f;
const int MAXA = 500;
int n;
int a[MAX];
int g[MAXA + 2], tmp[MAXA + 2];
int f[MAX][MAXA + 2];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  int T;
  cin >> T;
  while(T--)
  {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);

    memset(g, INF, sizeof(g));
    for (int i = 1; i <= MAXA; ++i)
    {
      f[1][i] = abs(a[1] - i);
      g[i] = min(g[i - 1], f[1][i]);
    }

    g[0] = INF;
    for (int i = 2; i <= n; ++i)
    {
      for (int j = 1; j <= MAXA; ++j)
      {
        f[i][j] = g[j - 1] + abs(a[i] - j);
        tmp[j] = j == 1 ? f[i][j] : min(tmp[j - 1], f[i][j]);
      }
      for (int j = 1; j <= MAXA; ++j) g[j] = tmp[j];
    }

    int ans = INF;
    for (int j = 1; j <= MAXA; ++j) ans = min(ans, g[j]);
    cout << ans << endl;
  }
  return 0;
}
