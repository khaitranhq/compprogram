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

typedef pair<int, int> ii;
const int MAX = 105;
int n;
ii a[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--){
        cin >> n;
        FOR(i, 1, n) cin >> a[i].fi >> a[i].se;

        bool flag = 1;
        FOR(i, 1, n) 
            if (
                a[i].se - a[i - 1].se > a[i].fi - a[i - 1].fi || 
                a[i].fi < a[i - 1].fi || 
                a[i].se < a[i - 1].se
            ) {
                flag = 0; 
                break;
            }
        
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
