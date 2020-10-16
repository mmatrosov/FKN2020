#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Document {
protected:
    const std::string Content;

public:
    Document(const std::string& s) : Content(s) {
    }
    virtual void Save() const {
    }
    virtual ~Document() {
        // std::cout << "~Doc\n";
    }
};

class PlainTextDocument : public Document {
public:
    PlainTextDocument(const std::string& s) : Document(s) {
    }
    void Save() const override {
        std::cout << Content << "\n";
    }
    ~PlainTextDocument() override {
        // std::cout << "~Plain\n";
    }
};

class HTMLDocument : public Document {
public:
    HTMLDocument(const std::string& s) : Document(s) {
    }
    void Save() const override {
        std::cout << "<HTML><BODY>" << Content << "</BODY></HTML>\n";
    }
    ~HTMLDocument() override {
        // std::cout << "~html\n";
    }
};

using DocumentCollection = std::vector<std::shared_ptr<Document>>;

void AddDocument(const std::string& content, const std::string& type,
                 DocumentCollection& collection) {
    if (type == "plain") {
        collection.push_back(std::shared_ptr<PlainTextDocument>(new PlainTextDocument(content)));
    } else if (type == "html") {
        collection.push_back(std::shared_ptr<HTMLDocument>(new HTMLDocument(content)));
    }
}

void PrintCollection(const DocumentCollection& collection) {
    for (const auto& doc : collection)
        (*doc).Save();
}
