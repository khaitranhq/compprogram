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

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        vector<int> digit;
        do{
            digit.push_back(n % 10);
            n /= 10;
        }while(n);

        bool ans = 1;
        reverse(digit.begin(), digit.end());
        for(int i = 0 ; i < digit.size() ; ++i) {
            if (digit[i] != 1){
                ans = 0;
                break;
            }

            if (i == digit.size() - 1) {
                continue;
            }

            if (digit[i + 1] == 2) ++i;
            if (digit[i + 1] == 2) ++i;
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
