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
const int MAX = 5e2 + 5;
int n, m;
ll a[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        FOR(i, 1, n) cin >> a[i];

        bool ans = 0;
        map<int, bool> mp;
        FOR(i, 1, n) {
            if (ans) break;
            FOR(j, 1, n) {
                if (a[i] + a[j] > m) continue;
                if (mp.count(m - a[i] - a[j])) ans |= 1;
                if (ans) break;
                mp[a[i] + a[j]] = 1;
            }
        }
        if (ans) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
