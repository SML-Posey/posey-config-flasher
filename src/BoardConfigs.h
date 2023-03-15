#pragma once

#include <stdint.h>
#include <stdbool.h>

struct BoardConfig
{
	const char * name;
	const char * role;
	const char * hw;
	const char * sw;
	const char * dt;
};

// w8.1/h1/r2.1 variety set
#define brd_w8_Thistle 0
#define brd_w8_Flox 1
#define brd_r2_Tulip 2
#define brd_h1_Carnation 3

bool get_board_config(const uint8_t board, struct BoardConfig * config);