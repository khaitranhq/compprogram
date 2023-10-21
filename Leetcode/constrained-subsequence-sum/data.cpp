#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int constrainedSubsetSum(vector<int> &nums, int k) {
    vector<int> dp;

    priority_queue<pair<int, int>> pq;

    dp.push_back(nums[0]);
    pq.push({dp[0], 0});
    int result = dp[0];
    for (int i = 1; i < nums.size(); ++i) {
      while (i - pq.top().second > k)
        pq.pop();

      dp.push_back(nums[i] + max(0, pq.top().first));
      pq.push({dp.back(), i});
      result = max(result, dp.back());
    }
    return result;
  }
};

int main() {
  freopen("data.inp", "r", stdin);
  freopen("data.out", "w", stdout);

  int n, k;
  vector<int> nums;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    nums.push_back(x);
  }
  cin >> k;

  Solution solution;
  cout << solution.constrainedSubsetSum(nums, k);
  return 0;
}
