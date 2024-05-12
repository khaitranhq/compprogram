#include <algorithm>
#include <cfloat>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
    vector<pair<double, double>> ratioQual;
    for (int i = 0; i < quality.size(); ++i) {
      ratioQual.push_back(
          {static_cast<double>(wage[i]) / quality[i], 1.f * quality[i]});
    }

    sort(ratioQual.begin(), ratioQual.end());

    double ans = DBL_MAX;

    priority_queue<double> pq;
    double currentSumQuality = 0;
    for (int i = 0; i < ratioQual.size(); ++i) {
      pq.push(ratioQual[i].second);
      currentSumQuality += ratioQual[i].second;

      if (pq.size() > k) {
        currentSumQuality -= pq.top();
        pq.pop();
      }

      if (pq.size() == k) {
        double totalWage = ratioQual[i].first * currentSumQuality;
        ans = min(ans, totalWage);
      }
    }

    return ans;
  }
};

int main() {
  // freopen("test/2.inp", "r", stdin);
  int n, k;
  cin >> n >> k;

  vector<int> quality;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    quality.push_back(x);
  }

  vector<int> wage;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    wage.push_back(x);
  }

  Solution solution;
  cout << fixed << setprecision(5)
       << solution.mincostToHireWorkers(quality, wage, k);
  return 0;
}
