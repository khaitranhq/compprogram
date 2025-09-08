#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int LOG_LEVEL = 0; // 0: for submit, 1: for debug

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int l = 0, r = nums1.size();
    while (l <= r) {
      int mid1 = (l + r) / 2;
      int mid2 = (nums1.size() + nums2.size() + 1) / 2 - mid1;

      int max1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
      int min1 = mid1 == nums1.size() ? INT_MAX : nums1[mid1];
      int max2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
      int min2 = mid2 == nums2.size() ? INT_MAX : nums2[mid2];

      if (max1 <= min2 && max2 <= min1) {
        if ((nums1.size() + nums2.size()) % 2 == 0) {
          return (max(max1, max2) + min(min1, min2)) / 2.0;
        } else {
          return max(max1, max2);
        }
      } else if (min1 > min2) {
        r = mid1 - 1;
      } else {
        l = mid1 + 1;
      }
    }
    return 0;
  }
};

void log(string message) {
  if (LOG_LEVEL == 1) {
    cout << message << endl;
  }
}

void expect(string testCase, vector<int> inputNums1, vector<int> inputNums2,
            double expected) {
  Solution s;
  double result = s.findMedianSortedArrays(inputNums1, inputNums2);

  if (result == expected) {
    cout << "\033[1m"
         << "\033[32m"
         << "PASS: " << testCase << "\033[0m"
         << "\033[0m" << endl;
  } else {
    cout << "\033[1m"
         << "\033[31m"
         << "FAIL: " << testCase << "\033[0m"
         << "\033[0m" << endl;
    cout << "-----------------------------" << endl;

    cout << "Result: " << result << endl;

    cout << "Expected: " << expected << endl;
    exit(1);
  }
}

int main() {
  expect("Example 1", vector<int>{1, 3}, vector<int>{2}, 2.0);
  expect("Example 2", vector<int>{1, 2}, vector<int>{3, 4}, 2.5);
  expect("Example 3", vector<int>{}, vector<int>{1}, 1.0);
  return 0;
}
