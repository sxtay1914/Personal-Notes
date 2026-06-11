Chapter 3: Data Models & query languages

## Big idea

￼
## Tradeoffs + When to use 

### Document vs Relation
* Document has more flexible schema & more scalable
* OOP widely use today, need translation layer to convert to relational schema => ORM (Object-relational mapping) frameworks
* Relation doesn’t capture one-to-many relationship that well, need many relation tables
* Document model has better locality

## ORM tradeoff
### Bad: 
* ORM is complex, cant really hide the diff between obj and relational models, end up still have to think in both models
* ORM mapping may not be efficient. 
* N+1 query problem, for problems that can be solved using join in relational need more query to get extra info
### Good:
* helps in caching res
* reduce boilerplate to map 
* helps in administrative tasks like schema migration

##Tradeoffs of Normalisation:
* store the data only in one place and refer to it using id
### Advantage of normalisation:
1. less redundancy
2. more read/write operations needed 
3. inconsistency record risk
### Disadvantage:
1. need join to get relevant data

## Should we normalise or denormalise?
1. normalise makes it easier to update but harder to read because need join
2. denormalise makes it harder to update but easier to read
OLTP -> normalise, analytical -> denormalise


## Social media post timeline: ### Denormalise or normalise: 
* denormalise would mean faster read but then harder update
* posts change frequently, denormalise will be bad
* can solve the read problem using caching, updating is more exp than read

## Many-to-many relationship
* normalised data is better to represent 
* relies on secondary indexes, have a junction table that connects both entities
