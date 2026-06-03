https://codeforces.com/contest/2229/problem/D
## D. Me When Median Problem
* Key idea is converting the arr to 0s and 1s, and finding the diff = cnt1 - cnt0, diff > 0
* then use binary search to find the ans

## Why convert to 0s and 1s
* easier manipulation
* if number of pairs of 1s greater than 0s
* blocks of 0,0 and 0,1 form one group and can be reduced to one 0,0 in between 1s

TC: O(NlogN) but because N = 1e9 it becomes O(N)

'''
For a candidate median x, forget the actual numbers and only remember whether each value is above or below x. The problem becomes a battle between "good" positions (both values ≥ x) and "bad" blocks (contiguous regions where neither value is ≥ x). If the good positions outnumber the bad blocks, then x is achievable. Since this condition is monotonic, binary search the largest valid x.
''' GPT suggested takeaway
