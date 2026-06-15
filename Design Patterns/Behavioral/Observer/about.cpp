/*
this solves a common problem that : when an object changes, other object must get notified about when it is changed, and what are the newer values (internal state) caused by that change.

observable - subject (only one)
observer - individual objects who want to look for state change (can be many)

polling technique - earlier used instead of observer design pattern
-> in a certain frequency, observer asks about the value change in the observable

pushing technique - observable itself notify the observers when the value change
observable can maintain a data structure to store the details about the observers, so it can help it to send the updation notifications

notify() in the observable will call the update() in the observer

naming conventions - IObserver - here I indicates that, it's an interface (pure abstract class)

observer design pattern - defines a one to many relationship among objects, so that when one object changes, all its dependents are notified and updated automatically.

our example is breaking the SRP :
it is handling both business logic and observer design pattern code
it has uploadVideo() along with subscribe(), unsubscribe() and notify()
how to fix it ?
observable is handling -> observer design pattern
concrete observable is handling -> business logic

real life use case - notification service, news feed service, event handling programming, weather station
*/