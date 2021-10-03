# Codeforces Round 479
## Problems
https://codeforces.com/problemset
## Solutions
### F. Consecutive Subsequence
* Find length of longest consecutive subsequence
  * Let dp[x] be the length of longest consecutive subsequence with the last element is x 
  ```
  3 5 4 2 3
  dp[4] = 2
  dp[2] = 1
  dp[3] = 2
  ```
  * Iterate over all elemments of input array, update dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1)
  * The largest value of dp[a[i]] is the answer
* Find longest consecutive subsequence 
  * With the value of a[i] which dp[a[i]] is the largest, we can iterate in reverse and restore subsequence
