#include <iostream>
// #include <cctype> -- seems to be included in iostream
#include <numeric>

bool check(std::string password) {
    for (char c : password)
        if (c < 33 || c > 126)
            return false;
    if (password.length() < 8 || password.length() > 14)
        return false;
    bool has_classes[4] = {0, 0, 0, 0};  // uppercase, lowercase, digits, others
    for (char c : password) {
        has_classes[0] |= isupper(c);
        has_classes[1] |= islower(c);
        has_classes[2] |= isdigit(c);
        has_classes[3] |= !isupper(c) && !islower(c) && !isdigit(c);
    }
    return std::accumulate(has_classes, has_classes + 4, 0) >= 3;
}

int main() {
    std::string password;
    getline(std::cin, password);
    std::cout << (check(password) ? "YES" : "NO");
    return 0;
}
