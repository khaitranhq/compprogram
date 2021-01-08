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

const int MAXN = 4;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
bool a[2][MAXN][MAXN];
int d[MAXN][MAXN][MAXN][MAXN]; //Min distance from chessman to all other cell

void BFS(ii s){
  queue<ii> q;
  q.push(s);
  while(q.size()) {
    ii u = q.front(); q.pop();

    for (int i = 0; i < MAXN; ++i) {
      ii v = ii(u.fi + dx[i], u.se + dy[i]);

      if (v.fi < 0 || v.fi >= MAXN) continue;
      if (v.se < 0 || v.se >= MAXN) continue;
      if (!a[0][v.fi][v.se])
        q.push(v);
    }
  }
}

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < MAXN; ++j)
    {
      string s;
      cin >> s;
      for (int k = 0; k < s.size(); ++i)
        a[i][j][k] = s[k] - '0';
    }

  for (int i = 0; i < MAXN; ++i)
    for (int j = 0; j < MAXN; ++j)
      if (a[0][i][j] && !a[1][i][j])
        BFS(ii(i, j));
  return 0;
}
