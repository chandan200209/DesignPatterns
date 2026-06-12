/*
-- design a food delivery app --
functional requirements -> product related, business logic
i) user can search for restaurants based on location
ii) user can add items to the cart
iii) user can checkout by making payments
iv) user should be notified once order is placed successfully

non - functional requirements ->
each part of the application should be scalable and modifiable

food delivery app can be of two parts -
i) user centric
ii) for delivery agents
here, we are focussing on that application is user centric

lld questions UML -
i) bottom - up approach
ii) top - down approach

model class - which have variables and their getters & setters, but not any functionality
here, MenuItem is a model class.
Model classes are generally represented as tables in databases easily.
for this application, we assume 'MenuItem' is dependent on 'Restaurant'
hence, the relationship between the two will be composition

RestaurantManager and Restaurant has aggregation relationship as restaurant can exist independently
Managers objects are 'single point of contact' for those objects whom they are managing.
which means, Restaurant can't be interacted directly, only through its manager.
it will help in maintaining loose coupling.
Manager classes are singleton classes, because generally managers handles a list of objects, we never want many objects to maintain many lists

orchestrator class - acts as 'single point of contact' and interacts with all other subsequent classes to achieve a workflow
It does not contain heavy business logic itself — instead, it delegates tasks to other classes and manages the sequence and data flow between them.
orchestrator class generally violates SRP.
in simple terms :
frontend <-> orchestrator class <-> backend

there can be two approaches of passing parameters to a function.
for example -
1. restaurantAddress(user->getAddress());
2. restaurantAddress(address);

in first one, we break the "Principle of Least Knowledge", because here we need to have knowledge about the user object and its structure to fully utilize it.
although, in second one, we just keep passing the parameters, whatever we get.

further extensions :
1. we can add PaymentStrategyFactory, combining two design patterns
which is used for managing payments, currently we are deciding which payment strategy to use in our "main()", which is generally unacceptable
2. there can be various kinds of notification services, like, email, push, etc.
3. inplace of one single orchestrator class, use of APIs is supported, like '/search', '/pay'
*/