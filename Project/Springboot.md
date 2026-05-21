### Why WebClient over RestTemplate?
WebCient is non-blocking, Rest is blocking

## What is @Bean
* Register the project so that Spring can create, manage and inject it anytime where appropriate
* Becuz normally need to create the object and manage it manually, but using this Spring helps to manage

# Connection pool
* JDBC: api to connect to db

## HikariCP
* cp for db 

## ConnectionProvider 
* cp for httpclient 

* Reasoning for choosing 500 as max connections?
    * not too big as to overwhelm the resources and not too small as to cause queue to be constantly full
* Reasoning for why maxLifeTime should be greater than maxIdleTime?
    * maxIdleTime is duration an unused connection is set alive
    * maxLifeTime is duration a connection is alive
    * so if lifeTime < idleTime, connection is closed and then maxIdleTime will timeout so then idleTime will be useless

## PostgresSQL 
* store request path, routing dest and http method
* request in, route to dest, response hit gateway, gateway respond to client

## Entity class  && repo interface 
** Define schema —>
* entity class: defines the data
* repo interface: defines the methods to query db 


## How WebClient gets the response?
* .get() —> .uri() —> .retrieve() —> .bodyToFlux 
    * Lazy, do nothing before receiving res
