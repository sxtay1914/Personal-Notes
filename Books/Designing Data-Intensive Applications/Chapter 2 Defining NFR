Chapter 2: Defining Nonfunctional Requirements

## Case Study:
* Initial suggestion: polling isn’t sensible in large scale system: imagine 10 million users are active at any given moment, and polling happens every 5 sec, this mean 2 mil req/s, each user has around 200 followers, so this will mean 400 mil req/s 
* Improvements:
    * Users subscribe, server push changes when there is any update
    * pre-computation & caching: materialisation
        * Speed up reads but slow down writes

## Response time & throughput
* the higher the throughput, the slower the response time. If max throughput is reached, more req will be queued => if waiting time is too large, may request timeout, clients will retry (retry storm), this will cause even more requests to be queued => metastable failure


## Measuring response time
**average, percentile and median**
1. average: good for estimating throughput limits
2. percentiles: able to know the percentage of clients experiencing limit
Is tail latency important?
* customers with slowest request have most data, most valuable customer 
￼
## parallel systems are bottlenecked by the slowest backend calls => tail latency amplification (high proportion of users end up being slow)

## Reliability 
* What? able to function properly even when things go wrong

## fault & failure 
* fault: part of sys fails
* failure: whole system stop providing the required service
**Error handling is very important**
* How to improve confidence in fault-tolerant mechanisms: chaos engineering which is to manually inject faults

## Improve fault tolerance
* Focus less on increasing uptime of a single machine but instead focuses more on increasing availability
* temporary outage is tolerable but losing data permanently is not

## Scalability
**Load, resource & performance**
* factors to consider:
    * read to write ratios
    * cache hit
    * number of items per users
    * avg cases
    * extreme cases
* no. of req isnt the only factor to scaling. System may have same no. of req but system with more data will require greater resource to handle write req.

## Shared-Memory, Shared-Disk, and Shared-Nothing Architectures
* vertical scaling:  more CPUs, more RAM & more disk space
* shared-memory: threads & processes share the same memory
* shared-disk: all servers can read & write to same data
* share-nothing: distributed sys with multiple nodes

## Making code maintainable:
* Most important keeping code simple
