Chapter 1: Trade-offs in System architecture

## 2 types of systems (compute-intensive system & data-intensive system):
* both need diff requirements. Compute-intensive need parallelising computation. Data-intensive system need ensure consistency and availability

## Meaning of transaction: group of reads and writes that together form a logical unit 

##Type of database access: 
* OLTP (Online transaction process) (sql)
* OLAP (Online analytical process) (sql) 
    * OLAP is in data warehouse

## What is data lake
* store files dont need to have specific format/schema

## What is difference btw system of records and derived data sys
* system of records: hold the authoritative version of records, single source of truth
* derived: as implied by its name, derived from other sources

## When to self-host, when to store on cloud?
* predictable load, have expertise
* else if load is not predictable and most of the time the computers are idle then use cloud

## What is object store?
* store data as flexible unit, instead of rigid file blocks

**Large file: use object store**
**small file: use db**

## Elasticity means: 
* system can scale up or down
