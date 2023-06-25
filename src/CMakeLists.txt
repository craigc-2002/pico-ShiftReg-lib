cmake_minimum_required(VERSION 3.13)

file(GLOB FILES *.cpp *.hpp)
add_library(pico-74hc595-lib ${FILES})
target_link_libraries(pico-74hc595-lib pico_stdlib)
target_include_directories(pico-74hc595-lib PUBLIC ../include)
