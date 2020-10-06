#include <iostream>

class TimeLogger {
private:
    double start_time;
public:
    TimeLogger() : start_time(Now()) {}

    ~TimeLogger() {
        std::cout << Now() - start_time << " milliseconds\n";
    }
};