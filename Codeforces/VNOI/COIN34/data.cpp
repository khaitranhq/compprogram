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
#define bit(x, y) (x >> y) & 1
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAXX = 40;
const ll MAXA = 2e9;
ll x[MAXX]; 
map<ll, int> m1, m2;

void Calc(int begin, int end, map<ll, int> &m) {
  int diff = end - begin + 1;
  for (int i = 0; i < (1 << diff); ++i) {
    ll sum = 0;
    for (int j = begin; j <= end; ++j) 
      if (bit(i, (j - begin))) sum += x[j];

    m[sum] = max(m[sum], __builtin_popcount(i));
  }
}

int main(){
  #ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
  #endif

  x[1] = 2; x[2] = 3; x[3] = 5;
  for (int i = 4; i <= 34; ++i)
    x[i] = x[i - 3] + x[i - 2] + x[i - 1];

  Calc(1, 17, m1);
  Calc(18, 34, m2);

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t){
    int x;
    cin >> x;
    
    int ans = -1;
    for (auto it = m1.begin(); it != m1.end(); ++it) 
      if (it -> first <= x && m2.count(x - it -> first)) {
        ans = max(ans, it -> second + m2[x - it -> first]);
      }

    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
