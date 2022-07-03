cmake_minimum_required(VERSION 3.22)
project(fractol C)

set(CMAKE_C_STANDARD 99)

add_executable(fractol main.c fractals/mandelbrot.c fractals/window.c window.c)
