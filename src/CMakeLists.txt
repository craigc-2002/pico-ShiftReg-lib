cmake_minimum_required(VERSION 3.13)

file(GLOB FILES *.cpp *.hpp)
add_library(pico-ShiftReg-lib ${FILES})
target_link_libraries(pico-ShiftReg-lib pico_stdlib)
target_include_directories(pico-ShiftReg-lib PUBLIC ../include)
