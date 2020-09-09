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

const int MAX = 1e5 + 5;
int n;
int a[MAX];

struct Fenwick{
    ll Tree[MAX];

    void update(int u, int x){
        for(; u <= n ; u += u & -u)
            Tree[u] += x;
    }

    ll query(int u){
        ll ans = 0;
        for(; u > 0 ; u -= u & -u)
            ans += Tree[u];
        return ans;
    }
} BIT;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = __gcd(abs(x1 - x2), abs(y1 - y2)) - 1;

    if (ans == -1) ans = 1;
    cout << ans;

    return 0;
}
