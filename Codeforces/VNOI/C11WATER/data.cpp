#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                 \
    {                                       \
        for (int _ = 1; _ < n; ++_)        \
        {                                   \
            for (int __ = 1; __ < m; ++__) \
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

const int MAX = 1e3 + 5;
const int MAXA = 1e6 + 5;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
int n, m;
vector<ii> cells[MAXA];
ll a[MAX][MAX], h[MAX][MAX];

void bfs(int x, int y, ll val) {
  queue<ii> q;
  h[x][y] = val;
  q.push(ii(x, y));

  while(q.size()) {
    int u = q.front().fi, v = q.front().se;
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int xx = u + dx[i];
      int yy = v + dy[i];

      if (xx < 1 || xx > m) continue;
      if (yy < 1 || yy > n) continue;

      if (!h[xx][yy] && a[xx][yy] <= val) {
        h[xx][yy] = val;
        q.push(ii(xx, yy));
      }
    }  
  }
}

bool isBorder(int x, int y) {
  for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if (h[xx][yy]) return 1;
  }  
  return 0;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
  
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        scanf("%lld", &a[i][j]);
        cells[a[i][j]].push_back(ii(i, j));
      }

    memset(h, -1, sizeof(h));

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        h[i][j] = 0;

    for (int i = 1; i <= MAXA - 5; ++i)
      for (int j = 0; j < cells[i].size(); ++j) {
        int x = cells[i][j].first;
        int y = cells[i][j].second;
        if (!h[x][y] && isBorder(x, y))
          bfs(x, y, a[x][y]);
      }


    ll ans = 0;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        ans += h[i][j] - a[i][j];

    cout << ans;
    return 0;
}

// BFS
// Logic with nature, actually
