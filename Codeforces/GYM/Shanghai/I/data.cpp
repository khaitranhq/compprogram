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
using namespace std;

typedef int64_t ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct Point
{
  double x, y;

  Point(double x, double y): x(x), y(y) {}

  double distance(Point other)
  {
      double tmp1 = other.x - x;
      double tmp2 = other.y - y;
      return sqrt(tmp1 * tmp1 + tmp2 * tmp2);
    }
};

const int MAX = 5e2 + 5;
const double EPS = 1e-6;
int n, m;
vector<Point> intersects[MAX];

int main()
{
#ifndef ONLINE_JUDGE
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  cin >> n >> m;

  for (int i = 1; i <= n; ++i)
    for (double angle = 0; angle - 2 * M_PI < -EPS; angle += M_PI / m)
    {
          double x = cos(angle) * i * 1.0;
          double y = sin(angle) * i * 1.0;

          intersects[i].push_back(Point(x, y));
        }

  double ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < intersects[i].size(); ++j)
      ans += Point(0, 0).distance(intersects[i][j]);

  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < intersects[i].size(); ++j)
      cout << intersects[i][j].x << " " << intersects[i][j].y << endl;

  double tmp = 0;
  for (int i = 1; i <= n; ++i)
  {
      tmp += 2 * i * m;
      for (int j = 1; j < m; ++j)
        tmp += intersects[i][0].distance(intersects[i][j]) * m;
    }
  debug(tmp)
  ans += tmp;

  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
          double sum = 0;
          for (int k = 1; k < m; ++k)
            sum += intersects[i][0].distance(intersects[j][k]);
          sum *= 2;
          sum += intersects[i][0].distance(intersects[j][0]);
          sum += intersects[i][0].distance(intersects[j][m]);
          sum *= m;
          ans += sum;
        }

  cout << ans;
  return 0;
}
