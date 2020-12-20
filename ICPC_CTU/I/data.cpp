#include <bits/stdc++.h>
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;

const ll MAX = 5e5 + 5;
const ll INF = 1e18;
ll n, m;
ll hc, sc, hj, sj;
vector<ii> adj[MAX];
vector<iii> G;
ll d[4][MAX];

void Dijkstra(ll s, int id) {
    for (int i = 1; i <= n; ++i) d[id][i] = INF;
    d[id][s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));

    while(pq.size()) {
        ll u = pq.top().se, t = pq.top().fi;
        pq.pop();

        if (d[id][u] != t) continue;
        for (auto v : adj[u])
            if (d[id][v.fi] > d[id][u] + v.se) {
                d[id][v.fi] = d[id][u] + v.se;
                pq.push(ii(d[id][v.fi], v.fi));
            }
    }
}

void check(int u, int v, ll t, int &ans) {
    if (d[0][u] + d[1][v] + t == d[0][sc])
        if (d[2][v] + d[3][u] + t == d[2][sj]) {
            if (abs(d[0][u] - d[2][v]) < t) ++ans;
        }
    if( d[0][u]==d[0][v] && d[2][u] == d[2][v])
        return;
    if (d[0][v] + d[1][u] + t == d[0][sc])
        if (d[2][u] + d[3][v] + t == d[2][sj]) {
            if (abs(d[0][v] - d[2][u]) < t) ++ans;
        }
}

bool checkInfinity(int u, int v, ll t) {
    if (d[0][u] + d[1][v] + t == d[0][sc])
        if (d[2][u] + d[3][v] + t == d[2][sj]) {
            if (d[0][u] == d[2][u]) return 1;
        }
    return 0;
}

int main() {
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);

    while(1) {
        cin >> n >> m;
        if (!n && !m) return 0;

        cin >> hc >> sc >> hj >> sj;
        for (int i = 1; i <= n; ++i) adj[i].clear();
        G.clear();

        for (int i = 0; i < m; ++i) {
            ll u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back(ii(v, c));
            adj[v].push_back(ii(u, c));
            G.push_back(iii(ii(u, v), c));
        }

        Dijkstra(hc, 0);
        Dijkstra(sc, 1);
        Dijkstra(hj, 2);
        Dijkstra(sj, 3);

        int ans = 0;

        // Diff sch, diff house
        for (int i = 1; i <= n; ++i)
            if (i != sc && i != sj && i != hc && i != hj)
                if (d[0][i] + d[1][i] == d[0][sc])
                    if (d[2][i] + d[3][i] == d[2][sj])
                        if (d[0][i] == d[2][i] || d[1][i] == d[3][i])
                            ++ans;

        // Same house
        if (hc == hj) ++ans;

        // Same school
        if (sc == sj) ++ans;
        else {
            if (d[0][sj] + d[1][sj] == d[0][sc])
                if (d[0][sj] >= d[2][sj])
                    ++ans;

            if (d[2][sc] + d[3][sc] == d[2][sj])
                if (d[0][sc] <= d[2][sc])
                    ++ans;
        }

        bool flag = 0;
        for (auto edge : G) {
            ll u = edge.fi.fi, v = edge.fi.se, t = edge.se;

            if (checkInfinity(u, v, t) || checkInfinity(v, u, t)){
                cout << -1 << endl;
                flag = 1;
                break;
            }
            check(u, v, t, ans);
        }

        if (!flag) cout << ans << endl;
    }
    return 0;
}
