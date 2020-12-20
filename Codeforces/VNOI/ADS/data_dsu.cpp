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

const int MAXN = 2e3 + 5;
int n, m;
vector<ii> E;
int res = 0;

struct DisjointSet {
  int par[MAXN];

  DisjointSet() {
    memset(par, -1, sizeof(par));
  }

  int root(int u) {
    return par[u] < 0 ? u : par[u] = root(par[u]);
  }

  void join(int u, int v) {
    u = root(u); v = root(v);
    if (u == v) return;
    
    --res;
    if (par[u] < par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
  }
} DSU;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      E.push_back(ii(u, v));
    }

    res = m;
    for (auto edge: E) {
      DSU.join(edge.fi, edge.se);
    }

    cout << res;
    return 0;
}
