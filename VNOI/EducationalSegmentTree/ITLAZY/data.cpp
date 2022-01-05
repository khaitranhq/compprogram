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

typedef long long ll;
const int MAX = 1e5 + 5;
const ll MIN_VALUE = -1e17;

struct Node {
  ll lazy;
  ll val;
};

struct SegmentTree {
  Node Tree[4 * MAX];

  void updateLowerNodes(int id) {
    ll parentLazy = Tree[id].lazy;

    Tree[2 * id].lazy += parentLazy;
    Tree[2 * id].val += parentLazy;

    Tree[2 * id + 1].lazy += parentLazy;
    Tree[2 * id + 1].val += parentLazy;

    Tree[id].lazy = 0;
  }

  void update(int id, int l, int r, int u, int v, int value) {
    if (l > v || r < u)
      return;

    if (l >= u && r <= v) {
      Tree[id].lazy += value;
      Tree[id].val += value;
      return;
    }

    updateLowerNodes(id);

    int mid = (l + r) >> 1;
    update(2 * id, l, mid, u, v, value);
    update(2 * id + 1, mid + 1, r, u, v, value);

    Tree[id].val = max(Tree[2 * id].val, Tree[2 * id + 1].val);
  }

  ll query(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
      return MIN_VALUE;

    if (l >= u && r <= v)
      return Tree[id].val;

    updateLowerNodes(id);

    int mid = (l + r) >> 1;
    ll L = query(2 * id, l, mid, u, v);
    ll R = query(2 * id + 1, mid + 1, r, u, v);
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
  }

  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y, val;
      cin >> x >> y >> val;
      IT.update(1, 1, n, x, y, val);
    } else {
      int l, r;
      cin >> l >> r;
      cout << IT.query(1, 1, n, l, r) << endl;
    }
  }
  return 0;
}
