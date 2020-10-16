#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func,
    int retryCount, int sleepTime, bool throwLast) {
    int call_number = 0;
    std::optional<Result> ans;
    while (call_number <= retryCount) {
        try {
            ans = func();
            break;
        }
        catch (Exception) {
            if (call_number != retryCount) {
                Sleep(sleepTime);
            } else {
                if (throwLast) {
                    throw;
                }
            }
        }
        ++call_number;
    }
    return ans;
}