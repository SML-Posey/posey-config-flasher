#include "BoardConfigs.h"

#define MaxConfigs 4
bool get_board_config(const uint8_t board, struct BoardConfig* config) {
    switch (board) {
        // w8/h1/r2 variety set
        case brd_w8_Thistle:
            *config = (struct BoardConfig){
                .name = "Posey w8 Thistle",
                .role = "watch",
                .hw = "v8.1",
                .sw = "1.1.0",
                .dt = "2023-02-06 15:24 EST"};
            return true;

        case brd_h1_Flox:
            *config = (struct BoardConfig){
                .name = "Posey h1 Flox",
                .role = "watch",
                .hw = "v8.1",
                .sw = "1.1.0",
                .dt = "2023-02-06 15:24 EST"};
            return true;

        case brd_r2_Tulip:
            *config = (struct BoardConfig){
                .name = "Posey r2 Tulip",
                .role = "ring",
                .hw = "r2.1",
                .sw = "1.1.0",
                .dt = "2023-02-06 15:24 EST"};
            return true;

        case brd_h1_Carnation:
            *config = (struct BoardConfig){
                .name = "Posey h1 Carnation",
                .role = "hub",
                .hw = "h1v8.1",
                .sw = "1.1.0",
                .dt = "2023-02-06 15:24 EST"};
            return true;

        // w8.2 r2.2
        case brd_r2_Indigo:
            *config = (struct BoardConfig){
                .name = "Posey r2 Indigo",
                .role = "ring",
                .hw = "r2.2",
                .sw = "1.1.0",
                .dt = "2023-05-24 15:24 EST"};
            return true;

        case brd_h1_Aster:
            *config = (struct BoardConfig){
                .name = "Posey h1 Aster",
                .role = "hub",
                .hw = "h1v8.2",
                .sw = "1.1.0",
                .dt = "2023-05-24 15:24 EST"};
            return true;

        // x2310
        case brd_w2310_Iris:
            *config = (struct BoardConfig){
                .name = "Posey r2310 Iris",
                .role = "ring",
                .hw = "r2310",
                .sw = "1.2.0",
                .dt = "2024-01-20 18:00 EST"};

        // x2405
        case brd_w2405_Lily:
            *config = (struct BoardConfig){
                .name = "Posey r2405 Lily",
                .role = "ring",
                .hw = "r2405",
                .sw = "1.3.0",
                .dt = "2024-06-14 18:00 EST"};
            return true;
        case brd_w2405_Poppy:
            *config = (struct BoardConfig){
                .name = "Posey r2405 Poppy",
                .role = "ring",
                .hw = "r2405",
                .sw = "1.3.0",
                .dt = "2024-06-21 18:00 EST"};
            return true;
        case brd_w2405_Violet:
            *config = (struct BoardConfig){
                .name = "Posey r2405 Violet",
                .role = "ring",
                .hw = "r2405",
                .sw = "1.3.0",
                .dt = "2024-06-24 18:00 EST"};
            return true;
        case brd_w2405_Rose:
            *config = (struct BoardConfig){
                .name = "Posey r2405 Rose",
                .role = "ring",
                .hw = "r2405",
                .sw = "1.3.0",
                .dt = "2024-06-24 18:00 EST"};
            return true;

        default:
            return false;
    }
}
