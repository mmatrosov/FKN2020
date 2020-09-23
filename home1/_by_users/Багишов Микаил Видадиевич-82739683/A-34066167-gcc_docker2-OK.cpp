#include <iostream>
#include <string>

bool is_password_valid(std::string const &pw) {
    if (pw.size() < 8 || pw.size() > 14) {
        return false;
    }
    for (char const &ch : pw) {
        auto code = static_cast<uint8_t>(ch);
        if (code < 33 || code > 126) {
            return false;
        }
    }
    int used_character_classes = 0;
    // uppercase
    for (char const ch : pw) {
        if (isupper(ch)) {
            ++used_character_classes;
            break;
        }
    }
    // lowercase
    for (char const ch : pw) {
        if (islower(ch)) {
            ++used_character_classes;
            break;
        }
    }
    // digits
    for (char const ch : pw) {
        if (isdigit(ch)) {
            ++used_character_classes;
            break;
        }
    }
    // others
    for (char const ch : pw) {
        if (!isalnum(ch)) {
            ++used_character_classes;
            break;
        }
    }
    return used_character_classes >= 3;
}

int main() {
    std::string password;
    std::cin >> password;
    if (is_password_valid(password)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}