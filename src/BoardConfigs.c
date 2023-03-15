#include "BoardConfigs.h"

#define MaxConfigs 4
bool get_board_config(const uint8_t board, struct BoardConfig * config)
{
    switch (board)
    {

        // w8/h1/r2 variety set
        case brd_w8_Thistle:
            *config = (struct BoardConfig){
                .name = "Posey w8 Thistle",
                .role = "watch",
                .hw = "v8.1",
                .sw = "1.1.0",
                .dt = "2023-02-06 15:24 EST"
            };
            return true;
        
        case brd_w8_Flox:
            *config = (struct BoardConfig){
                .name = "Posey w8 Flox",
                .role = "watch",
                .hw = "v8.1",
                .sw = "1.1.0",
                .dt = "2023-02-06 15:24 EST"
            };
            return true;
        
        case brd_r2_Tulip:
            *config = (struct BoardConfig){
                .name = "Posey r2 Tulip",
                .role = "ring",
                .hw = "r2.1",
                .sw = "1.1.0",
                .dt = "2023-02-06 15:24 EST"
            };
            return true;
        
        case brd_h1_Carnation:
            *config = (struct BoardConfig){
                .name = "Posey h1 Carnation",
                .role = "hub",
                .hw = "h1v8.1",
                .sw = "1.1.0",
                .dt = "2023-02-06 15:24 EST"
            };
            return true;

        default:
            return false;
    }
}