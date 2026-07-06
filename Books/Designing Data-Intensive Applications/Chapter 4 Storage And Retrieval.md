# Chapter 4: Storage and retrieval

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

How to prevent searching through all segments?
1. hash(key): 12 bit number
2. 12 bit number —> 3 indexes
3. mark as 1
How to check whether exist? hash(key) then check whether all indexes = 1
* will have false positive but its ok because no harm is done
* cannot have false negative

Different methods of compaction: 
1. size-tiered compaction: wait until sst become similar size then merge together into one large sst
    * trading temporary memory disk storage and read speed for very fast write speed
2. levelled compaction: group SST by levels, if total storage(SST) > threshold, then merge one or more table with level i+1
    * trading write speed for read speed because fewer SST table



## B-Tree
￼

What is B-Tree?
* balanced tree, has O(logN) depth
* mutable, key-value similar to LSM tree
* split into fixed-size pages that contain key and references, leaf page contains the data

Comparing B-tree & LSM:
* Generally B-tree is faster than LSM because it only has a few level of pages to check. However because of compaction strategy and Bloom filters in LSM, LSM is also pretty fast
* Range queries faster on B-tree, because already sorted. LSM is also sorted but need to perform parallel checking on all segments and merge them together.
* Write is better in LSM because of sequential writes, B-trees are random writes. However, when there is a spike in writes, LSM will have higher latency when its memtable is full. 
    * What causes the memtable to be full? memtable is not written to the disk quickly. 

SSD:
**Store in pages, delete in blocks** (Block contain multiple pages) 
* writes in pages, but delete in blocks
* so some blocks contain valid & invalid pages mixed together. 
* move the valid page to other blocks and delete the block containing the invalid blocks 
Sequential writes better for garbage collection

Write Amplification
* total number of bytes written to disk / number of bytes intended to be written
* LSM tree lower write amplification compared to B-Tree because B tree needs to write whole page while modifying whereas LSM tree don’t
Effect of write amplification: 
1. slower writes
2. higher wear on SSD

Fragmentation: 
B-Tree has higher fragmentation because of random writes, whereas LSM tree has lesser because of compaction and sequential write

Secondary index:
1. sec index : ref primary key 
2. sec index : data location (data store in heap files)
Types of index:
1. cluster index: which contains all data (referring to the primary index)
2. convering index: contains some of the columns (some queries dont need to query table)

## Significance of in-memory store:
* its good not because there is little round trip to the disk, but because there is no conversion from memory store —> disk storage 


# Data storage for analytics
## What is difference between OLTP and OLAP?
* OLTP involves single records
* OLAP involves aggregation of large amount of data

## Query engine?
* convert sql queries into executions
## Storage format?
* determines how tables are stored as bytes 
## Table format?
* defines which data makes up the table
## Data catalog?
* defines which tables are in the db

How to reduce the amount of data loaded into memory?
## Column-oriented storage
* usually is row-oriented storage. So during query, if there are many columns the amount of data loaded will be a lot. Storing data column wise and only loading the necessary data from the columns will save a lot of space

## Column compression? 
    * store each distinct value in a column as bitmap, and only setting the bit if the row has it
Eg. distinct value: 5

### How to store efficiently?
    * use run-length encoding
Eg. 0 0 0 1 1 1 : 3 1s, 3 1s.

### Sorting on columns?
    * Why? faster query and better column compression using run-length encoding

### How to write to column-oriented store?
* write in bulk armortizes the cost of rewriting the columns 
1. small individual writes absorbed by an in-memory buffer
2. then merge with existing data and new columnar data is produced. (Obj storage best for this because modify in bulk) 

## Speed up not just by the amount of data loaded in but also by reducing CPU speed needed
Interpreter (Normal approach)	Query Compilation	Vectorised Processing
1. look at query plan	1. convert SQL queries —>  code --> machine code	1. process data column wise
2. decide which operators to use	2. faster processing per row even though still need to process every row	
3. do this for every row 		

How to further improve queries?
* use materialised aggregates known as data cubes

## Multidimensional and full-text indexes
* concatenated index

## How about querying geospatial data?
* convert 2d coordinate into single number
* divide the space and group nearby points together

## Full-text search?
* use key-value with inverted index
Eg. word: [documentID containing it]

## Vector Embeddings?
* types of vector embeddings?
    * flat indexes: store the index as it is but slow to measure the distance
    * inverted file indexes: use centroids to reduce the number of vectors to be compared
    * HNSW indexes: multiple layers. node represents the vector and edge represents the distance to other vectors. Each layer has increasing more nodes
￼
Why are B-Trees popular?
What tradeoff was accepted?

What became slower?
When not to use?
