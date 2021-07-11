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
        int x1, y1, z1;
        int x2, y2, z2;
        cin >> z1 >> y1 >> x1;
        cin >> z2 >> y2 >> x2;

        int k = min(x1, y2);
        y2 -= k;
        cout << 2 * k - max(0, y1 -y2 - z2) * 2 << endl;
    }
    return 0;
}
