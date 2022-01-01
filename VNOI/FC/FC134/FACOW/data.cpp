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

typedef pair<int, int> pii;

const int MAX = 1e3 + 5;
int n, A, B;
int a[MAX], p[MAX];
bool isSelected[MAX];

int main() {
  cin >> n >> A >> B;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= n; ++i)
    cin >> p[i];

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (isSelected[i])
      continue;

    vector<pii> temp;
    for (int j = 1; j <= n; ++j)
      if (!isSelected[j])
        temp.push_back({a[j], j});

    sort(temp.begin(), temp.end());

    isSelected[i] = 1;
    bool flag = 0;
    for (int j = 0; j < temp.size(); ++j) {
      if (temp[j].first > a[i] && j == p[i]) {
        isSelected[temp[j].second] = 1;
        ans += B;
        flag = 1;
        break;
      }
    }

    if (!flag)
      ans += A;
  }

  cout << ans << endl;
  return 0;
}
