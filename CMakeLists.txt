cmake_minimum_required(VERSION 3.22)
project(fractol C)

set(CMAKE_C_STANDARD 99)

add_executable(fractol main.c fractals/mandelbrot.c fractals/window.c fractal_creater.c error_manager.c includes/error_flags.h colorizer/colorizer.c includes/colors.h initializers/color_initializers/color_initializer.c initializers/fractol_initializers.c initializers/color_initializers/inside_color_initializer.c initializers/color_initializers/outside_color_initializer.c colorizer/hex_rgb_converters.c colorizer/rgb_to_hex_converter.c initializers/color_initializers/outline_color_initializer.c colorizer/colorize_mandelbrot.c includes/hooks.h hooks_and_events/key_hooks.c hooks_and_events/mouse_hooks.c fractals/presets/mandelbrot_standard.c fractals/presets/mandelbrot_psychedelic.c fractals/presets/presets_printer.c tools/memory_freer.c initializers/mods_initializer.c hooks_and_events/vert_horiz_mover.c hooks_and_events/hooks_checker.c)
