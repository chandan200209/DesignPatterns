#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

class IObserver
{
public:
    virtual void update() = 0;
    virtual ~IObserver() {}
};
// Notification and Decorator
class INotification
{
public:
    virtual string getContent() const = 0;
    virtual ~INotification() {}
};
// concrete notification : simple text notification
// further we can support HTML notifications with images, gifs or videos
class SimpleNotification : public INotification
{
private:
    string text;

public:
    SimpleNotification(const string &msg)
    {
        this->text = msg;
    }
    string getContent() const override
    {
        return text;
    }
};
// abstract decorator : wraps a notification object
class INotificationDecorator : public INotification
{
protected:
    INotification *notification;

public:
    INotificationDecorator(INotification *n)
    {
        notification = n;
    }
    virtual ~INotificationDecorator()
    {
        delete notification;
    }
};
// decorator to add a timestamp to the content
class TimestampDecorator : public INotificationDecorator
{
public:
    TimestampDecorator(INotification *n) : INotificationDecorator(n) {}
    static string getCurrentTime()
    {
        time_t now = time(0);   // time returns no. of seconds since January 1, 1970 (Unix Epoch).
        char *dt = ctime(&now); // ctime converts the time in seconds in human readable form
        string s(dt);           // since, ctime returns in c like string, we need to convert this in c++ like string
        if (!s.empty() && s.back() == '\n')
        {
            s.pop_back(); // If the string isn't empty and its last character is a newline, remove it.
        }
        return s;
    }
    string getContent() const override
    {
        return getCurrentTime() + " " + notification->getContent();
    }
};
// decorator to appnend signature to the content
class SignatureDecorator : public INotificationDecorator
{
private:
    string signature;

public:
    SignatureDecorator(INotification *n, const string &sig) : INotificationDecorator(n)
    {
        signature = sig;
    }
    string getContent() const override
    {
        return notification->getContent() + "\n--" + signature + "\n\n";
    }
};

// observer pattern components
class IObservable
{
public:
    virtual void addObserver(IObserver *observer) = 0;
    virtual void removeObserver(IObserver *observer) = 0;
    virtual void notifyObserers() {}
};

// concrete observable
class NotificationObservable : public IObservable
{
private:
    vector<IObserver *> observers;
    INotification *currentNotification;

public:
    NotificationObservable()
    {
        currentNotification = nullptr;
    }
    void addObserver(IObserver *obs) override
    {
        observers.push_back(obs);
    }
    void removeObserver(IObserver *obs) override
    {
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }
    void notifyObserers() override
    {
        for (unsigned int i = 0; i < observers.size(); i++)
        {
            observers[i]->update();
        }
    }
    void setNotification(INotification *notification)
    {
        // Without this, every time a new notification is set, the old one would remain in memory, causing a memory leak.
        if (currentNotification != nullptr)
        {
            delete currentNotification;
        }
        currentNotification = notification;
        notifyObserers();
    }
    INotification *getNotification()
    {
        return currentNotification;
    }
    string getNotificationContent()
    {
        return currentNotification->getContent();
    }
};

// observer interface : each observer gets a update with a Notification pointer
// concrete observer 01
class Logger : public IObserver
{
private:
    NotificationObservable *notificationObservable;

public:
    Logger(NotificationObservable *observable)
    {
        this->notificationObservable = observable;
    }
    void update()
    {
        cout << "Logging new notification : \n"
             << notificationObservable->getNotificationContent();
    }
};
// concrete observer 02 (strategy pattern components - notification engine)
class INotificationStrategy
{
public:
    virtual void sendNotification(string content) = 0;
};
class EmailStrategy : public INotificationStrategy
{
private:
    string emailID;

public:
    EmailStrategy(string emailID)
    {
        this->emailID = emailID;
    }
    void sendNotification(string content) override
    {
        // simulate the process of sending the email notification, representing the dispatch of messages/notifications to the users via email
        cout << "Sending email notification to " << emailID << "\n"
             << content << endl;
    }
};
class SMSStrategy : public INotificationStrategy
{
private:
    string mobileNumber;

public:
    SMSStrategy(string mobile)
    {
        this->mobileNumber = mobile;
    }
    void sendNotification(string content) override
    {
        // simulate the process of sending an SMS notification, representing the dispatch of messages to users via SMS
        cout << "Sending SMS notification to " << mobileNumber << "\n"
             << content << endl;
    }
};
class PopUpStrategy : public INotificationStrategy
{
public:
    void sendNotification(string content) override
    {
        // simulate the process of sending the popup notifications
        cout << "Sending popup notifications.\n"
             << content << endl;
    }
};
class NotificationEngine : public IObserver
{
private:
    NotificationObservable *notificationObservable;
    vector<INotificationStrategy *> notificationStrategies;

public:
    NotificationEngine(NotificationObservable *observable)
    {
        this->notificationObservable = observable;
    }
    void addNotificationStrategy(INotificationStrategy *ns)
    {
        this->notificationStrategies.push_back(ns);
    }
    // can have remove notification strategy as well
    void update()
    {
        string notificationContent = notificationObservable->getNotificationContent();
        for (const auto notificationStrategy : notificationStrategies)
        {
            notificationStrategy->sendNotification(notificationContent);
        }
    }
};
// notification service - the NotificationService manages notifications. it keeps track of notifications.
// any client code will interact with this service.
class NotificationService
{
private:
    NotificationObservable *observable;
    static NotificationService *instance;
    vector<INotification *> notifications;
    NotificationService()
    {
        // private constructor
        observable = new NotificationObservable();
    }

public:
    static NotificationService *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new NotificationService();
        }
        return instance;
    }
    // expose the observable so observers can attach.
    NotificationObservable *getObservable()
    {
        return observable;
    }
    // creates a new Notification and notify observers
    void sendNotification(INotification *notification)
    {
        notifications.push_back(notification);     // to maintain history
        observable->setNotification(notification); // setNotification() -> notify() -> update()
    }
    ~NotificationService()
    {
        delete observable;
    }
};
NotificationService *NotificationService::instance = nullptr;
int main()
{
    // create NotificationService
    NotificationService *notificationService = NotificationService::getInstance();
    // create observable
    NotificationObservable *notificationObservable = notificationService->getObservable();
    // create logger observer
    Logger *logger = new Logger(notificationObservable);

    // create NotificationEngine observers
    NotificationEngine *notificationEngine = new NotificationEngine(notificationObservable);
    notificationEngine->addNotificationStrategy(new EmailStrategy("chandan@example.com"));
    notificationEngine->addNotificationStrategy(new SMSStrategy("+91 1234567890"));
    notificationEngine->addNotificationStrategy(new PopUpStrategy());

    // attach these observers
    notificationObservable->addObserver(logger);
    notificationObservable->addObserver(notificationEngine);

    // create a notification with decorators
    INotification *notification = new SimpleNotification("Your order has been shipped.");
    notification = new TimestampDecorator(notification);
    notification = new SignatureDecorator(notification, "Customer Care");

    notificationService->sendNotification(notification);

    delete logger;
    delete notificationEngine;
    return 0;
}