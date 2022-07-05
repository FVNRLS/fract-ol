cmake_minimum_required(VERSION 3.22)
project(fractol C)

set(CMAKE_C_STANDARD 99)

add_executable(fractol main.c fractals/mandelbrot.c fractals/window.c fractal_creater.c error_manager.c includes/error_flags.h colorizer/colorizer.c includes/colors.h initializers/color_initializers/color_initializer.c initializers/fractol_initializers.c initializers/color_initializers/inside_color_initializer.c initializers/color_initializers/outside_color_initializer.c colorizer/hex_rgb_converters.c colorizer/rgb_to_hex_converter.c)
