#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func, int retryCount, int sleepTime,
                                  bool throwLast) {
    Result res;
    for (int i = 0; i < retryCount; ++i) {
        try {
            res = func();
        } catch (Exception) {
            Sleep(sleepTime);
            continue;
        } catch (...) {
            throw;
        }
        return res;
    }
    try {
        res = func();
    } catch (Exception ex) {
        if (throwLast)
            throw ex;
        return {};
    } catch (...) {
        throw;
    }
    return res;
}
