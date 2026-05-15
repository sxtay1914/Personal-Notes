### C. Red-Black Pairs
* I couldnt think of the solution, but it turns out that it is a dp problem.

### Key idea
* * Try to find a common pattern. In this case it is the column. becuase there is only 2 ways that a 2x1 domino piece can be aligned: vertically or two horizontal piece stacked together. From here we can see that we just need to conside the "vertical" and the "horizontal" columns.
* * dp[c] = min(dp[c-1] + curr_cost, dp[c-2] + curr_cost, dp[i])
    
