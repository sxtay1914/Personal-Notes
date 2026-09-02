# An overview 
* Built using Springboot Webflux. It centralises JWT authentication, database-driven route handling, distributed rate-limiting, HTTP proxying, envoy as a sidecar for downstream services (circuit breaker and retries delegated to envoy).
* Routes and rate limits can be configured in the database. Lua script is used for atomic operations in Redis. Observability is provided by prometheus and grafana. For testing, I used Testcontainers and Wiremocks so the tests are not dependent on external dependencies.

 ### Architecture
  Client
    │
    ▼
  Spring WebFlux Gateway
    ├─ CorrelationIdFilter
    ├─ JwtFilter ───────────────► JWKS/Auth server
    ├─ RateLimiterFilter
    │    ├─ RoutingService ─────► PostgreSQL
    │    └─ RateLimiterService ─► Redis + Lua
    └─ RouteHandler/WebClient
               │
               ▼
             Envoy
               │
               ▼
        Downstream service

  Actuator ─► Prometheus ─► Grafana

# Possible questions
* Why WebFlux? Most works are network I/O, improve concurrency with fewer waiting threads.
* Why LUA? batch Redis transactions into one atomic operations, prevent race condition
* What makes HTTP proxy transparent? preserve important headers, body, query param and then we will remove security sensitive headers and hop-by-hop headers
* Main bottlenecks? per request db and redis call, buffering body into bytes[] array
* What fails closed? failed JWT auth, Auth server not starting and Redis not available. 
