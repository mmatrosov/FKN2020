#include <iostream>

class TimeLogger {
    long start_time;

public:
    TimeLogger() {
        start_time = Now();
    }
    ~TimeLogger() {
        std::cout << Now() - start_time << " milliseconds\n";
    }
};
