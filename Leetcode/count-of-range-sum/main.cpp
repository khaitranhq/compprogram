#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

const int MAX_ARRAY_ELEMENT = 1e5 + 5;

struct FenwickTree {
  int tree[MAX_ARRAY_ELEMENT];

  void update(int index, int val) {
    while (index < MAX_ARRAY_ELEMENT) {
      tree[index] += val;
      index += (index & -index);
    }
  }

  int query(int index) {
    int sum = 0;
    while (index > 0) {
      sum += tree[index];
      index -= (index & -index);
    }
    return sum;
  }

  FenwickTree() { memset(tree, 0, sizeof(tree)); }
};

class Solution {
public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
      vector<int64_t> prefixes(1, 0);
    for (int i = 0; i < nums.size(); ++i)
      prefixes.push_back(prefixes.back() + nums[i]);

    sort(prefixes.begin(), prefixes.end());

    int ans = 0;
    FenwickTree fenwick;
    int64_t currentSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
      fenwick.update(lower_bound(prefixes.begin(), prefixes.end(), currentSum) -
                         prefixes.begin() + 1,
                     1);

      currentSum += nums[i];

      int lowerBoundaryPrefixIndex =
          lower_bound(prefixes.begin(), prefixes.end(), currentSum - upper) -
          prefixes.begin();
      int upperBoundaryPrefixIndex =
          upper_bound(prefixes.begin(), prefixes.end(), currentSum - lower) -
          prefixes.begin();

      ans += fenwick.query(upperBoundaryPrefixIndex) - fenwick.query(lowerBoundaryPrefixIndex);
    }
    return ans;
  }
};

void expected(string testDescription, vector<int> nums, int lower, int upper,
              int expect) {
  Solution s;
  int result = s.countRangeSum(nums, lower, upper);
  if (result == expect) {
    cout << "\033[1m" << "\033[32m" << "PASS: " << testDescription << "\033[0m"
         << "\033[0m" << endl;
  } else {
    cout << "\033[1m" << "\033[31m" << "FAIL: " << testDescription << "\033[0m"
         << "\033[0m" << endl;
    cout << "-----------------------------" << endl;
    cout << "result: " << result << endl;
    cout << "-----------------------------" << endl;
    cout << "expected: " << expect << endl;
    cout << "-----------------------------" << endl;
    exit(1);
  }
}

int main() {
  expected("Test 1", {-2, 5, -1}, -2, 2, 3);
  expected("Test 2", {0}, 0, 0, 1);
  expected("Test 3", {2147483647,-2147483648,-1,0}, -1, 0, 4);
  expected("Test 4", {1, 4, -2, 3, -4, 3, 0, -4, 4}, 3, 6, 16);
  expected("Test 5", {1, 4, -2}, 3, 6, 3);
  return 0;
}

// prefix[j] - prefix[i - 1] >= lower
// prefix[j] - prefix[i - 1] <= upper
// => prefix[j] - upper <= prefix[i - 1] <= prefix[j] - lower
