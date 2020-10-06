#include <iostream>

class TimeLogger {
 private:
    long start;

 public:
    TimeLogger() {
        start = Now();
    }

    ~TimeLogger() {
        std::cout << Now() - start << " milliseconds\n";
    }
};