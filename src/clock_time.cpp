#include "clock_time.h"

std::tm get_clocktime() {
    const auto now = std::chrono::system_clock::now();
    const time_t now_t = std::chrono::system_clock::to_time_t(now);
    std::tm time{};

#ifdef _WIN32
    localtime_s(&time, &now_t);
#else
    localtime_r(&now_t, &time);
#endif

    return time;
}

void push_back_number(std::vector<int> &vec, const int number) {
    vec.push_back(number / 10);
    vec.push_back(number % 10);
}

std::vector<int> get_clocktime_vector(const std::tm &time) {
    std::vector<int> clocktime_vector{};

    push_back_number(clocktime_vector, time.tm_hour);
    push_back_number(clocktime_vector, time.tm_min);
    push_back_number(clocktime_vector, time.tm_sec);

    return clocktime_vector;
}