## What is API gateway?
* a middleman between clients and backend services
* central software for managing APIs

### API gateway deployment patterns
* at top level to determine which cluster to send to (intercluster)
* withhin cluster to determine which kubernetes container to send to (intracluster)
* within the container (gateway for each services)

### Architecture
* intracluster
* intercluster
* before microservice

## What does it contain?
* **auth** & **rate-limiting** 
* analyse and take care of the backend outputs
* proxy server
* load-balancing
* protocol translation
* traffic management
* developer logging
