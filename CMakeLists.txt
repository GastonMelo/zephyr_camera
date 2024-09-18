cmake_minimum_required(VERSION 3.20.0)
set(DTC_OVERLAY_FILE "esp32.overlay")
set(BOARD esp32_devkitc_wroom)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(test03)

target_sources(app PRIVATE src/main.c)

