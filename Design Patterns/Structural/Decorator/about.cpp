/*
decorator - providing additional functionalities at the run-time

without this, we were using inheritance, eg.,
Base Class -> method() -> cout<<"Hello";
Derived Class -> method() -> cout<<"Hello programmer";

if, Base *b = new Base() -> output -> Hello
if, Base *b = new Derived() -> output -> Hello programmer

then, why use Decorator - inheritance is bad; it causes classes explosion (too many classes), multiple hierarchies
decorator is also an object; 'is-a' relationship to behave like object (base class object)
also, it has 'has-a' relationship of composition (decorator has objects) to change properties dynamically
in other words, decorator has base class and decorator is a base class, both.

obj - "I did something"
dec1 - "I did something amazing"
dec2 - "I did something amazing today"

it is just like having recusion using classes
to pass objects in each others constructor, it need to be an object too, that's why it has 'is-a' relationship.

decorator pattern attaches additional responsibility to an object dynamically. decorator provides a flexible alternative to subclassing for extending functionality.

real life use-case :
word processor like MS Word - decorating text with Bold, Italics and Underline options
using in form validations : email verification, SQL injection attack, CSS injection attack
*/