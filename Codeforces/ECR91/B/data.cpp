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

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int n = s.size();
        s = " " + s;

        int cnt[3] = {0, 0, 0};
        FOR(i, 1, n){
            if (s[i] == 'P') ++cnt[0];
            if (s[i] == 'R') ++cnt[1];
            if (s[i] == 'S') ++cnt[2];
        }

        if (cnt[0] >= cnt[1] && cnt[0] >= cnt[2])
            FOR(i, 1, n) cout << 'S';
        else 
            if (cnt[1] >= cnt[0] && cnt[1] >= cnt[2])
                FOR(i, 1, n) cout << 'P';
            else
                FOR(i, 1, n) cout << 'R';
        cout << endl;
    }
    return 0;
}
