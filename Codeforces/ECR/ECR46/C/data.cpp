#include <bits/stdc++.h>
#include <queue>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int _ = 0; _ < n; ++_) {                                              \
      for (int __ = 0; __ < m; ++__)                                           \
        cout << x[_][__] << " ";                                               \
      cout << endl;                                                            \
    }                                                                          \
    cout << endl;                                                              \
  }
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }

#define fi first
#define se second
#define pb push_back
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAX = 2e5 + 5;
int n;
ii seg[MAX];
int numberCover[MAX];

int main() {
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> seg[i].fi >> seg[i].se;

  sort(seg, seg + n);

  priority_queue<ii, vector<ii>, greater<ii>> pq;
  for (int i = 0; i < n; ++i) {
    pq.push(seg[i]);

    while (i + 1 < n && seg[i + 1].fi == seg[i + 1].fi) {
      pq.push(seg[i + 1]);
      ++i;
    }
    ++numberCover[pq.size()];
  }
  return 0;
}
