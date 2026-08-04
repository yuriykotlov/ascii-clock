//
// Created by yuriy on 04/08/2026.
//

#ifndef ASCII_CLOCK_ASCII_ART_H
#define ASCII_CLOCK_ASCII_ART_H

#include <array>
#include <string_view>

// vertical size of numbers
inline constexpr int MAX_ROWS_IN_NUMBER_ART{7};

inline constexpr std::array<std::array<std::string_view, MAX_ROWS_IN_NUMBER_ART>, 11> ascii_numbers{
        {
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
                        "    ##   ",
                        " #####   ",
                        "    ##   ",
                        "    ##   ",
                        "    ##   ",
                        "    ##   ",
                        "##########"
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
        }
};

inline constexpr auto ascii_numbers_colon{ascii_numbers[ascii_numbers.size() - 1]};

#endif //ASCII_CLOCK_ASCII_ART_H
