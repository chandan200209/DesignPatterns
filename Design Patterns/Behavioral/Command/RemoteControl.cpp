#include <iostream>
using namespace std;

// Command interface
class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() {}
};
// receivers
class Light
{
public:
    void on()
    {
        cout << "Light is ON" << endl;
    }
    void off()
    {
        cout << "Light is OFF" << endl;
    }
};
class Fan
{
public:
    void on()
    {
        cout << "Fan is ON" << endl;
    }
    void off()
    {
        cout << "Fan is OFF" << endl;
    }
};
// concrete command for Light
class LightCommand : public Command
{
private:
    Light *light;

public:
    LightCommand(Light *l)
    {
        light = l;
    }
    void execute()
    {
        light->on();
    }
    void undo()
    {
        light->off();
    }
};
// concrete command for Fan
class FanCommand : public Command
{
private:
    Fan *fan;

public:
    FanCommand(Fan *f)
    {
        fan = f;
    }
    void execute()
    {
        fan->on();
    }
    void undo()
    {
        fan->off();
    }
};
// Invoker : Remote Controller with static 2D of 4 buttons (2 columns, 2 rows)
class RemoteController
{
private:
    static const int numButtons = 4;
    Command *buttons[numButtons];
    bool buttonsPressed[numButtons]; // stores either true or false, for being ON or OFF
public:
    RemoteController()
    {
        for (int i = 0; i < numButtons; i++)
        {
            buttons[i] = nullptr;
            buttonsPressed[i] = false; // false = off, true = on
        }
    }
    void setCommand(int idx, Command *cmd)
    {
        if (idx >= 0 && idx < numButtons)
        {
            if (buttons[idx] != nullptr) // means we have already set command on that button index
            {
                delete buttons[idx]; // deleting that command first, and reassigning anew
            }
            buttons[idx] = cmd;
            buttonsPressed[idx] = false;
        }
    }
    void pressButton(int idx)
    {
        if (idx >= 0 && idx < numButtons && buttons[idx] != nullptr)
        {
            if (buttonsPressed[idx] == false)
            {
                buttons[idx]->execute();
            }
            else
            {
                buttons[idx]->undo();
            }
            buttonsPressed[idx] = !buttonsPressed[idx];
        }
        else
        {
            cout << "No command assigned at button " << idx << endl;
        }
    }
    ~RemoteController()
    {
        for (int i = 0; i < numButtons; i++)
        {
            if (buttons[i] != NULL)
            {
                delete buttons[i];
            }
        }
    }
};
int main()
{
    Light *livingRoomLight = new Light();
    Fan *ceilingFan = new Fan();

    RemoteController *remote = new RemoteController();
    remote->setCommand(0, new LightCommand(livingRoomLight));
    remote->setCommand(1, new FanCommand(ceilingFan));

    // simulate button presses (toggle behaviour)
    cout << "--- Toggling Light Button 0 ---" << endl;
    remote->pressButton(0); // ON
    remote->pressButton(0); // OFF
    remote->pressButton(0); // ON
    cout << "--- Toggling Fan Button 1 ---" << endl;
    remote->pressButton(1); // ON
    remote->pressButton(1); // OFF

    // press unassigned button to show default message
    cout << "--- Pressing Unassigned Button 2 ---" << endl;
    remote->pressButton(2);

    // clean up
    delete remote;
    delete livingRoomLight;
    delete ceilingFan;

    return 0;
}