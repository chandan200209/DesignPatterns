// problems that can occur cause of not using design patterns and solid principles
/*
maintainability - easily extensible, not much changes to do in code while integrating new features
readability - easy to comprehend by new devs
more chances of bugs - due to bad architecture of the codebase

design patterns are introduced by robert c. martin in 2000 research paper
SOLID design principles
S : Single Responsibility Principle (SRP)
O : Open/Close Principle (OCP)
L : Liskov Substitution Principle (LSP)
I : Interface Segregation Principle (ISP)
D : Dependency Inversion Principle (DIP)

1. single resposibility principle - a class should have only one reason to change, i.e., it should do only one thing
composition is extensively used to follow the SRP principle.

2. open close principle - a class should be open for extension but closed for modification
we should not  add new methods in already built classes
this ocp with be achieved using abstraction, inheritance and polymorphism
the classes that we will be modifying should become an abstract class, instead of concrete class

3. liskov subsitution principle - subclasses should be subsitutable for their base classes
the child classes should behave like parent classes, apart from inherting all the functionalities too.

inheritance ensures that subclasses always expand the features of base classes, not narrowing it.
class A - m1(), m2(), m3()
class B - m1(), m2(), m3(), m4(), m5()
for B -> A
it is always expanding its base class, hence it is subsitutable
expecting A means -> client has a random method, which is as follows
    randomMethod(A *a){
        a->m1();
        a->m2();
        a->m3();
    }
for lsp to follow, we can easily :
    randomMethod(A *a){
        a->m1();
        a->m2();
        a->m3();
    }
    A * a = new B();

there are some guidelines to follow :
1. signature rule - signature means i) method's name, ii) arguments, iii) return type
2. propterty rule
3. method rule

broad class - parent class - which aggregates a large number of responsibilities
narrow class - child class - which is modular and is for specific use-case

1. signature rule -
a) method argument rule
class Parent{
    void solve(string s){}
}
class Child{
    void solve(string s){} // here the argument should be string or broader object
}
eg. narrow -> DatabaseLogger
    broad -> Logger which consists of DatabaseLogger, FileLogger and ConsoleLogger

by default - c++ imposes signature rule strictly, which mean, we need to pass the same argument type in child classes, no other options we have.

b) return type rule -
covariance - the return type of the method of subclass can be narrower or equal.
because, eg., we have,
Animal *a = p-> function();
this states that, whatever is function() returning is getting assigned to 'a' of Animal.
now, it can handle, say, Dog, Cat etc, but can't handle Organism class return type.

c) exception rule -
exception - logic errors - invalid argument, out of range error
            runtime errors - overflow, bad allocation error
similar to the return type rule, the object of subclass can handle exceptions of either same or narrower
class
e.g., catch is looking for out of range error but the method thrown logic errors (which is superclass)

2. Property rule -
a) Class invariant rule -
any condition, fact or rule which is always true for any class
the object's data members must satisfy this condition from the moment it finishes construction until the moment it is destroyed.

what does that rule even mean ?
anything which we want the class and its object to follow
The Invariant: The size of the array must never be negative, and it must never exceed the capacity

the Child class should follow the parent's rule either exactly or can strengthens, but no weakening it.

b) history constraint - history can never be changed, ie, whatever the parent class has declared as state, the child will follow that state.
"If a parent class promises that something can never change, a child class isn't allowed to add a button that changes it."

difference between class invariant and history constraint -
class invariant checks if the data inside an object is valid at any single given moment
-> speed is always positive at any given instance of time
history constraint compares the old state to the new state
-> odometer always increase the reading

immutable class - that class which can't be inherited, hence, it won't be changed.
immutable methods - those methods won't be overridden.
'final' keyword is used to make them immutable
history constraint also ensures that, we should not make immutable types of classes or methods to mutable as declared by parent class, by any mistake. otherwise, the rule is broken.

3. method rule -
a) pre-condition - those conditions which must be followed before any method execution
the rule states that, the child class can either follow or weakens the precondition set by the parent class
e.g., parent class for ATM transaction requires PIN
child class eases out for either PIN or biometrics

parent class method - expecting number n >= 0 && n <=5
child class method - we have given condition check for n >= 0 && n <= 10
client is already aware of number between 0 and 5, so this weakened condition will not cause any problem.

b) post-condition - those conditions which must be satisfied after any method execution
this is just opposite of that of pre-condition rule
it states that, the child class can either has the same post condition as that of parent class or it can strengthens it

The Child class must deliver at least everything the Parent promised, if not more. It cannot slack off.
e.g., parent class - StandardPizzaMaker - 45 min delivery, warm pizza
child class - FastPizzaMaker - 25 min delivery, hot pizza with extra cheese

overall we have to look for these points in LSP - whether the child class is throwing exception, keeping the method empty or giving some hardcoded values, while inherting the parent class.
in those conditions, it wont be a good child class, thus violating LSP

4. interface segregation principle -
-> many client specific interfaces are better than one general purpose interface
-> this causes a problem that, many child classes that are inheriting have to implement/override the methods, even if they don't need them
-> client should not be forced to implement methods they don't need

eg., shape - i) 2d shape - a) square b) rectangle c) circle ( area() )
            ii) 3d shape - a) cube   b) sphere              ( area(), volume() )

5. dependency inversion principle -
high level module should not depend on low level module but rather both should depend on abstraction
they should not be interacting with each other, instead they should have an interface/abstract class between them

high level module - interacts with business logic in the application
low level module - (detailed implementation) interacts with the system like database tables, file system, external api, etc.

if open closed principle is the target, then dependency inversion principle is the solution
*/