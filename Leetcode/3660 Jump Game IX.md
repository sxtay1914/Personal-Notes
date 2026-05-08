## 3660. Jump Game IX https://leetcode.com/problems/jump-game-ix/description/?envType=daily-question&envId=2026-05-07

### My initial approach:
* Did prefixMax and suffixMin approach. Then, perform binary search to look for the furthest min. 
### What is wrong with my approach:
* I didnt account for the fact that there maybe different routes that I can take to reach the max. Example (2, 3, 1) : 2 can first go to 1 and then go to 3.

### Model Solution:
* Still uses prefixMAx and suffixMin. The problem becomes sort of like a graph problem where we try to find routes. if two sections have a bridge between them, then just take the max of these 2 sections. So what constitutes a bridge: if max of r1 is less than min of r2, then there is a brige between r1 and r2 sections.

TC: O(N) 
SC: O(N)
