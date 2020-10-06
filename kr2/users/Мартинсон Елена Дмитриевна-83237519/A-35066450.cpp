#include <iostream>

class TimeLogger {
   private:
    double start_time = 0;

   public:
    TimeLogger() {
        start_time = Now();
    }
    ~TimeLogger() {
        std::cout << Now() - start_time << " milliseconds\n";
    }
};
