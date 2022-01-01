#include <bits/stdc++.h>

#define debug(x) cerr << #x << " = " << x << endl;
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 1; _ <= n; ++_)                                               \
      cerr << x[_] << " ";                                                     \
    cerr << endl;                                                              \
  }
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int __ = 1; __ <= n; ++__)                                            \
      debugarr(x[__], m);                                                      \
    cerr << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cerr << x[_] << " ";                                                     \
    cerr << endl;                                                              \
  }

using namespace std;

const int MAX = 1e5 + 5;
const int MIN_VALUE = -1e9 + 5;

struct SegmentTree {
  int Tree[4 * MAX];

  void update(int id, int l, int r, int u, int v, int value) {
    if (l > v || r < u)
      return;

    if (l >= u && r <= v) {
      Tree[id] = value;
      return;
    }

    int mid = (l + r) >> 1;
    update(2 * id, l, mid, u, v, value);
    update(2 * id + 1, mid + 1, r, u, v, value);

    Tree[id] = max(Tree[2 * id], Tree[2 * id + 1]);
  }

  int query(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
      return MIN_VALUE;

    if (l >= u && r <= v) {
      return Tree[id];
    }

    int mid = (l + r) >> 1;
    int L = query(2 * id, l, mid, u, v);
    int R = query(2 * id + 1, mid + 1, r, u, v);
    return max(L, R);
  }
} IT;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    IT.update(1, 1, n, i, i, x);
  };

  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int type, x, y;
    cin >> type >> x >> y;
    if (type == 1)
      IT.update(1, 1, n, x, x, y);
    else
      cout << IT.query(1, 1, n, x, y) << endl;
  }
  return 0;
}
