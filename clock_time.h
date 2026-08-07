//
// Created by yuriy on 04/08/2026.
//

#ifndef ASCII_CLOCK_CLOCK_TIME_H
#define ASCII_CLOCK_CLOCK_TIME_H

#include <chrono>
#include <vector>

// 2 digits for hour + 2 for minutes + 2 for seconds
constexpr int MAX_CLOCKTIME_VEC_SIZE{6};

std::tm get_clocktime();

void push_back_number(std::vector<int> &vec, const int number);

std::vector<int> get_clocktime_vector(const std::tm &time);

#endif //ASCII_CLOCK_CLOCK_TIME_H
