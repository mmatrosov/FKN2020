#include <iostream>
#include <string>

int main() {
    std::string password;
    std::cin >> password;
    bool first_condition = true;
    bool second_condition = (8 <= password.length() && password.length() <= 14);
    bool third_condition;
    bool symbol_types[4];
    for (int i = 0; i < 4; i++)
        symbol_types[i] = 0;
    for (const char& symbol : password) {
        first_condition &= (33 <= symbol && symbol <= 126);
        if (islower(symbol)) {
            symbol_types[0] = true;
        } else {
            if (isupper(symbol)) {
                symbol_types[1] = true;
            } else {
                if (isdigit(symbol)) {
                    symbol_types[2] = true;
                } else {
                    symbol_types[3] = true;
                }
            }
        }
    }
    third_condition = (symbol_types[0] + symbol_types[1] + symbol_types[2] + symbol_types[3] >= 3);
    if (first_condition & second_condition & third_condition) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}
