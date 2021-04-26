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
int n, k, t, m;
queue<int> q;
vector<int> adj[MAX];
int d[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    memset(d, -1, sizeof(d));

    cin >> n >> k >> t;
    for (int i = 1; i <= k; ++i) {
      int x;
      cin >> x;
      q.push(x);
      d[x] = 0;
    }

    cin >> m;
    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    while(q.size()) {
      int u = q.front(); q.pop();

      for (auto v: adj[u]) {
        if (d[v] != -1) continue;
        d[v] = d[u] + 1;
        q.push(v);
      }
    }

    for (int i = 1; i <= n; ++i) cout << (d[i] <= t ? d[i] : -1) << " " ;
    return 0;
}
