#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// abstraction for document elements
class DocumentElement
{
public:
    virtual string render() = 0;
};

// concrete implementation for text elements
class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }
    string render() override
    {
        return text;
    }
};

// concrete implementation for image elements
class ImageElement : public DocumentElement
{
private:
    string imagePath;

public:
    ImageElement(string imagePath)
    {
        this->imagePath = imagePath;
    }
    string render() override
    {
        return "[Image : " + imagePath + "]";
    }
};
// NewLineElement represents a line break in the document
class NewLineElement : public DocumentElement
{
public:
    string render() override
    {
        return "\n";
    }
};
// TabSpaceElement represents a tab space in the document
class TabSpaceElement : public DocumentElement
{
public:
    string render() override
    {
        return "\t";
    }
};

// Document class responsible for holding a collection of elements
class Document
{
private:
    // has-a relationship (one to many - document and documentElements)
    vector<DocumentElement *> documentElements;

public:
    void addElement(DocumentElement *element)
    {
        documentElements.push_back(element);
    }
    // renders the document by concatenating the render outputs of all elements
    string render()
    {
        string result;
        for (auto element : documentElements)
        {
            result += element->render();
        }
        return result;
    }
};

// Persistence Interface
class Persistence
{
public:
    virtual void save(string data) = 0;
};
// FileStorage implementation of Persistence
class FileStorage : public Persistence
{
public:
    void save(string data) override
    {
        ofstream outFile("documentFinal.txt");
        if (outFile)
        {
            outFile << data;
            outFile.close();
            cout << "Document is saved to file document.txt" << endl;
        }
        else
        {
            cout << "Error : Unable to open file for writing." << endl;
        }
    }
};
// Placeholder DBStorage implementation
class DBStorage : public Persistence
{
public:
    void save(string data) override
    {
        // saves to DB
    }
};
// DocumentEditor class managing client interactions
class DocumentEditor
{
private:
    Document *document;
    Persistence *storage;
    string renderedDocument;

public:
    DocumentEditor(Document *document, Persistence *storage)
    {
        this->document = document;
        this->storage = storage;
    }
    void addText(string text)
    {
        document->addElement(new TextElement(text));
    }
    void addImage(string imagePath)
    {
        document->addElement(new ImageElement(imagePath));
    }
    // adds a new line to the document
    void addNewLine()
    {
        document->addElement(new NewLineElement());
    }
    // adds a tab space to the document
    void addTabSpace()
    {
        document->addElement(new TabSpaceElement());
    }
    string renderDocument()
    {
        if (renderedDocument.empty())
        {
            renderedDocument = document->render();
        }
        return renderedDocument;
    }
    void saveDocument()
    {
        storage->save(renderDocument()); // whatever is returned from renderDocument() is now saved
    }
};
int main()
{
    Document *document = new Document();
    Persistence *persistence = new FileStorage();

    DocumentEditor *editor = new DocumentEditor(document, persistence);

    // simulate a client using document editor with common text formatting features
    editor->addText("Hello World");
    editor->addNewLine();
    editor->addText("This is a document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("This is a line after indentation.");
    editor->addNewLine();
    editor->addImage("image.jpg");

    // render and display the final document
    cout << editor->renderDocument() << endl;
    editor->saveDocument();
    return 0;
}