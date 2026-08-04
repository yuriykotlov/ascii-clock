#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <vector>

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

std::vector<std::vector<std::string>> numbers = {
    {
        " ######## ",
        "##      ##",
        "##      ##",
        "##      ##",
        "##      ##",
        "##      ##",
        " ######## "
    },
 {
        "   ##   ",
        " ####   ",
        "   ##   ",
        "   ##   ",
        "   ##   ",
        "   ##   ",
        "########"
    },
 {
        " ######## ",
        "##      ##",
        "        ##",
        " ######## ",
        "##        ",
        "##        ",
        "##########"
    },
 {
        " ######## ",
        "##      ##",
        "        ##",
        " ######## ",
        "        ##",
        "##      ##",
        " ######## "
    },
 {
        " #    ## ",
        "##    ## ",
        "##    ## ",
        "#########",
        "      ## ",
        "      ## ",
        "      ## "
    },
 {
        "##########",
        "##        ",
        "##        ",
        "######### ",
        "        ##",
        "##      ##",
        " ######## "
    },
 {
        " ######## ",
        "##      ##",
        "##        ",
        "######### ",
        "##      ##",
        "##      ##",
        " ######## "
    },
 {
        " #########",
        "##      ##",
        "       ## ",
        "     ##   ",
        "    ##    ",
        "    ##    ",
        "    ##    "
    },
 {
        " ######## ",
        "##      ##",
        "##      ##",
        " ######## ",
        "##      ##",
        "##      ##",
        " ######## "
    },
 {
        " ######## ",
        "##      ##",
        "##      ##",
        " #########",
        "        ##",
        "##      ##",
        " ######## "
    },
 {
        "          ",
        "    ##    ",
        "    ##    ",
        "          ",
        "    ##    ",
        "    ##    ",
        "          ",
    }
};

// 2 digits for hour + 2 for minutes + 2 for seconds
constexpr int MAX_CLOCKTIME_VEC_SIZE{6};

// vertical size of numbers
constexpr int MAX_ROWS_IN_NUMBER_ART{7};

std::tm get_clocktime() {
    const auto now = std::chrono::system_clock::now();
    time_t now_t = std::chrono::system_clock::to_time_t(now);
    std::tm time{};
    localtime_s(&time, &now_t);
    return time;
}

void push_back_number(std::vector<int>* vec, int number) {
    vec->push_back(number / 10);
    vec->push_back(number % 10);
}

std::vector<int> get_clocktime_vector(std::tm time) {
    //std::cout << "\033[H" << std::put_time(time, "%H:%M:%S") << std::flush;

    std::vector<int> clocktime_vector{};

    // push_back adds 0 if value is <10 so that the time would be 01:--:-- instead of 1:--:--
    // to fit the format

    if (time.tm_hour < 10) {
        clocktime_vector.push_back(0);
        clocktime_vector.push_back(time.tm_hour);
    } else {
        push_back_number(&clocktime_vector, time.tm_hour);
    }

    if (time.tm_min < 10) {
        clocktime_vector.push_back(0);
        clocktime_vector.push_back(time.tm_min);
    } else {
        push_back_number(&clocktime_vector, time.tm_min);
    }

    if (time.tm_sec < 10) {
        clocktime_vector.push_back(0);
        clocktime_vector.push_back(time.tm_sec);
    } else {
        push_back_number(&clocktime_vector, time.tm_sec);
    }

    // for (int number : clocktime_vector) {
    //     std::cout << number;
    // }
    //
    // std::cout << std::endl;

    return clocktime_vector;
}

void display_clocktime_art(std::vector<int> time_vector) {
    std::vector<std::vector<std::string>> clocktime_art{};

    for (int row = 0; row < MAX_ROWS_IN_NUMBER_ART; row++) {
        // make new row
        clocktime_art.push_back({});

        for (int number_index = 0; number_index < MAX_CLOCKTIME_VEC_SIZE; number_index++) {
            // gets actual time number (e.g. 1-:--:--) in time_vector, and gets it art
            std::string this_row = numbers[time_vector[number_index]][row];

            if (number_index != 0 && number_index != MAX_CLOCKTIME_VEC_SIZE - 1 && number_index % 2 != 0) {
                // the last item in the numbers vector is art of the ":" character
                this_row += " " + numbers[numbers.size() - 1][row];
            }

            clocktime_art[row].push_back(this_row);
        }

        // full row completed, display
        std::string full_row{};
        for (std::string number_string : clocktime_art[row]) {
            full_row += " " + number_string + " ";
        }

        std::cout << full_row << std::endl;
    }

    std::cout << "\033[H" << std::flush;
}

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