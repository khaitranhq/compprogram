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
vector<int> adj[MAXN];
bool isVisited[MAXN];

void bfs(int startVer) {
  queue<int> q;
  q.push(startVer);
  while(q.size()) {
    int u = q.front(); q.pop();
    isVisited[u] = 1;

    for(auto v : adj[u])
      if (!isVisited[v]) 
        q.push(v);
  }
}

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
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int numberConnectedComponent = 0;
    for (int i = 0; i < n; ++i)
      if (!isVisited[i]) {
        ++numberConnectedComponent;
        bfs(i);
      }

    cout << m - n + numberConnectedComponent;
    return 0;
}
