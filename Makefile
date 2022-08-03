# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 17:29:32 by rmazurit          #+#    #+#              #
#    Updated: 2022/08/03 18:22:08 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		fractol

CC 			= 		cc

FLAGS		= 		-Wall -Wextra -Werror

SRC 		= 		./main.c																	\
					./src/fractals/fractal_creater.c											\
					./src/fractals/fractal_printer.c											\
					./src/fractals/mandelbrot.c												\
					./src/fractals/julia.c														\
					./src/fractals/burning_ship.c												\
					./src/fractals/presets/presets_printer.c									\
					./src/fractals/presets/mandelbrot_psychedelic.c							\
					./src/fractals/presets/mandelbrot_standard.c								\
					./src/color_range_shifter/hex_rgb_converter.c								\
					./src/color_range_shifter/red_shifter.c									\
					./src/color_range_shifter/green_shifter.c									\
					./src/color_range_shifter/blue_shifter.c									\
					./src/colorizer/effects.c													\
					./src/colorizer/images/image_updater.c										\
					./src/colorizer/images/fractal_images.c									\
					./src/colorizer/mandelbrot_colorizer.c										\
					./src/colorizer/julia_colorizer.c											\
					./src/colorizer/burning_ship_colorizer.c									\
					./src/initializers/color_initializers/color_initializer.c					\
					./src/initializers/color_initializers/inside_color_initializer.c			\
					./src/initializers/color_initializers/outside_color_initializer.c			\
					./src/initializers/color_initializers/outline_color_initializer.c			\
					./src/initializers/mods_initializer.c										\
					./src/initializers/fractol_initializers.c									\
					./src/hooks_and_events/hooks_checker.c										\
					./src/hooks_and_events/key_hooks.c											\
					./src/hooks_and_events/vert_horiz_mover.c									\
					./src/hooks_and_events/mouse_hooks.c										\
					./src/hooks_and_events/zoomer.c											\
					./src/tools/memory_freer.c													\
					./src/tools/ft_atoi.c														\
					./src/tools/ft_atof.c														\
					./src/tools/ft_strcmp.c													\
					./src/io_controller/info_printer.c											\
					./src/io_controller/input_checker.c										\
					./src/io_controller/valid_param_printer.c									\

OBJ 		= 		${SRC:.c=.o}

LIBS		= 		./lib/ft_printf/libftprintf.a 												\

$(NAME): $(OBJ)
	make -C ./lib/minilibx
	make -C ./lib/ft_printf
	${CC} ${FLAGS} ${OBJ} ${LIBS} -o fractol ${FLAGS} -L ./lib/minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	cd ./lib/minilibx && make clean && cd .. && cd ..
	cd ./lib/ft_printf && make fclean && cd .. && cd ..
	rm -f ${OBJ}

fclean:
	cd ./lib/minilibx && make clean && cd .. && cd ..
	cd ./lib/ft_printf && make fclean && cd .. && cd ..
	rm -f ${OBJ}
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re