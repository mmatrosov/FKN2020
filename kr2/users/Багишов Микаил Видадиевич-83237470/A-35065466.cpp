#include <iostream>

long Now();

class TimeLogger {
    long begin_time;

public:
    TimeLogger() : begin_time(Now()) {
    }

    ~TimeLogger() {
        long end_time = Now();
        std::cout << (end_time - begin_time) << " milliseconds\n";
    }
};