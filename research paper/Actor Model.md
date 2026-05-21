## Actor Model
**Encapsulation can only be guaranteed by single thread**
* Why not OOP:
    * Encapsulation: making internal data not accessible to outside, expose only curated set of methods
    * problem: multiple threads may call the same methods => one way to synchronise is by using locks, however locks are expensive, blocking & introduces deadlock

## Take OS for example\
—> quite similar to networks
1. no shared memory (CPU cores pass msg to each other because they write to cache line which is local to each core) 
2.  no true call stack anymore (due to multi-thread, worker thread operate in a different call stack, if exception occurs, then will

## How does it work?
* actor passes around asynchronous msg instead of passing around thread of execution
* msg added to queue and processed asynchronously

## Components of model
* mailbox
* actor state
* execution env
* address

## How handle error
* if execution fails: send message saying that there is error back to the caller
* if actor fails: parent actor will handle
