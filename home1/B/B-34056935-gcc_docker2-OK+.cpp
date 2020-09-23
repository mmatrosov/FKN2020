#include <iostream>
#include <map>

char convert(char c) {
    std::map<char, int> helper = {{'a', '0'}, {'b', '1'}, {'c', '2'},
                             {'d', '3'}, {'e', '0'}, {'f', '1'},
                             {'g', '2'}, {'h', '0'}, {'i', '0'},
                             {'j', '2'}, {'k', '2'}, {'l', '4'},
                             {'m', '5'}, {'n', '5'}, {'o', '0'},
                             {'p', '1'}, {'q', '2'}, {'r', '6'},
                             {'s', '2'}, {'t', '3'}, {'u', '0'},
                             {'v', '1'}, {'w', '0'}, {'x', '2'},
                             {'y', '0'}, {'z', '2'}};
    return helper[c];
}

int main() {
    std::string pass, res;
    std::getline(std::cin, pass);

    res.push_back(pass[0]);

    for (int i = 1; i < pass.size(); ++i) {
        char symbol = convert(pass[i]);
        if (symbol == '0') continue;

        if (res.back() != symbol) {
            res.push_back(symbol);
        }
    }

    for (int i = 0; i < 3; ++i) {
        res.push_back('0');
    }

    for (int i = 0; i < std::min(4, static_cast<int>(res.size())); ++i) {
        std::cout << res[i];
    }
    std::cout << std::endl;
    return 0;
}