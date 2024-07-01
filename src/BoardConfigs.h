#pragma once

#include <stdbool.h>
#include <stdint.h>

struct BoardConfig {
        const char* name;
        const char* role;
        const char* hw;
        const char* sw;
        const char* dt;
};

// w8.1/h1/r2.1 variety set
#define brd_w8_Thistle 0
#define brd_h1_Flox 1
#define brd_r2_Tulip 2
#define brd_h1_Carnation 3

// w8.2/r2.2 variety set
#define brd_r2_Indigo 4
#define brd_h1_Aster 5

// x2310
#define brd_w2310_Iris 6

// x2405
#define brd_w2405_Lily 7    // BNO086
#define brd_w2405_Poppy 8   // BNO086
#define brd_w2405_Violet 9  // BNO086
#define brd_w2405_Rose 10   // BNO085*

bool get_board_config(const uint8_t board, struct BoardConfig* config);
