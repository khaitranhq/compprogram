#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a ; i <= b ; ++i)
#define FOD(i, a, b) for(int i = a ; i >= b ; --i)
#define REP(i, a, b) for(int i = a ; i < b ; ++i)
#define FRSZ(i, a) for(int i = 0 ; i < a.size() ; ++i)
#define FDSZ(i, a) for(int i = a.size() – 1 ; i >= 0 ; --i)

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m) {FOR(_, 1, (n)) {FOR(__, 1, (m)) cout << x[_][__] << " "; cout << endl;} cout << endl;}
#define debugarr(x, n) {FOR(_, 1, (n)) cout << x[_] << " " ; cout << endl;}
#define debugvi(x) {FRSZ(_, x) cout << x[_] << " " ; cout << endl;}

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;

const int MAX = 1e5 + 5;
int n, k, t, m;
int check[MAX];
vector<int> adj[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    queue<int> q;
    memset(check, -1, sizeof(check));
    cin >> n >> k >> t;
    FOR(i, 1, k){
        int x;
        cin >> x;
        check[x] = 0;
        q.push(x);
    }

    cin >> m;
    FOR(i, 1, m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(q.size()){
        int u = q.front(); q.pop();
        FRSZ(i, adj[u]){
            int v = adj[u][i];
            if (check[v] == -1){
                check[v] = check[u] + 1;
                q.push(v);
            }
        }
    }

    FOR(i, 1, n)
        if (check[i] > t) cout << -1 << " ";
        else cout << check[i] << " ";
    return 0;
}
