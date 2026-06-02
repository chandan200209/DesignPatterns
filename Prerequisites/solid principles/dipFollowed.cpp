#include <iostream>
using namespace std;

// abstract (interface)
class Database
{
public:
    virtual void save(string data) = 0; // pure virtual function
};

// mysql implementation (low level module)
class MySQLDatabase : public Database
{
public:
    void save(string data) override
    {
        cout << "Executing SQL Query : INSERT INTO users VALUES('" << data << "'); " << endl;
    }
};
// mongodb implementation (low level module)
class MongoDBDatabase : public Database
{
public:
    void save(string data) override
    {
        cout << "Executing MongoDB Function : db.users.insert({name : '" << data << "'})" << endl;
    }
};
// high level module (now loosely coupled)
class UserService
{
private:
    Database *db; // dependency injection - passing object as a variable in a class
public:
    UserService(Database *database)
    {
        db = database;
    }
    void storeToUser(string user)
    {
        db->save(user);
    }
};
int main()
{
    MySQLDatabase mysql;
    MongoDBDatabase mongodb;

    UserService service1(&mysql);
    service1.storeToUser("Roy");
    UserService service2(&mongodb);
    service2.storeToUser("Hemant");

    return 0;
}