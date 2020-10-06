#include <iostream>

long Now();

class TimeLogger {
    long start;

public:
    TimeLogger() : start(Now()) {
    }

    ~TimeLogger() {
        std::cout << Now() - start << " milliseconds\n";
    }
};
