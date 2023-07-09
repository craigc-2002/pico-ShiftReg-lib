add_executable(fill
	fill.cpp
)

target_link_libraries(fill pico_stdlib pico-ShiftReg-lib)

pico_enable_stdio_uart(fill 0)
pico_enable_stdio_usb(fill 1)

pico_add_extra_outputs(fill)
