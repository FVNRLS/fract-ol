# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 17:29:32 by rmazurit          #+#    #+#              #
#    Updated: 2022/07/27 15:39:08 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		fractol

CC 			= 		cc

FLAGS		= 		-Wall -Wextra -Werror

SRC 		= 		./main.c																	\
					./srcs/fractals/fractal_creater.c											\
					./srcs/fractals/fractal_printer.c											\
					./srcs/fractals/mandelbrot.c												\
					./srcs/fractals/julia.c														\
					./srcs/fractals/burning_ship.c												\
					./srcs/fractals/presets/presets_printer.c									\
					./srcs/fractals/presets/mandelbrot_psychedelic.c							\
					./srcs/fractals/presets/mandelbrot_standard.c								\
					./srcs/color_range_shifter/hex_rgb_converter.c								\
					./srcs/color_range_shifter/red_shifter.c									\
					./srcs/color_range_shifter/green_shifter.c									\
					./srcs/color_range_shifter/blue_shifter.c									\
					./srcs/colorizer/effects.c													\
					./srcs/colorizer/images/image_updater.c										\
					./srcs/colorizer/images/fractal_images.c									\
					./srcs/colorizer/mandelbrot_colorizer.c										\
					./srcs/colorizer/julia_colorizer.c											\
					./srcs/colorizer/burning_ship_colorizer.c									\
					./srcs/initializers/color_initializers/color_initializer.c					\
					./srcs/initializers/color_initializers/inside_color_initializer.c			\
					./srcs/initializers/color_initializers/outside_color_initializer.c			\
					./srcs/initializers/color_initializers/outline_color_initializer.c			\
					./srcs/initializers/mods_initializer.c										\
					./srcs/initializers/fractol_initializers.c									\
					./srcs/hooks_and_events/hooks_checker.c										\
					./srcs/hooks_and_events/key_hooks.c											\
					./srcs/hooks_and_events/vert_horiz_mover.c									\
					./srcs/hooks_and_events/mouse_hooks.c										\
					./srcs/hooks_and_events/zoomer.c											\
					./srcs/tools/memory_freer.c													\
					./srcs/tools/ft_atoi.c														\
					./srcs/tools/ft_atof.c														\
					./srcs/tools/ft_strcmp.c													\
					./srcs/io_controller/info_printer.c											\
					./srcs/io_controller/input_checker.c										\
					./srcs/io_controller/valid_param_printer.c									\

OBJ 		= 		${SRC:.c=.o}

LIBS		= 		./libs/ft_printf/libftprintf.a 												\

$(NAME): $(OBJ)
	make -C ./libs/minilibx
	make -C ./libs/ft_printf
	${CC} ${FLAGS} ${OBJ} ${LIBS} -o fractol ${FLAGS} -L ./libs/minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	cd ./libs/minilibx && make clean && cd .. && cd ..
	cd ./libs/ft_printf && make fclean && cd .. && cd ..
	rm -f ${OBJ}

fclean:
	cd ./libs/minilibx && make clean && cd .. && cd ..
	cd ./libs/ft_printf && make fclean && cd .. && cd ..
	rm -f ${OBJ}
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus