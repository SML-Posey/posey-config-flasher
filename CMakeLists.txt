cmake_minimum_required(VERSION 3.20.0)

macro(app_set_runner_args)
#   board_runner_args(dfu-util "--dfuse-modifiers=force:mass-erase")
#   board_runner_args(pyocd "--erase")
#   board_runner_args(nrfjprog "--recover")
endmacro()

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(nvs)


target_sources(app PRIVATE src/main.c src/BoardConfigs.c)
target_include_directories(app PRIVATE ${ZEPHYR_BASE}/subsys/fs/nvs)
