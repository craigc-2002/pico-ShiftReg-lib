add_executable(count
	count.cpp
)

target_link_libraries(count pico_stdlib pico-74hc595-lib)

pico_enable_stdio_uart(count 0)
pico_enable_stdio_usb(count 1)

pico_add_extra_outputs(count)
