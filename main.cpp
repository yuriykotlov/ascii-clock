#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

void enable_ansi_codes() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hConsole, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hConsole, dwMode);
}

void get_clocktime(std::tm* time) {
    const auto now = std::chrono::system_clock::now();
    time_t now_t = std::chrono::system_clock::to_time_t(now);
    localtime_s(time, &now_t);
}

void display_clocktime(std::tm* time) {
    std::cout << "\033[H" << std::put_time(time, "%H:%M:%S") << std::flush;
}

void run_clock() {
    struct std::tm time{};

     while (true) {
         get_clocktime(&time);
         display_clocktime(&time);
         std::this_thread::sleep_for(std::chrono::seconds(1));
     }
}

int main() {
    enable_ansi_codes();
    run_clock();
    return 0;
}