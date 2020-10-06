#include <iostream>

class TimeLogger {
    long start;

public:
    TimeLogger() {
        start = Now();
    }
    ~TimeLogger() {
        std::cout << Now() - start << " milliseconds\n";
    }
};