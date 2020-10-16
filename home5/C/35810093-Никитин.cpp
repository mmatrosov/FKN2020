#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime,
                                  bool throwLast) {
    for (int i = 0; i <= retryCount; ++i) {
        try {
            return func();
        } catch (Exception exc) {
            if (i == retryCount && throwLast) {
                throw exc;
                break;
            }
            if (i < retryCount) {
                Sleep(sleepTime);
            }
        }
    }
}