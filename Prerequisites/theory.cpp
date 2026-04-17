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

indexing - fetching required data efficiently, type of data structures used, like, b tree,
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

UML diagrams - there are 14 diagrams in total.
7 static (structural) and 7 dynaminc (behavioural)
only 2 are main, rest are specific to the application
class diagram - structural
sequence diagram - behavioural

class diagram - i) class structure ii) associations/connections
class structure - access specifieres ->
    + public
    # protected
    - private

associations
i) class associations - inheritance (is-a relationship) filled arrow is used to denote inheritance
ii) object associations - a) simple association b) aggregation c) composition
all these three have a 'has-a' relationship, they are programmatically same

simple association -
empty arrow, strong line is used for simple association
eg. arjun lives in a house

aggregation -
diamond and strong line is used
diamond on the side of aggregator (container object)
eg. room has bed and chair

composition -
strongest form of relationship between two objects
individual objects do not exists here
filled diamond and strong line is used
filled diamond on the side of aggregator (container object)

how to represent this programatically
A{
    method1();
}
B{
    A *a; // reference
    B(){
        a = new A(); // initialize
    }
    method2();
}
main(){
    B *b = new B();
    b->method2();
    b->a->method1();
}

sequence diagram -
objects - shown as a box
lifeline - when the object is present or created in the application
activation bar - when the object is ready to sent or receive msg
messages - asynchronous - don't wait for response, synchronous - can't sent until response comes

for synchronous -
message as strong line + closed (filled) arrow
response as dashed line + closed (filled) arrow
for asynchronous -
message as strong line + open arrow

create message - when an object is being created
destroy message - when an object is being destroyed
lost message - point encircled by a circle
found message - same as lost message, but the source is unknown here.
alt - if/else condition
option - if condition only
loop - for/while loop
*/