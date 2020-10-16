#include <exception>
#include <functional>
#include <optional>

/*#include <iostream>

int func() {
    std::cout << "function called\n";
    if (rand() % 4) {
        if (rand() % 2) {
            std::cout << "\tthrowing std::logic_error\n";
            throw std::logic_error("std::logic_error");
        }
        else {
            std::cout << "\tthrowing std::runtime_error\n";
            throw std::runtime_error("std::runtime_error");
        }
    }
    std::cout << "\timitated success\n";
    return 0;
}

void Sleep(int sleepTime) {
    std::cout << "sleeping\n";
}*/

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime,
                                  bool throwLast) {
    for (int i = 0; i <= retryCount; ++i) {
        try {
            auto result = func();
            return result;
        } catch (const Exception& _) {
            if (i < retryCount)
                Sleep(sleepTime);
            if (i == retryCount && throwLast)
                throw;
        }
    }
    return {};
}

/*int main() {
    int retryCount;
    std::cin >> retryCount;
    try {
        DoWithRetry<int, std::logic_error>(func, retryCount, 0, false);
    }
    catch (std::logic_error&) {
        std::cout << "exception LE\n";
    }
    catch (std::runtime_error&) {
        std::cout << "exception RE\n";
    }
    catch (...) {
        std::cout << "unknown exception\n";
    }
    return 0;
}
*/
