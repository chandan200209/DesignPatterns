#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// forward declaration
class ISubscriber;
// abstract Observable interface : a YouTube channel interface
class IChannel
{
public:
    virtual void subscribe(ISubscriber *subscriber) = 0;
    virtual void unsubscribe(ISubscriber *subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}; // virtual destructor for interface
};
// abstract Observer interface : subscribers must implement update()
class ISubscriber
{
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
};

// concrete subject : a YouTube channel that observers can subscribe to
class Channel : public IChannel
{
private:
    vector<ISubscriber *> subscribers; // list of subscribers
    string name;
    string latestVideo; // latest uploaded video title
public:
    Channel(const string &name)
    {
        this->name = name;
    }
    // The find() function returns : An iterator pointing to the element if it is found.
    // subscribers.end() if the element is not found.
    // it == subscribers.end() means: "it has reached the end (or the element wasn't found)."

    // add a subscriber (avoid duplicates)
    void subscribe(ISubscriber *subscriber) override
    {
        // checking if, it doesn't exists in the list already
        if (find(subscribers.begin(), subscribers.end(), subscriber) == subscribers.end())
        {
            subscribers.push_back(subscriber);
        }
    }
    // remove a subscriber if present
    void unsubscribe(ISubscriber *subscriber) override
    {
        auto it = find(subscribers.begin(), subscribers.end(), subscriber);
        if (it != subscribers.end())
        {
            subscribers.erase(it);
        }
    }
    // notify all subscribers of the latest video
    void notifySubscribers() override
    {
        for (ISubscriber *sub : subscribers)
        {
            sub->update();
        }
    }
    // upload a new video and notify all subscribers
    void uploadVideo(const string &title)
    {
        latestVideo = title;
        cout << "\n[" << name << " uploaded " << title << "]" << endl;
        notifySubscribers();
    }
    // get video data
    string getVideoData()
    {
        return " Checkout our latest video " + latestVideo + "\n";
    }
};
// concrete subscriber : represents a subscriber to a channel
class Subscriber : public ISubscriber
{
private:
    string name;
    Channel *channel; // the channel which he/she had followed [as a composition]

public:
    Subscriber(const string &name, Channel *channel)
    {
        this->name = name;
        this->channel = channel;
    }
    // called by channel; prints notification message
    void update() override
    {
        cout << "Hey, " << name << "!," << this->channel->getVideoData();
    }
};
int main()
{
    // create a channel and subscribers
    Channel *channel = new Channel("LazyAssassin");
    Subscriber *subs1 = new Subscriber("Michael", channel);
    Subscriber *subs2 = new Subscriber("Harrison", channel);

    // Channel owns the list of subscribers
    // Michael and Harrison subscribers to LazyAssassin
    channel->subscribe(subs1);
    channel->subscribe(subs2);

    // upload a video, both will be notified
    channel->uploadVideo("Detroit Become Human");

    // Michael unsubscribes, Harrison remains subscribed
    channel->unsubscribe(subs1);

    // upload another video, only Harrison gets notified
    channel->uploadVideo("Immortal Fenyx Rising");
    return 0;
}
// alternative approach for subscribe and unsubscribe, so users and channels both call these methods
// class Subscriber {
//     Channel* channel;

// public:
//     void subscribe() {
//         channel->subscribe(this);
//     }

//     void unsubscribe() {
//         channel->unsubscribe(this);
//     }
// };