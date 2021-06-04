# KQUERY
URL Problem [here](https://oj.vnoi.info/problem/kquery)
## Tag
* `BIT` or `IT`
## Solution
This problem, I used the `offline processing technique`
* Sort query following decrease of `k`
* Have vector store value and index of initial array, let's sort it.
* For each query, we will increase node's positions which have value (following the index) greater than `k` of query up to 1.
* Finnaly, get result from left and right postions. This work is easy to done`