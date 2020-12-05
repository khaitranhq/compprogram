
#include <bits/stdc++.h>
#include <functional>
#include <queue>

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
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MAXN = 3e5 + 5;
int n;
int a[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.ans", "w", stdout);
#endif

  int T, t = 1;
  cin >> T;
  while(T--)
  {
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 1; i <= n; ++i)
    {
      int x;
      cin >> x;
      pq.push(x);
    }

    int cnt = 0;
    while(pq.size() && pq.top() - cnt >= 0)
    {
      int x = pq.top();
      pq.pop();
      ++x;
      pq.push(x);
      ++cnt;
    }

    cout << "Case #" << t << ": " << cnt << endl;
    ++t;

  }
  return 0;
}

