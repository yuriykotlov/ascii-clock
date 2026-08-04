//
// Created by yuriy on 04/08/2026.
//

#include "clock_time.h"

#include <chrono>
#include <vector>

extern inline std::tm get_clocktime() {
    const auto now = std::chrono::system_clock::now();
    const time_t now_t = std::chrono::system_clock::to_time_t(now);
    std::tm time{};
    localtime_s(&time, &now_t);
    return time;
}

extern inline void push_back_number(std::vector<int> &vec, const int number) {
    vec.push_back(number / 10);
    vec.push_back(number % 10);
}

extern inline std::vector<int> get_clocktime_vector(const std::tm time) {
    //std::cout << "\033[H" << std::put_time(time, "%H:%M:%S") << std::flush;

    std::vector<int> clocktime_vector{};

    push_back_number(clocktime_vector, time.tm_hour);
    push_back_number(clocktime_vector, time.tm_min);
    push_back_number(clocktime_vector, time.tm_sec);

    // for (int number : clocktime_vector) {
    //     std::cout << number;
    // }
    //
    // std::cout << std::endl;

    return clocktime_vector;
}