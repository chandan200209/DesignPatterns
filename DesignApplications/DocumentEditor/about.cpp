/*
document editor application - like, google docs
features -
i) we can insert text and images currently
ii) should be scalable and later we will have features like supporting videos and tables, new lines, fonts, tab space and different kinds of editing features.

there are two approaches of handling an LLD problem -
a) top-down approach - main object first, then smaller modules and their dependencies
b) bottom-up approach - smaller objects first, then integrating them along with their dependencies

many interviewees go for bottom-up and we're too going for this approach in this problem statement

taking variables for text and images, for this we have two options
-> storing both in their respective variables - this will lead to problem of maintaining their order
-> second option is of storing them in a single variable (vector list)

in better design version, DocumentEditor class too have all the methods, but it is not handling them, it is just delegating them to the subsequent classes
but, there is one problem in this approach too.
although it does not have implementation of all the methods, but it should have the knowledge of all the underlying methods, and, deletion or addition of any method in other classes also affect the DocumentEditor class
we can add Client class, we can interact with all the other classes

this happens too in Document class (<<model>> class)
to solve this, we can add a new class named DocumentRenderer and transfer the render() to it.

principle of least knowledge - you should always talk with your immediate friends
a class should always call methods of those classes only whom which it is directly related
*/