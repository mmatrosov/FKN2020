#include <iostream>

class TimeLogger {
private:
    long begin_time;
public:
    TimeLogger(): begin_time(Now()) {}

    ~TimeLogger() {
        std::cout << Now() - begin_time << " milliseconds\n";
    }
};
