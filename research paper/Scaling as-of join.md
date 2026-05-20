## Reading ASOF join blog
* v1: sorting + two-pointer approach 
    * Problem: string comparison is slow because need to compare char by char
* v2: hashing —> partitioning & parallelism
    * Problem: data skew 
* v3: batching  —> within batch perform v2 & all batches running on separate threads so there can be good utilisation of core resources

## Why hash-partition doesn’t scale?
* data skew, some workers a lot of load, some are idle
* some times key is not given in real life

## To scale:
* use sampling & range partition
    * sampling is to partition data according to distribution
    * partition into n-1 workers, each strictly smaller
* carry the max over to the next working instance, because only need the max

