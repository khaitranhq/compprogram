#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                 \
    {                                       \
        for (int _ = 0; _ < n; ++_)        \
        {                                   \
            for (int __ = 0; __ < m; ++__) \
                cout << x[_][__] << " ";    \
            cout << endl;                   \
        }                                   \
        cout << endl;                       \
    }
#define debugarr(x, n)               \
    {                                \
        for (int _ = 0; _ < n; ++_) \
            cout << x[_] << " ";     \
        cout << endl;                \
    }
#define debugvi(x)                         \
    {                                      \
        for (int _ = 0; _ < x.size(); ++_) \
            cout << x[_] << " ";           \
        cout << endl;                      \
    }

#define fi first
#define se second
#define pb push_back
#define round vaskdjfa
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int score[2];
int round[2];

void check() {
    for (int i = 0; i < 2; ++i) {
      if ((score[i] >= 5 && score[i] - score[i ^ 1] >= 2) || score[i] == 10) {
        score[i] = 0;
        score[i ^ 1] = 0;
        ++round[i];
      }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif

    string s;
    cin >> s;

    int current = 0;

    for (int i = 0; i < s.size(); ++i) {
      check();

      if (s[i] == 'S' && round[0] < 2 && round[1] < 2) {
        ++score[current];
      }

      if (s[i] == 'R' && round[0] < 2 && round[1] < 2) {
        ++score[current ^ 1];
        current ^= 1;
      }


      if (s[i] == 'Q') {
        if (round[1] == 2 || round[0] == 2) {
          cout << round[0] << " ";
          if (round[0] == 2) cout << "(winner)";
          cout << " - " << round[1] << " ";
          if (round[1] == 2) cout << "(winner)";
          continue;
        }

        cout << round[0] << " (" << score[0];
        if (!current) cout << "*";
        cout << ") - ";
        cout << round[1] << " (" << score[1];
        if (current) cout << "*";
        cout << ")" << endl;
      }

    }

    return 0;
}
