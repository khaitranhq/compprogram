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

const int MAX = 3E2 + 5;
int d[MAX];

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

        int res = 0;
        while(s.size() > 1){
            ++res;
            FOR(i, 1, n) d[i] = 0;
            FOR(i, 1, n)
                FOR(j, 1, n - i + 1)
                    if (s[i] == s[i + j - 1]) d[i] = j;
                    else break;
            
            int maxLenghPalindromeIndex = 0;
            FOR(i, 1, n)
                if (!maxLenghPalindromeIndex || d[maxLenghPalindromeIndex] < d[i])
                    maxLenghPalindromeIndex = i;
            
            int indexLeft = maxLenghPalindromeIndex, indexRight = maxLenghPalindromeIndex + d[maxLenghPalindromeIndex];
            s = s.substr(0, indexLeft - 1) + (indexRight < s.size() ? s.substr(indexRight, s.size()) : "");
            debug(s) debug(indexLeft) debug(indexRight) cout << endl;
        }
        cout << res;
    }
    return 0;
}
