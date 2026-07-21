# Chapter 5: Data formats

## Old and new data formats can coexist in the system due to 2 reasons:
1. server rolling upgrade
2. client doesn’t update in time

## Compatibility directions:
1. forward compatibility 
    * ensure older code able to read newer code
2. backward compatibility
    * vice versa

## Forward compatibility is harder:
* Why?
    * old code needs to be written defensively for new data that it has never seen before
    * data can be lost if newer data has extra field and the old data does not preserve the old data

## Language specific encoding
* fix to one language
* security issues: not only data is encoded but also the class is encoded. So if the byte stream is controlled, classes maybe instantiated and chained together in a way that harms the system
* no versioning
* inefficient

## Binary encoding for JSON/XML
Adv:
1. save space a little and perhaps speed up parsing speed
2. Schemaless so need to include object field names and types
Dis:
1. loss of human readability 

## What is protobuf? (schema + encoding)
* it is a binary encoding library
* schema & uses tag number 
* generate code that implements the schema in different languages —> language agnostic

## What is a varint?
* smaller number uses less bytes and larger number uses more
* for this to work need a way to signal whether there are more bytes coming and MSB of each bytes come into play

## How does protobuf enforce forward compatibility?
* if bytes with unknown tag number appears, skip it
## How about backward compatibility? 
* tag number still defines the particular field no. 

## Avro
* doesn’t even have datatype encoded, no tags
* uses both writer schema and reader schema for decoding. If a field exists in writer schema but not in reader, then it is omitted. If a field exists in reader but not writer, then it will be given default values

## How does Avro ensure forward and backward compatibility?
* by ensure that fields have default values

## What is Avro good for?
* Used for dynamically generated schemas, the reason being is that it doesn’t have to tag number
* so how does it make it good? it doesn’t have to care about previous changes

## Dataflow through databases
* both old and new instances can access the db 
* written by new code and read by old code, forward compatibility is needed

## Data-outlives-code
* one db may contain different versions of data
* ways to solve this
    * update to new schema, but best effort and asynchronously because operation is exp
    * add new col with null to old data

## Archiving data 
* snapshots of data are taken at different times, so the data are encoded with different versions of schema
* while reading the data, it is basically free to encode data in new schema

## Dataflow through REST and RPC
* REST: specify the resource using url, negotiate the content type, cache control, authentication
* IDL <-> code: Interface definition language gives API specs 

## Why RPC is bad?
* calling function locally and over the network is different from calling over the network
    * Why?
        * msg loss, timeout —> so outcome can be: pass, fail, unknown
        * so lets say we retry —> we have to ensure idempotency
        * high latency
        * cannot pass ref, must encode data, problematic when data is mutable and large
        * different programming languages

## Load balancing & service discovery
## DNS?
* DNS caches at different levels and thus update propagation is slow —> stale cache issues
## Service discovery system
* Centralised, service registers the host and port it is listening on
* How is this better than DNS? IP changes frequently 
## Service mesh
* use by microservices 
* instead of having retries, load balancing all in application code, deploy as a sidecar proxy alongside the service

## Workflows
* workflows made up of tasks
* executed using workflow engine (orchestrator + executor)

### Durable execution
* transaction-ability 
Dis: Idempotent api required + code change is brittle 


## Event-driven architecture
* event broker holds the message —> actor

### Why need event broker?
1. buffer in case of service overload
2. resend msg in case of service failure
3. no need for service discovery
4. decouple sender from receiver
5. send to multiple receivers

## Actor model
* concurrency model
