#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime,
                                  bool throwLast) {
    for (int attempt = 0; attempt <= retryCount; ++attempt) {
        try {
            Result res = func();
            return {res};  //
        } catch (Exception const& exc) {
            if (attempt == retryCount) {  //
                if (throwLast) {
                    throw;
                } else {
                    return std::nullopt;
                }
            }
            Sleep(sleepTime);
        }
    }
}