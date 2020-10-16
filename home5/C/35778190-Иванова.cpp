#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func,
                                int retryCount, int sleepTime, bool throwLast) {
    for (; retryCount >= 0; --retryCount) {
        try {
            Result res = func();
            return res;
        } catch (Exception) {
            if (retryCount == 0 && throwLast)
                throw;
            else if (retryCount != 0)
                Sleep(sleepTime);
        }
    }
    return {};
}
