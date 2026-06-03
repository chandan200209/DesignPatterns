#include <bits/stdc++.h>
using namespace std;

class DocumentEditor
{
private:
    vector<string> documentElements;
    string renderedDocument; // saves the whole rendered document as string, when repeatedly being rendered or saved to file
public:
    // add text as a plain string
    void addText(string text)
    {
        documentElements.push_back(text);
    }
    // add an image represented by its file path
    void addImage(string imagePath)
    {
        documentElements.push_back(imagePath);
    }
    // renders the document by checking the type of each element at the runtime
    string renderDocument()
    {
        if (renderedDocument.empty())
        {
            string result;
            for (auto element : documentElements)
            {
                if (element.size() > 4 && (element.substr(element.size() - 4) == ".jpg" || element.substr(element.size() - 4) == ".png"))
                {
                    result += "[Image : " + element + "]" + "\n";
                }
                else
                {
                    result += element + "\n";
                }
            }
            renderedDocument = result;
        }
        return renderedDocument;
    }
    void saveToFile()
    {
        ofstream file("document.txt");
        if (file.is_open())
        {
            file << renderDocument();
            file.close();
            cout << "Document is saved to file document.txt" << endl;
        }
        else
        {
            cout << "Error : Unable to open file for writing." << endl;
        }
    }
};

int main()
{
    DocumentEditor editor;
    editor.addText("this is programming lecture");
    editor.addText("design patterns");
    editor.addImage("patterns.jpg");

    cout << editor.renderDocument();
    editor.saveToFile();
    return 0;
}

// problems in this design
// violating SRP, OCP
// no LSP, ISP and, DIP