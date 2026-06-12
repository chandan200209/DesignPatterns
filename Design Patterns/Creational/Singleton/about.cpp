/*
in singleton design pattern, the singleton class allows only one object to instantiate, if we try to do another, it will only return the first.

two types of memory :
i) stack memory - used to store primitive data types, ie., int, char, long, etc.
ii) heap memory - used to store non-primitive data types, ie, objects of custom classes

A* a = new A(); // here, during A(), a constructor of that class is called
constructor is called automatically when an object is instantiated.
used to provide initial values to it

steps :
1. space for class is allocated, the space will be equal to the unit space of each variable in that class
2. constructor will be called, if not avaliable, then default
3. a pointer (*a) located in stack memory will be assigned to the allocated heap memory

static methods belongs to the class, not objects.
they are same for each objects and can be called upon by any object using class's name.

conclusion :-
1. create a private constructor
2. create a static instance (getInstance) which returns the same instance every time

real life use case :
i) logging system - time based logs of any application, when which activity is done (using logger libraries or we can create our own custom)
ii) database connection - it is an expensive operation, hence, creation of one instance only is recommended. that one instance is being shared by all applications.
iii) configuration manager - configuration files which are required by many services
API key is a configuration, stored in configuration file as a single source of truth to prevent many objects altering it

when not to use :
where we already knew that many instances are required, like in a game, for many players we require many instances

*/