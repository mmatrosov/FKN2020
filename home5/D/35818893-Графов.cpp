#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Document {
protected:
    const std::string Content;
public:
    Document(const std::string& s) : Content(s) {}
    virtual void Save() const {
    }
};

class PlainTextDocument : public Document {
public:
    PlainTextDocument(const std::string& s) : Document(s) {}
    virtual void Save() const {
        std::cout << Content << "\n";
    }
};

class HTMLDocument : public Document {
public:
    HTMLDocument(const std::string& s) : Document(s) {}
    virtual void Save() const {
        std::cout << "<HTML><BODY>" << Content << "</BODY></HTML>\n";
    }
};

using DocumentCollection = std::vector<std::unique_ptr<Document>>;

void AddDocument(const std::string& content, const std::string& type,
    DocumentCollection& collection) {
    if (type == "plain") {
        PlainTextDocument* a = new PlainTextDocument(content);
        collection.push_back(std::unique_ptr<Document>(a));
    } else {
        if (type == "html") {
            HTMLDocument* a = new HTMLDocument(content);
            collection.push_back(std::unique_ptr<Document>(a));
        }
    }
}

void PrintCollection(const DocumentCollection& collection) {
    for (int i = 0; i < collection.size(); ++i)
        collection[i]->Save();
}