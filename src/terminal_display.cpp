#include "ascii_numbers.h"
#include "clock_time.h"

#include <iostream>
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

void display_clocktime_art(const std::vector<int> &time_vector) {
    std::vector<std::vector<std::string>> clocktime_art{};

    std::cout << "\033[H" << std::flush;

    for (int row = 0; row < MAX_ROWS_IN_NUMBER_ART; row++) {
        // make new row
        clocktime_art.emplace_back();

        for (int number_index = 0; number_index < MAX_CLOCKTIME_VEC_SIZE; number_index++) {
            // gets actual time number (e.g. 1-:--:--) in time_vector, and gets it art
            std::string combined_row{};

            combined_row.append(" ").append(ascii_numbers[time_vector[number_index]][row]);

            if (number_index != 0 && number_index != MAX_CLOCKTIME_VEC_SIZE - 1 && number_index % 2 != 0) {
                // the last item in the numbers vector is art of the ":" character
                combined_row.append(" ").append(ascii_numbers_colon[row]);
            }

            clocktime_art[row].push_back(combined_row);
        }

        // full row completed, display
        std::string full_row{};
        for (std::string number_string : clocktime_art[row]) {
            full_row += " " + number_string + " ";
        }

        std::cout << full_row << std::endl;
    }
}