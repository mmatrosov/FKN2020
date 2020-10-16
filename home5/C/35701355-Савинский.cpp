#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime,
                                  bool throwLast) {
    for (size_t iter = 0; iter <= retryCount; ++iter) {
        try {
            return func();
        } catch (Exception) {
            if (iter == retryCount && throwLast) {
                throw;
            }
            if (iter == retryCount) {
                break;
            }
            Sleep(sleepTime);
        }
    }
    return std::nullopt;
}
