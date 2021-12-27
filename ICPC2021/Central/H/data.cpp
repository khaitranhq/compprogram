#include <bits/stdc++.h>

#define center adfadfsaf
#define radius asdfasdfas
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

const float EPS = 1e-9;

float pow2(float x) { return x * x; }

struct Point {
  float x, y;

  Point() {}
  Point(const Point &other) : x(other.x), y(other.y) {}
  Point(float x, float y) : x(x), y(y) {}

  float getLength(Point other) {
    return sqrt((pow2(x - other.x) + pow2(y - other.y)));
  }
};

struct Line {
  float a, b, c;

  Line(Point P, Point Q) {
    a = P.y - Q.y;
    b = Q.x - P.x;
    c = -a * P.x - b * P.y;
  }
};

struct Circle {
  Point center;
  float radius;

  Circle(const Point &center, float radius) : center(center), radius(radius) {}

  vector<Point> findIntersecLine(Point p1, Point p2) {
    vector<Point> points;

    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;

    float A = pow2(dx) + pow2(dy);
    float B = 2 * (dx * (p1.x - center.x) + dy * (p1.y - center.y));
    float C = (p1.x - center.x) * (p1.x - center.x) +
              (p1.y - center.y) * (p1.y - center.y) - radius * radius;

    float detla = B * B - 4 * A * C;
    if (A <= EPS || detla < 0)
      return points;

    float t = -B / 2 * A;
    if (detla == 0) {
      points.push_back(Point(p1.x + t * dx, p1.y + t * dy));
      return points;
    }

    t = (-B + sqrt(detla)) / (2 * A);
    points.push_back(Point(p1.x + t * dx, p1.y + t * dy));

    t = (-B - sqrt(detla)) / (2 * A);
    points.push_back(Point(p1.x + t * dx, p1.y + t * dy));
    return points;
  }

  float getArea() { return 2 * acos(0) * pow2(radius); }

  float getAreaOfArc(Point A, Point B) { // A and B on circle
    float c = A.getLength(B);

    float gamma = asin(c / (2 * radius));

    return gamma * 0.5 * pow2(radius);
  }
};

struct Triangle {
  Point A, B, C;

  Triangle(Point A, Point B, Point C) : A(A), B(B), C(C) {}

  float getArea() {
    float area =  abs((B.x - A.x) * (C.y - B.y) - (C.x - B.x) * (B.y - A.y) / 2);
    return area;
  }
};

int main() {
/*   freopen("data.inp", "r", stdin); */
  /* freopen("data.out", "w", stdout); */

  Point A, B, C;
  scanf("%f%f%f%f%f%f", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);

  float R;
  scanf("%f", &R);

  float per;
  scanf("%f", &per);

  Line AB(A, B);
  Circle cir(C, R);

  vector<Point> intersects = cir.findIntersecLine(A, B);
  Triangle triangle(A, B, C);

  if (intersects.size() < 2)
    cout << "NO";
  else {
    float ans =
        cir.getAreaOfArc(intersects[0], intersects[1]) - triangle.getArea();
    debug(ans)

    float cirArea = cir.getArea();
    if (abs(ans / cirArea - per / 100) <= (float)5 / 100)
      cout << "YES";
    else
      cout << "NO";
  }
  cout << endl;
  return 0;
}
