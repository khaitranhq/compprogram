# CodeCraft-19 and Codeforces Round #537 (Div. 2)
## Problems
https://codeforces.com/problemset
## Solutions
### C. Creative Snap
* Use divide and conquer technique
* For each recursive time, we will find min value of answer of 2 operations
  * Process with entire array
    * If all of elements are empty -> answer is A. If this case was met, we don't need to consider the other operation
    * Otherwise, answer is B * n * l
  * Divide into 2 subarray, process 2 subarray separately
