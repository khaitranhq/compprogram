#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define DEBUG(x) cout << #x << ": " << x << endl
#define DEBUGVI(x)                                                             \
  for (auto i : x)                                                             \
    cout << i << " ";
#define DEBUGVVI(x)                                                            \
  for (auto i : x) {                                                           \
    DEBUGVI(i);                                                                \
    cout << endl;                                                              \
  }

using namespace std;

typedef vector<vector<int>> vvi;

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    vector<Rectangle> rectangles;
    for (auto building : buildings) {
      rectangles.push_back(Rectangle(building[0], building[1], building[2]));
    }

    vector<bool> isRectangleActive(rectangles.size(), true);

    vector<XLine> xLines;
    for (int i = 0; i < rectangles.size(); ++i) {
      xLines.push_back(XLine(rectangles[i].leftX, i, false));
      xLines.push_back(XLine(rectangles[i].rightX, i, true));
    }
    sort(xLines.begin(), xLines.end());

    int currentValue = 0;
    vector<vector<int>> result;
    priority_queue<pair<int, int>> pq;
    pq.push({0, -1});

    for (int i = 0; i < xLines.size(); ++i) {
      XLine xLine = xLines[i];

      if (!xLine.isRight)
        pq.push(
            {rectangles[xLine.rectangleIndex].height, xLine.rectangleIndex});


      if (xLine.isRight)
        isRectangleActive[xLine.rectangleIndex] = false;

      if (i + 1 < xLines.size() && xLines[i + 1].x == xLine.x)
        continue;

      while (pq.size() && pq.top().second >= 0 &&
             !isRectangleActive[pq.top().second])
        pq.pop();

      if (pq.size() > 0) {
        pair<int, int> topHeight = pq.top();

        if (topHeight.first != currentValue) {
          result.push_back({xLine.x, topHeight.first});
          currentValue = topHeight.first;
        }
      }
    }

    return result;
  }

private:
  struct XLine {
    int x;
    int rectangleIndex;
    bool isRight;

    XLine(int x, int index, bool isRight)
        : x(x), rectangleIndex(index), isRight(isRight) {}

    bool operator<(const XLine &other) const { return x < other.x; }
  };

  struct Rectangle {
    int leftX;
    int rightX;
    int height;

    Rectangle(int leftX, int rightX, int height)
        : leftX(leftX), rightX(rightX), height(height) {}
  };
};

void expect(string test, vvi input, vvi expected) {
  Solution s;
  vvi result = s.getSkyline(input);
  if (result == expected) {
    cout << "\033[1m" << "\033[32m" << "PASS: " << test << "\033[0m"
         << "\033[0m" << endl;
  } else {
    cout << "\033[1m" << "\033[31m" << "FAIL: " << test << "\033[0m"
         << "\033[0m" << endl;
    cout << "-----------------------------" << endl;
    cout << "result: " << endl;
    DEBUGVVI(result);
    cout << "-----------------------------" << endl;
    cout << "expected: " << endl;
    DEBUGVVI(expected);
    cout << "-----------------------------" << endl;
    exit(1);
  }
}

int main() {
  vvi input;
  vvi ans;

  input = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  ans = {{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}};
  expect("Test 1", input, ans);

  input = {{0, 2, 3}, {2, 5, 3}};
  ans = {{0, 3}, {5, 0}};
  expect("Test 2", input, ans);

  input = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}};
  ans = {{2, 10}, {3, 15}, {7, 12}, {12, 0}};
  expect("Test 3", input, ans);
  return 0;
}
