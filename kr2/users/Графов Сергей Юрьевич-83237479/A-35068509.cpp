#include<iostream>

struct TimeLogger {
private:
    long time;
public:
    TimeLogger() {
        time = Now();
    }
    ~TimeLogger() {
        std::cout << Now() - time << " milliseconds\n";
    }
};