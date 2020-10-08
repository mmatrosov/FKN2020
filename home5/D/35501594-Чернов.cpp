#include <iostream>
#include <string>
#include <vector>

class Document {
public:
    const std::string Content;

    Document(const std::string& s) : Content(s) {
    }

    virtual void Save() const {
    }

    virtual ~Document() {
    }
};

class PlainTextDocument : public Document {
public:
    PlainTextDocument(const std::string& s) : Document(s) {
    }

    void Save() const override {
        std::cout << Content << "\n";
    }
};

class HTMLDocument : public Document {
public:
    HTMLDocument(const std::string& s) : Document(s) {
    }

    void Save() const override {
        std::cout << "<HTML><BODY>" << Content << "</BODY></HTML>\n";
    }
};

enum class Type {
    plain,
    html,
};

class Pointer {
private:
    Type t;
    Document* ptr;

public:
    Pointer(const std::string& content, const std::string type) {
        if (type == "plain") {
            t = Type::plain;
            ptr = new PlainTextDocument(content);
        } else {
            t = Type::html;
            ptr = new HTMLDocument(content);
        }
    }

    Pointer(const Pointer& other) {
        if (other.t == Type::plain) {
            ptr = new PlainTextDocument(other.ptr->Content);
        } else {
            ptr = new HTMLDocument(other.ptr->Content);
        }
    }

    const Document* GetPointer() const {
        return ptr;
    }

    ~Pointer() {
        delete ptr;
    }
};

using DocumentCollection = std::vector<Pointer>;

void AddDocument(const std::string& content, const std::string& type,
    DocumentCollection& collection) {
    collection.emplace_back(content, type);
}

void PrintCollection(const DocumentCollection& collection) {
    for (const auto& doc : collection)
        doc.GetPointer()->Save();
}