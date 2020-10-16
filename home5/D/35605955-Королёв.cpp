#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Document {
protected:
    std::string Content;
public:
    Document(const std::string& s): Content(s) {}
    virtual void Save() {}
};

class PlainTextDocument: public Document {
public:
    PlainTextDocument(const std::string& s): Document(s) {}
    virtual void Save() {
        std::cout << Content << "\n";
    }
};

class HTMLDocument: public Document {
public:
    HTMLDocument(const std::string& s): Document(s) {}
    virtual void Save() {
        std::cout << "<HTML><BODY>" << Content << "</BODY></HTML>\n";
    }
};

using DocumentCollection = std::vector<std::unique_ptr<Document>>;

void AddDocument(const std::string& content,
                 const std::string& type,
                 DocumentCollection& collection) {
    if (type == "plain")
        collection.emplace_back(new PlainTextDocument(content));
    else if (type == "html")
        collection.emplace_back(new HTMLDocument(content));
}

void PrintCollection(const DocumentCollection& collection) {
    for (auto& doc : collection)
        doc->Save();
}