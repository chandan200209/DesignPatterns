/*
Facade design pattern -
1. here we have a much complicated classes subsystem - which focuses on doing one particular thing
as it is too complex, it is quite cumbersome for client to handle it
that's why, we have a Facade class in between, which is just like 'a gateway'.
2. it decouples client from complex subsystem.
3. principle of least knowledge

example use-case =>
a computer booting up, at that time, we requires many classes like CPU, Memory, SSD, BIOS, PowerSystem, CoolingSystem and OS, but for users, it is simply like pressing the power button only.
we have a Facade class here, with only one method startComputer().

Principle of least knowledge - talk only with your immediate friends
eg., A -> B -> C (all are classes, and they are dependent as shown here.)
=> A has B and B has C.
=> A should not call methods of C.
we want lesser interactions between classes, to make it loosely coupled.

Rules :
Take any object, now from any method in that object, principle tells you to invoke only methods that belongs to :
i) the object itself
ii) the object passed in as a parameter to the method
iii) any object that method creates
iv) any object with 'has-a' relationship

standard definition - facade pattern provides a simplified, unified interface to a set of complex subsystem. it hides the complexity of the system and exposes only what is necessary.

difference between facade and adapter - their intents are different
facade - hides the complexity
adapter - to make the interaction between completely different interfaces

real life use-cases ->
game engines - unity, unreal
they have complex subsystem with responsibilities like assets loading, memory management, physics engine
*/