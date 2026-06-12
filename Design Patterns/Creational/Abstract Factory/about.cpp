/*
why do we need it ?
in strategy pattern, the creation of objects is handled somewhere, but we are focussed more on calling the methods to get our desired output.
simply, the creational logic is abstracted

dependency injection -
the dependencies (Talkable, Walkable, Flyable) are injected in the dependent class (Robot)
the dependent class delegates its functionality to dependencies.

the aim of factory pattern is to separate business logic from the object creation logic
business logic is that, around which whole application is centered
it will be less complex if we separate out the two.

types of factory -
i) simple factory -> not a design pattern, but principle
ii) factory method -> is a design pattern
iii) abstract factory method -> is a design pattern

simple factory -
a factory class which decides which concrete class to instantiate
factory is something which creates objects
we have two options, either, we can implement our object creation logic in client code using the 'new' keyword, which in return gives us the object
or, we create a factory class which returns our desired object

factory method - now the factory class is also an abstract class, it has two or more factory classes
it is decided polymorphically, which then creates their own subsequent objects

defines an interface for creating objects but allows subclasses to decide which class to instantiate

abstract factory method - here we have more than one products, that too from more than one factories
standard definition -> provides an interface for creating families of related objects without specifying their concrete classes
*/