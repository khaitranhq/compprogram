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

const int MAX = 1005;

int n;
int a[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--){
        cin >>  n;
        FOR(i, 1, n) cin >> a[i];

        bool flag = 0;
        FOR(i, 1, n){
            if (flag) break;
            int k = 0;
            FOR(j, 1, n){
                if (i == j) continue;
                if (a[i] > a[j])
                    if (k == 0) k = j;
                    else {
                        if (j < i && k < i) continue;
                        if (j > i && k > i) continue;
                        cout << "YES" << endl;
                        cout << k << " " << i << " " << j << endl;
                        flag = 1;
                        break;
                    }
            }
        }
        if (!flag) cout << "NO" << endl;
    }
    return 0;
}
