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
typedef pair<int, ii> iii;

const int MAXN = 1e4 + 5;
const int MAXM = 1e5 + 5;
int n, m;
int C[MAXN];
vector<iii> E;
int res = 0;

struct DisjointSet {
  int par[MAXN];
  
  DisjointSet() {
    memset(par, -1, sizeof(par));
  }

  int root(int u){
    return par[u] < 0 ? u : par[u] = root(par[u]);
  }

  void join(int u, int v, int w){
    u = root(u); v = root(v);
    if (u == v) return;

    if (par[u] < par[v]) swap(u, v);
    res += w;

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

    int minC = 10005;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &C[i]);
      minC = min(minC, C[i]);
    }

    for (int i = 1; i <= m; ++i) {
      int u, v, l;
      scanf("%d%d%d", &u, &v, &l);
      E.push_back(iii(C[u] + C[v] + l * 2, ii(u, v)));
    }

    sort(E.begin(), E.end());
    for (int i = 0; i < E.size(); ++i) {
      int u = E[i].se.fi, v = E[i].se.se;
      int w = E[i].fi;

      DSU.join(u, v, w);
    }

    cout << res + minC << endl;
    return 0;
}

