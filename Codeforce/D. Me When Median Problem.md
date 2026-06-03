https://codeforces.com/contest/2229/problem/D
## D. Me When Median Problem
* Key idea is converting the arr to 0s and 1s, and finding the diff = cnt1 - cnt0, diff > 0
* then use binary search to find the ans

## Why convert to 0s and 1s
* easier manipulation
* if number of pairs of 1s greater than 0s
* blocks of 0,0 and 0,1 form one group and can be reduced to one 0,0 in between 1s

TC: O(NlogN) but because N = 1e9 it becomes O(N)
