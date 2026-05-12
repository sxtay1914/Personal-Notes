## B. Alternating String
* Initially I think that if there exists a sequence of same letters with length >= 3, then it will be No, but it turns out that there is not a case because of abbb. 
* Then I think in the direction of number of violations in the string, this is in fact in the right direction but i still keep the length constraint

### Solution
* As long as there is count of pairs of same number > 2, then it is NO else YES

### What did I learn?
* can try to formulate the question differently 
* think how does the operation causes changes. Like in this case one operation can invert at most two 1's. (Eg. 101 -> 000) 
