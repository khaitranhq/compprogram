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

const int MAX = 1e5;
ll n, x;
ll a[MAX];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--){
        cin >> n >> x;
        FOR(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1);
        int i = n, cnt = 0, cur = n + 1;
        for(; i > 0; ){
            int l = 1, r = n - i + 1, ans = -1;
            while(l <= r){
                int mid = (l + r) >> 1;
                if (mid * a[i] >= x){
                    ans = mid;
                    r = mid- 1;
                } else l = mid + 1;
            }
            // debug(i)debug(ans) debug(cur)
            if (i + ans - 1 < cur && ans != -1) { 
                ++cnt;
                cur = i;
            }
            --i;
        }
        cout << cnt << endl;
    }
    return 0;
}
