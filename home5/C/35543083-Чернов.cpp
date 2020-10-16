#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime,
                                  bool throwLast) {
    for (int i = 0; i <= retryCount; ++i) {
        Result result;
        try {
            result = func();
        } catch (const Exception&) {
            if (i == retryCount) {
                if (!throwLast) {
                    return std::nullopt;
                }
                throw;
            }
            Sleep(sleepTime);
            continue;
        }
        return result;
    }
}