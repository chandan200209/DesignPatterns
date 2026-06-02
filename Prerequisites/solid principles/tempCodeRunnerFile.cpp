#include <iostream>
using namespace std;

// low level module
class MySQLDatabase
{
public:
    void saveToSql(string data)
    {
        cout << "Executing SQL Query : INSERT INTO users VALUES('" << data << "'); " << endl;
    }
};
// low level module
class MongoDBDatabase
{
public:
    void saveToMongoDB(string data)
    {
        cout << "Executing MongoDB Function : db.users.insert({name : '" << data << "'})" << endl;
    }
};
// high level module (tightly coupled)
class UserService
{
private:
    // has-a relationship
    MySQLDatabase sqlDb;     // direct dependency on MySQL
    MongoDBDatabase mongoDb; // direct dependency on MongoDB
public:
    void storeUserToSQL(string user)
    {
        // SQL specific code
        sqlDb.saveToSql(user);
    }
    void storeUserToMongoDB(string user)
    {
        // MongoDB specific code
        mongoDb.saveToMongoDB(user);
    }
};
int main()
{
    UserService service;
    service.storeUserToSQL("Roy");
    service.storeUserToMongoDB("Hemant");
    return 0;
}