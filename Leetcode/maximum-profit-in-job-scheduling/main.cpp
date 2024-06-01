#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<pair<int, int>, int> Job;

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    vector<Job> jobs;
    for (int i = 0; i < startTime.size(); ++i) {
      jobs.push_back({{startTime[i], endTime[i]}, profit[i]});
    }
    sort(jobs.begin(), jobs.end());

    vector<Job>::iterator currentJobIter = jobs.end();
    maxDp[jobs.size()] = 0;
    for (int i = jobs.size() - 1; i >= 0; --i, --currentJobIter) {
      // cout << jobs[i].first.first << " " << jobs[i].first.second << endl;

      int firstSatisfidedIndex =
          lower_bound(
              currentJobIter, jobs.end(), jobs[i].first.second,
              [](Job a, int value) -> bool { return a.first.first < value; }) -
          jobs.begin();
      // cout << firstSatisfidedIndex << endl;

      dp[i] = jobs[i].second + maxDp[firstSatisfidedIndex];
      maxDp[i] = max(maxDp[i +  1], dp[i]);
      // cout << dp[i]<< endl; 
      // cout << maxDp[firstSatisfidedIndex] << endl;
      // cout << maxDp[i] << endl;
      // cout << endl;
    }
    return maxDp[0];
  }

private:
  static const int MAX = 5e4 + 5;
  int dp[MAX];
  int maxDp[MAX];
};

int main() {
  freopen("test/2.inp", "r", stdin);
  int n;
  cin >> n;

  vector<int> startTime(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> startTime[i];
  }

  vector<int> endTime(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> endTime[i];
  }

  vector<int> profit(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> profit[i];
  }

  Solution solution;
  cout << solution.jobScheduling(startTime, endTime, profit);
  return 0;
}
