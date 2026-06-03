/*
flexible design - minimal code changes, and minimal time when integrating any new feature
segregate the static and dynamic (ever evolving) portions of the application, so that, dynamic portions have minimal impact on the application as it won't be ceased to change

why inheritance is bad ?
consider the example of robot applications with their features

robot ->    1. talkable
                        i) walkable
                                a) flyable
                                b) non-flyable
                        ii) non-walkable
                                a) flyable
                                b) non-flyable
            2. non-talkable
                        i) walkable
                                a) flyable
                                b) non-flyable
                        ii) non-walkable
                                a) flyable
                                b) non-flyable

while many classes inheriting from their many parent classes, the number of permutations will be too much and it will be much complicated to handle.
=> the solution to inheritance is not more inheritance

problems ->
1. bad code reuse
2. to add new changes, a lot of changes were required
3. breaking OCP

strategy design pattern -
defines a family of algorithm, put them in separate classes so they can be changed at runtime.
encapsulate what varies and keep it separate from what remains same.

we can make interfaces namely Talkable, Walkable and Flyable, which are dynamic methods and they were causing so much combinations. Now, from this interfaces all the others classes will be derived with concrete implementation
Robot class now using composition instead of inheritance
the main class, which is here is 'Robot' called as client in Strategy design pattern perspective.
the interfaces are called 'strategies'

we can remove projection() also, and make an interface for that, like we did for all other 3 methods.
thus, inheritance can be completely removed from it.
it will be solely dependent on composition only.

it supports OCP also.
solution to inheritance is not more inheritance
in the end, favour composition over inheritance
"code to an interface, not to an implementation"

real life example -
payment system - payNow()
i) UPI, ii) NetBanking, iii) Cards

sorting algorithm - sort()
i) MergeSort, ii) QuickSort, iii) InsertionSort
*/