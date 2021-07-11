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

const int MAXN = 102;
const int MAXS = 52;
int n;
int a[MAXN];
string s[MAXN];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--){
        int maxLen = 0;
        cin >> n;
        FOR(i, 1, n) {
            cin >> a[i];
            maxLen = max(maxLen, a[i]);
        }
        ++maxLen;

        s[1].resize(maxLen + 1);
        FOR(i, 1, maxLen)
            s[1][i] = 'a';

        FOR(i, 1, n) {
            s[i + 1].resize(maxLen + 1);
            FOR(j, 1, maxLen)
                if (j <= a[i])
                    s[i + 1][j] = s[i][j];
                else
                    s[i + 1][j] = s[i][j] == 'z' ? 'a' : s[i][j] + 1;
        }

        FOR(i, 1, n + 1){
            FOR(j, 1, s[i].size() - 1)
                putchar(s[i][j]);
            cout << endl;
        }
    }
    return 0;
}
