#include <iostream>
#include <thread>

#include "clock_time.cpp"
#include "terminal_display.cpp"

void run_clock() {
     while (true) {
         display_clocktime_art(get_clocktime_vector(get_clocktime()));
         std::this_thread::sleep_for(std::chrono::seconds(1));
     }
}

int main() {
    enable_ansi_codes();
    run_clock();

    return 0;
}