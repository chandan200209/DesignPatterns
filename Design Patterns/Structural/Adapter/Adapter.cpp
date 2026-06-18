#include <iostream>
#include <string>
using namespace std;

// 1. target interface expected by the client
class IReports
{
public:
    // now takes the raw data string and returns JSON
    virtual string getJsonData(const string &data) = 0;
    virtual ~IReports() {}
};
// 2. adaptee : provides XML data from a raw input
class XMLDataProvider
{
public:
    // expects data in "name:id" format (eg., "Henry:123")
    string getXmlData(const string &data)
    {
        size_t sep = data.find(':');
        string name = data.substr(0, sep); // substr(start, length)
        string id = data.substr(sep + 1);
        // build an XML representation
        return "<user>"
               "<name>" +
               name + "</name>"
                      "<id>" +
               id + "</id>"
                    "</user>";
    }
};
// 3. adapter : implements IReports by converting XML -> JSON
class XMLDataProviderAdapter : public IReports
{
private:
    XMLDataProvider *xmlDataProvider; // has-a relationship -> reference of third party library
public:
    XMLDataProviderAdapter(XMLDataProvider *provider)
    {
        this->xmlDataProvider = provider;
    }
    string getJsonData(const string &data) override
    {
        // 1. get XML from the adaptee
        string xml = xmlDataProvider->getXmlData(data);
        // 2. naively parse our <name> and <id> values
        size_t startName = xml.find("<name>") + 6; // 6 for '<name>'
        size_t endName = xml.find("</name>");
        string name = xml.substr(startName, endName - startName);

        size_t startId = xml.find("<id>") + 4; // 4 for '<id>'
        size_t endId = xml.find("</id>");
        string id = xml.substr(startId, endId - startId);

        // 3. build and return JSON
        return "{\"name\":\"" + name + "\", \"id\":" + id + "}";
    }
};
// 4. client code works only with IReports code
class Client
{
public:
    void getReport(IReports *report, string rawData)
    {
        cout << "Processed JSON : " << report->getJsonData(rawData) << endl;
    }
};
int main()
{
    // create the adaptee
    XMLDataProvider *xmlProv = new XMLDataProvider();
    // make our adapter
    IReports *adapter = new XMLDataProviderAdapter(xmlProv);
    // get our raw data
    string rawData = "Sachin:1000";
    // client prints the JSON
    Client *client = new Client();
    client->getReport(adapter, rawData); // adapter is a report, that's why we passed it too.
    // Processed JSON : {"name":"Sachin","id":1000}

    // clean up code
    delete xmlProv;
    delete adapter;
    return 0;
}