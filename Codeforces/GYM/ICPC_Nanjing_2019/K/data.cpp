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

struct Point {
  double x, y;

  Point() {}
  Point(double x, double y) : x(x), y(y) {}
};

const pii edges[] = {{0, 1}, {0, 2}, {1, 2}};
const double EPS = 1e-7;

double getArea(Point A, Point B, Point C) {
  double area = ((B.x - A.x) * (C.y - B.y) - (C.x - B.x) * (B.y - A.y)) / 2;
  return area;
}

double crossProduct(Point A, Point B, Point C) { // x-product of BA and BC
  double xu = A.x - B.x;
  double yu = A.y - B.y;

  double xv = C.x - B.x;
  double yv = C.y - B.y;

  return xu * yv - xv * yu;
}

bool checkPointInsideSegment(Point A, Point B,
                             Point p) { // Check p is inside AB or not
  return fabs(crossProduct(A, p, B) - 0) <= EPS;
}

Point getBestPoint(vector<Point> trianglePoints, Point P, int refEdgeIndex,
                   int edgeIndex) {
  Point pL = trianglePoints[edges[edgeIndex].first],
        pR = trianglePoints[edges[edgeIndex].second];
  for (int i = 1; i <= 200; ++i) {
  }
}

void solve(vector<Point> trianglePoints, Point P) {
  int refEdgeIndex = -1; // Index of edge which  contain P
  for (int i = 0; i < 3; ++i)
    if (checkPointInsideSegment(trianglePoints[edges[i].first],
                                trianglePoints[edges[i].second], P))
      refEdgeIndex = i;

  if (refEdgeIndex == -1) {
    cout << -1;
    return;
  }

  double S = getArea(trianglePoints[0], trianglePoints[1], trianglePoints[2]);

  for (int i = 0; i < 3; ++i)
    if (i != refEdgeIndex) {
      int commonPoint = (edges[i].first == edges[refEdgeIndex].first ||
                         edges[i].first == edges[refEdgeIndex].second)
                            ? edges[i].first
                            : edges[i].second;
    }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int x1, y1, x2, y2, x3, y3, px, py;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &px, &py);

    vector<Point> trianglePoints;
    trianglePoints.push_back(Point(x1, y1));
    trianglePoints.push_back(Point(x2, y2));
    trianglePoints.push_back(Point(x3, y3));
    solve(trianglePoints, Point(px, py));
  }
  return 0;
}
