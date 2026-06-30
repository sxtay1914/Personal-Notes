Chapter 4: Storage and retrieval

## Engineering principle: Optimise for the common case, not every case

## Log-based storage:
* When is it useful? updating, because append-only
* When is it not useful? reading, has to scan the whole file
    * How do you speed up reading? use index
        * Tradeoff of index: increases write overhead, consume additional disk space                                                                                                                                                                      

Tradeoffs:
1. didn’t free up disk space
2. can only be implemented in memory, hard to do on disk —> slow restart because need to rebuild the hashmap on every startup
3. range queries are inefficient
——————
key: byte offset
——————

## SSTable file format
What is it? the keys are sorted and exists only once

How does it able to store in memory: group key-value pair groups into blocks and then store the first key of the block in the index

Tradeoffs:
1. didn’t free up disk space
2. range queries are inefficient
3. write became slower because,

Problem is too slow to write, so how to solve this?
* Use LSM Tree
    1. store in ordered data structure like red-black tree, trie (aka memtable)
    2. when memtable > threshold, store as SSTable
    3. from time to time, perform merging and compaction (to prevent from reading through many segments)

How to delete to free up disk space?
* use tombstone record. Once the tombstone is merged into the oldest segment it can be dropped


Why are B-Trees popular?
What tradeoff was accepted?
What became slower?
When not to use?
