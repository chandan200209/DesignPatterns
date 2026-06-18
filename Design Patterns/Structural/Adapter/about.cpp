/*
in adapter design pattern, we have two completely different interfaces/abstract classes, which do not communicate with each other
we often use third party libraries like payment gateway, notification system in our code, which generally have different kinds of written classes and methods.

to solve the dissimilarity :-
i) we can reserve a space in our code for the integration of these libraries (to call them from our code), but using this approach, our code is tightly coupled with these libraries
ii) using adapter design pattern

existing code <=> adapter <=> libraries
now, our existing code doesn't know about our libraries, it just uses an adapter to communicate and it then returns a value
in our example, we have, an 'is-a' relationship between IReports and XMLDataProviderAdapter and a 'has-a' relationship between XMLDataProviderAdaper and XMLDataProvider.
any client which expects an IReports can have XMLDataProviderAdapter passed on also, due to the reason that they has an 'is-a' relationship between them.
XMLDataProviderAdapter - adapter
XMLDataProvider - adaptee

standard definition -
adapter converts interface of a class into another interface that client expects. adapter lets classes work together that could'nt otherwise due to incompatible interfaces.

there are two kinds of adapters :
object adapters - uses composition
class adapters - uses inheritance (having multiple inheritance)

real life use-cases :
1. communication with third party vendors
2. modern application <-> adapter <-> legacy code
*/