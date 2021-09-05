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

const double EPS = 1e-9;

struct point {
  double x, y;

  point() {
    x = 0;
    y = 0;
  }

  point(double x, double y) : x(x), y(y) {}

  double getDistance(point other) { return hypot(x - other.x, y - other.y); }

  bool areEqual(point other) {
    return fabs(x - other.x) <= EPS && fabs(y - other.y) <= EPS;
  }
};

struct line {
  double a, b, c; // ax + by + c = 0;

  line() { a = b = c = 0; }
  line(point p1, point p2) {
    if (fabs(p1.x - p2.x) < EPS)
      a = 1.0, b = 0.0, c = -p1.x;
    else {
      a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
      b = 1.0;
      c = -(double)(a * p1.x) - p1.y;
    }
  }

  bool areParallel(line other) {
    return (fabs(a - other.a) < EPS) && (fabs(b - other.b) < EPS);
  }

  bool areSame(line other) {
    return areParallel(other) && (fabs(c - other.c) < EPS);
  }

  // returns true (+ intersection point) if two lines are intersect
  point findIntersectPoint(line other) {
    if (areParallel(other))
      return point(); // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    point ans;
    ans.x = (other.b * c - b * other.c) / (other.a * b - a * other.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(b) > EPS)
      ans.y = -(a * ans.x + c);
    else
      ans.y = -(other.a * ans.x + other.c);
    return ans;
  }
};

int n;
vector<line> lines;

int main() {
#ifdef LOCAL
  freopen("data.inp", "r", stdin);
#endif

  cin >> n;
  for (int i = 0; i < n; ++i) {
    point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    lines.push_back(line(p1, p2));
    // cout << lines[i].a << " " << lines[i].b << " " << lines[i].c << endl;
  }

  double ans = 0.0;
  bool flag = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      for (int k = j + 1; k < n; ++k) {
        if (lines[i].areParallel(lines[j]) || lines[i].areParallel(lines[k]) ||
            lines[j].areParallel(lines[k]))
          continue;

        point p1 = lines[i].findIntersectPoint(lines[j]);
        point p2 = lines[i].findIntersectPoint(lines[k]);
        point p3 = lines[j].findIntersectPoint(lines[k]);

        //                 cout << p1.x << p1.y << endl;
        // cout << p2.x << p2.y << endl;
        // cout << p3.x << p3.y << endl;

        if (p1.areEqual(p2) || p1.areEqual(p3) || p2.areEqual(p3))
          continue;

        flag = 1;
        double perimeter =
            p1.getDistance(p2) + p1.getDistance(p3) + p2.getDistance(p3);
        //      debug(p1.getDistance(p2));
        // debug(p1.getDistance(p3));
        // debug(p2.getDistance(p3));

        if (perimeter - ans > EPS)
          ans = perimeter;
      }
  if (!flag)
    cout << "no triangle";
  else
    cout << fixed << setprecision(10) << ans;
  return 0;
}
