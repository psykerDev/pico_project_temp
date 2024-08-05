cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(pico_base C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

#set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

set(PICO_BOARD pico_w)



add_executable(blink blink.c)



#pico_enable_stdio_usb(blink 1)
#pico_enable_stdio_uart(hello_world 0)

pico_add_extra_outputs(blink)

#target_include_directories(blink PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(blink pico_stdlib
pico_cyw43_arch_none )
