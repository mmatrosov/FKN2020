#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func,
    int retryCount,
    int sleepTime,
    bool throwLast) {
    while (true) {
        try {
            return func();
        } catch (Exception) {
            if (retryCount == 0) {
                if (throwLast) {
                    throw;
                }
                return std::optional<Result>();
            }
            Sleep(sleepTime);
        }
        --retryCount;
    }
}