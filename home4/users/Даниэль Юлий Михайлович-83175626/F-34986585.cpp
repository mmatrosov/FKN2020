#include <iostream>
#include <list>
#include <string>

class Vim {
    std::list<char> text;
    std::list<char>::iterator pos = text.end();
    std::string mode = "normal";

    void normal(char c) {
        if (c == 'h' && pos != text.begin())
            pos--;
        if (c == 'l' && pos != text.end())
            pos++;
        if (c == 'i')
            mode = "insert";
    }

    void insert(char c) {
        if (c == '<')
            mode = "normal";
        else
            text.insert(pos, c);
    }

   public:
    void process(char c) {
        if (mode == "normal")
            normal(c);
        else
            insert(c);
    }

    void output() {
        for (auto c : text)
            std::cout << c;
        std::cout << std::endl;
    }
};

int main() {
    Vim redactor;

    std::string in;
    std::getline(std::cin, in);

    for (auto c : in)
        redactor.process(c);
    redactor.output();
    return 0;
}