/*
Command Design Pattern

earlier, with no Command Design Pattern, there are two kind of entities here.
i) sender
ii) receiver
=> sender using asks the receiver to do something by calling its method;
=> it is a request, command or action from the sender to the receiver

with Command Design Pattern ->
i) sender
ii) command
iii) receiver
sender <=> command <=> receiver
it is done to make it loosely coupled

Example - smart home automation system -
we have a device (say) remote, which has three buttons - using for switching ON/OFF light, fan & AC
class Remote{
    Light light;
    pressLightButton(){
    light.on()
    }
};
=> using this, we make our Remote tightly coupled with Light, or any other device.
=> this is now breaking the Open Closed Principle.

doubt in Command Pattern -
sometimes we have a 'has-a' relationship in Interface, while sometimes we have on Concrete Classes
eg, here we have 'Light* light' in LightCommand, not in Command, which has only virtual methods.
it's all about the intention of the class, what work it supposed to do.
here, Command only responsible for having methods, but not explicitly on which object those methods will be called

why we are having concretions like LightCommand, FanCommand, Light and Fan classes, not only Command (concrete) and Appliances, which work for all kind of devices and we need not to make those classes
answer => for Liskov Substitution Principle
Light has only on and off methods, while Fan has on, off, speed regulation methods.
here, child classes are not replacable by their parent classes, if using this approach

real-life use cases =>
i) text editor, photoshop - having undo features
ii) keyboard shortcuts - keyboard is not statically linked to the action
    keyboard <-> command <-> increasing/decresing monitor brightness

standard definition -
encapsulate a request as an object, thereby letting you paramterize clients with different request, queue, or log request and support undoable operations.
*/