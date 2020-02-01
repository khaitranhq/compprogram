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

#define left asdfasdfadf
#define right asdfadvas
using namespace std;

typedef int64_t ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> III;
const int MAX = 2e5 + 5;
int n;
ll f[MAX], sum[MAX];
ii a[MAX];

struct FenwickTree{
    int Tree[2 * MAX];

    void init(){
        memset(Tree, 0, sizeof(Tree));
    }

    void update(int u, int x){
        for(; u <= 2 * n ; u += u & -u)
            Tree[u] += x;
    }

    int query(int u){
        int ans = 0;
        for(; u ; u -= u & -u)
            ans += Tree[u];
        return ans;
    }
} BIT;

void numberCompression(){
    vector<III> values;
    FOR(i, 1, n){
        values.push_back(III(a[i].fi, ii(i, 0)));
        values.push_back(III(a[i].se, ii(i, 1)));
    }
    sort(values.begin(), values.end());

    int cnt = 1;
    FRSZ(i, values){
        if (i && values[i].fi != values[i - 1].fi) ++cnt;
        III element = values[i];
        if (element.se.se)
            a[element.se.fi].se = cnt;
        else
            a[element.se.fi].fi = cnt;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--){
        cin >> n;
        FOR(i, 1, n)
            cin >> a[i].fi >> a[i].se;
        numberCompression();
        sort(a + 1, a + n + 1);

        memset(sum, 0, sizeof(sum));
        FOR(i, 1, n) {
            int left = i + 1, right = n, ans = i;
            while(left <= right){
                int mid = (left + right) >> 1;
                if (a[mid].fi <= a[i].se){
                    ans = mid;
                    left = mid + 1;
                } else right = mid - 1;
            }

            f[i] += ans - i;
            sum[i + 1] += 1;
            sum[ans + 1] -= 1;
        }

        sum[0] = 0;
        FOR(i, 1, n)
            sum[i] = sum[i - 1] + sum[i];

        FOR(i, 1, n)
            f[i] += sum[i];
        
        int indexMax = -1;
        FOR(i, 1, n)
            if (indexMax == -1 || f[indexMax] < f[i])
                indexMax = i;

        int res = 0;
        a[0] = ii(0, 0);
        FOR(i, 1, n)  {
            if (i == indexMax) continue;
            if (i - 1 == indexMax){
                if (a[i].fi > a[i - 2].se) ++res;
            }
            else 
                if (a[i].fi > a[i - 1].se) ++res;
        }
        cout << res << endl;;
    }
    return 0;
}
