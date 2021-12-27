#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

struct Point {
  double x, y;

  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }

  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  double operator*(Point p) { return x * p.x + y * p.y; }
  Point operator*(double k) { return Point(x * k, y * k); }
};

void print(Point p) { cout << p.x << " " << p.y << "\n"; }

double dist(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int32_t main() {
/*   freopen("data.inp", "r", stdin); */
  /* freopen("data.ans", "w", stdout); */

  double xa, ya, xb, yb, xc, yc, r, p;
  cin >> xa >> ya >> xb >> yb >> xc >> yc >> r >> p;

  Point d(xa, ya);
  Point n(xb - xa, yb - ya);
  Point c(xc, yc);

  double A = n * n;
  double B = n * (d - c) * 2;
  double C = (d - c) * (d - c) - r * r;
  double delta = B * B - 4 * A * C;

  if (delta <= 0) {
    cout << "NO" << endl;
    return 0;
  }

  double tmp = sqrt(B * B - 4 * A * C);
  double x1 = (-B + tmp) / (2 * A);
  double x2 = (-B - tmp) / (2 * A);

  Point P1 = d + n * x1;
  Point P2 = d + n * x2;

  double PI = acos(-1.0);
  double w = dist(P1, P2);
  double alpha = asin(w / 2.0 / r);
  cerr << alpha << endl;
  double S = PI * r * r;
  cerr << cos(alpha) * r * w / 2.0 << endl;
  cerr << S * alpha / PI  << endl;
  double s = S * alpha / PI - cos(alpha) * r * w / 2.0;
  cerr << s << endl;
  double ans = abs(s / S * 100 - p);
  if (ans <= 5.0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
