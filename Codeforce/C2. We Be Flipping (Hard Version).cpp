https://codeforces.com/contest/2229/problem/C2

## C2. We Be Flipping (Hard Version)
* The main trick is to take inspiration from c1. From c1, we know that it is possible to turn the entire array into negative, so applying this idea we can choose a positive number and convert all number before it to negative and then inverting from that particular number. 
* Then use prefix and suffix sum to find the best idx
