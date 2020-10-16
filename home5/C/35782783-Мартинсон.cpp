#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime,
                                  bool throwLast) {
    for (int i = 0; i <= retryCount; ++i) {
        try {
            return func();
        } catch (Exception) {
            if (retryCount == i) {
                if (throwLast) {
                    throw;
                } else {
                    std::optional<Result> em;
                    return em;
                }
            }
            Sleep(sleepTime);
        }
    }
}

/*
std::optional<int> f() {
    std::optional<int> a;
    return a;
}

int main() {
    DoWithRetry<int>(f, 10, 10, true);

    return 0;
}
*/
