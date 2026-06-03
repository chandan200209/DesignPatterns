#include <iostream>
using namespace std;

// strategy interface for walk
class WalkableRobot
{
public:
    virtual void walk() = 0;
    ~WalkableRobot() {}
};

// concrete strategies for walk
class NormalWalk : public WalkableRobot
{
public:
    void walk() override
    {
        cout << "Walking normally..." << endl;
    }
};
class NoWalk : public WalkableRobot
{
public:
    void walk() override
    {
        cout << "Cannot walk." << endl;
    }
};

// strategy interface for talk
class TalkableRobot
{
public:
    virtual void talk() = 0;
    ~TalkableRobot() {}
};

// concrete strategies for talk
class NormalTalk : public TalkableRobot
{
public:
    void talk() override
    {
        cout << "Talking normally..." << endl;
    }
};
class NoTalk : public TalkableRobot
{
public:
    void talk() override
    {
        cout << "Cannot talk." << endl;
    }
};

// strategy interface for fly
class FlyableRobot
{
public:
    virtual void fly() = 0;
    ~FlyableRobot() {}
};

// concrete strategies for fly
class NormalFly : public FlyableRobot
{
public:
    void fly() override
    {
        cout << "Flying normally..." << endl;
    }
};
class NoFly : public FlyableRobot
{
public:
    void fly() override
    {
        cout << "Cannot fly." << endl;
    }
};

// Robot Base Class
class Robot
{
protected:
    WalkableRobot *walkBehavior;
    TalkableRobot *talkBehavior;
    FlyableRobot *flyBehavior;

public:
    Robot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f)
    {
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }
    // dumb methods, they are simply delegating to other interfaces
    void walk()
    {
        walkBehavior->walk();
    }
    void talk()
    {
        talkBehavior->talk();
    }
    void fly()
    {
        flyBehavior->fly();
    }
    virtual void projection() = 0; // abstract method for subclasses
};

// concrete robot types
class CompanionRobot : public Robot
{
public:
    CompanionRobot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f) : Robot(w, t, f) {}
    void projection() override
    {
        cout << "Displaying friendly companion features..." << endl;
    }
};
class WorkerRobot : public Robot
{
public:
    WorkerRobot(WalkableRobot *w, TalkableRobot *t, FlyableRobot *f) : Robot(w, t, f) {}
    void projection() override
    {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};
int main()
{
    // we can show many permutations here
    Robot *robot01 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot01->walk();
    robot01->talk();
    robot01->fly();
    robot01->projection();

    cout << "---------------" << endl;
    Robot *robot02 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot02->walk();
    robot02->talk();
    robot02->fly();
    robot02->projection();

    return 0;
}