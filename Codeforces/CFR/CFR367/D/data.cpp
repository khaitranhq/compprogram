#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define debugarr(x, n)                                                         \
  {                                                                            \
    for (int _ = 0; _ < n; ++_)                                                \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }
#define debugarr2d(x, n, m)                                                    \
  {                                                                            \
    for (int __ = 0; __ < n; ++__)                                             \
      debugarr(x[__], m);                                                      \
    cout << endl;                                                              \
  }
#define debugvi(x)                                                             \
  {                                                                            \
    for (int _ = 0; _ < x.size(); ++_)                                         \
      cout << x[_] << " ";                                                     \
    cout << endl;                                                              \
  }

using namespace std;

typedef vector<bool> vb;
const int MAX_DIGITS = 31;
const int MAX_NODES = 1e6 + 5;

bool bit(int x, int index) {return (x >> index) & 1;}

struct Trie {
  vector<int> next

  void Add() {}
  void Remove(){}

} trie;

int main() {
#ifdef LOCAL
  freope("data.inp", "r", stdin);
#endif

  int q;
  cin >> q;
  while (q--) {
    char type;
    int x;
    do {
      scanf("%c", &type);
    } while (type != '+' && type != '-' && type != '?');

    cin >> x;

    switch (type) {
    case '+':
      trie.Add(x);
      break;
    case '-':
      trie.Remove(x);
      break;
    case '?':
      for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 8; ++i)
          cout << trie.noNumberHasDigit[i][j] << " ";
        cout << endl;
      }
      cout << trie.Query(x) << endl;
      break;
    }
  }
  return 0;
}
