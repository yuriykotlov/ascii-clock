//
// Created by crims on 07/08/2026.
//

#ifndef ASCII_CLOCK_TERMINAL_DISPLAY_H
#define ASCII_CLOCK_TERMINAL_DISPLAY_H

#include <vector>

void enable_ansi_codes();

void display_clocktime_art(const std::vector<int> &time_vector);

#endif //ASCII_CLOCK_TERMINAL_DISPLAY_H
