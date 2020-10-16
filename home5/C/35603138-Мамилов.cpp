#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(
                                  std::function<Result()> func,
                                  int retryCount,
                                  int sleepTime,
                                  bool throwLast) {
    for (int i = 0; i < retryCount; ++i) {
        try {
            return std::optional<Result>{func()};
        } catch (Exception e) {
            Sleep(sleepTime);
        }
    }
    try {
        return std::optional<Result>{func()};
    } catch (Exception e) {
        if (throwLast)
            throw e;
        else
            return std::nullopt;
    }
}
