/*
what is dsa ?
here, we have some 'isolated problems' and to solve them, we use different kinds of algorithms, like binary search, linear search

what is system design ?
pre-planning of the whole system before starting to code it, like, architecture, database, requirements, scalabilty, security, components.

topics included : horizontal and vertical scaling
vertical scaling - increasing the infrastructure of a single server
horizontal scaling - increasing the no. of servers

loadbalancing - distributing load/request on different servers

databases - sql, nosql, vector

indexing - fetching required data efficiently, type of data structures uded, like, b tree,
b+ tree.

sharding - allocating data to various instances of databases situated across the globe.

replica - maintaining multiple copies of data for durability, keeping it safe from data loss from accident losses.

CAP theorem - consistency, availability, and partition

rate limiter - make account of no. of request a user can send to the server in specified  time limit, eg, 100 req. every 15 minutes. Prevents server crashes.

cdn - content delivery network takes care of latency of the data being fetched. store the data at nearby servers to reduce the latency.

api design - graphql or rest api. prevent exploitation of the server by inducing authentication and authorization.

architecture of the system - monolithic, microservices, event driven, client server.

what is lld ?
complete applications build around multiple DSA concepts/algorithms
apart from algorithms, focus on objects/entities, relationships, data security, notifications/payments, millions of users accessing simultaneously, and so on, should also be there.

three pillars of lld -> scalability, maintainability, reusability
algorithms, features should not be tightly coupled.
eg., same notification/payment gateway can be used on multiple applications

what is hld ?
focuses on - tech stack, database, server scaling, cost optimization (budget)

application = hld + lld + dsa
hld -> system architecture
lld -> code structure
dsa -> tool used for lld

history of programming
machine language - binary
    disadvantages - prone to error, not scalable, highly tedious process

assembly language - dependant on hardware, use of mnemonics
    disadvantages - prone to error, not scalable, highly tedious process

procedural programming - functions, loops, blocks, if else, switches
    diadvantages - not for large scale applications, complex problems

object oriented programming - real world modelling, data security, scalable and reusable applications
objects interact with each other
object - characteristics, behavior
*/