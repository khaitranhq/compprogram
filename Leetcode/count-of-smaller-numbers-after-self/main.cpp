#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_ARRAY = 1e5;
const int MAX_NUM = 1e4;
struct FenwickTree {
  int tree[MAX_NUM * 2 + 5];
  int n;

  FenwickTree() {
    memset(tree, 0, sizeof(tree));
    n = 2 * MAX_NUM + 1;
  }

  void add(int x) {
    for (; x <= n; x += (x & (-x)))
      tree[x] += 1;
  }

  int query(int x) {
    int ans = 0;
    for (; x > 0; x -= (x & (-x)))
      ans += tree[x];
    return ans;
  }
};

class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    FenwickTree fenwick;
    vector<int> result(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; --i) {
      result[i] = fenwick.query(nums[i] + MAX_NUM);
      fenwick.add(nums[i] + MAX_NUM + 1);
    }
    return result;
  }
};

void expect(string test, vector<int> input, vector<int> expected) {
  Solution s;
  vector<int> result = s.countSmaller(input);
  if (result == expected) {
    cout << "\033[1m" << "\033[32m" << "PASS: " << test << "\033[0m"
         << "\033[0m" << endl;
  } else {
    cout << "\033[1m" << "\033[31m" << "FAIL: " << test << "\033[0m"
         << "\033[0m" << endl;
    cout << "-----------------------------" << endl;
    cout << "result: " << endl;
    for (auto x : result)
      cout << x << " ";
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "expected: " << endl;
    for (auto x : expected)
      cout << x << " ";
    cout << endl;
    cout << "-----------------------------" << endl;
    exit(1);
  }
}

int main() {
  vector<int> input;
  vector<int> output;

  input = {5, 2, 6, 1};
  output = {2, 1, 1, 0};
  expect("Test 1", input, output);

  input = {-1};
  output = {0};
  expect("Test 2", input, output);

  input = {-1, -1};
  output = {0, 0};
  expect("Test 3", input, output);
  return 0;
}
