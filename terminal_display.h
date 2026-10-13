#ifndef TERMINAL_DISPLAY_H
#define TERMINAL_DISPLAY_H

#include <vector>

void enable_ansi_codes();

void display_clocktime_art(const std::vector<int> &time_vector);

#endif //TERMINAL_DISPLAY_H
