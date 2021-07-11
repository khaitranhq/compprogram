#include <bits/stdc++.h>

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

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        if (n < k) cout << k - n << endl;
        else cout << (n + k) % 2 << endl;
    }
    return 0;
}
