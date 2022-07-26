# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 17:29:32 by rmazurit          #+#    #+#              #
#    Updated: 2022/07/26 11:35:18 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		fractol

CC 			= 		cc

FLAGS		= 		-Wall -Wextra -Werror -g3

SRC 		= 		./main.c																\
					./fractals/fractal_creater.c											\
					./fractals/fractal_printer.c											\
					./fractals/mandelbrot.c													\
					./fractals/julia.c														\
					./fractals/burning_ship.c												\
					./fractals/presets/presets_printer.c									\
					./fractals/presets/mandelbrot_psychedelic.c								\
					./fractals/presets/mandelbrot_standard.c								\
					./color_range_shifter/hex_rgb_converters.c								\
					./color_range_shifter/red_shifter.c										\
					./color_range_shifter/green_shifter.c									\
					./color_range_shifter/blue_shifter.c									\
					./colorizer/effects.c													\
					./colorizer/images/image_updater.c										\
					./colorizer/images/fractal_images.c										\
					./colorizer/mandelbrot_colorizer.c										\
					./colorizer/julia_colorizer.c											\
					./colorizer/burning_ship_colorizer.c									\
					./initializers/color_initializers/color_initializer.c					\
					./initializers/color_initializers/inside_color_initializer.c			\
					./initializers/color_initializers/outside_color_initializer.c			\
					./initializers/color_initializers/outline_color_initializer.c			\
					./initializers/mods_initializer.c										\
					./initializers/fractol_initializers.c									\
					./hooks_and_events/hooks_checker.c										\
					./hooks_and_events/key_hooks.c											\
					./hooks_and_events/vert_horiz_mover.c									\
					./hooks_and_events/mouse_hooks.c										\
					./hooks_and_events/zoomer.c												\
					./tools/memory_freer.c													\
					./tools/ft_atoi.c														\
					./tools/ft_atof.c														\
					./tools/ft_strcmp.c														\
					./io_controller/error_printer.c											\
					./io_controller/input_checkers.c										\

OBJ 		= 		${SRC:.c=.o}

LIBS		= 		./libs/ft_printf/libftprintf.a 											\

$(NAME): $(OBJ)
	make -C ./libs/minilibx
	make -C ./libs/ft_printf
	${CC} ${FLAGS} ${OBJ} ${LIBS} -o fractol ${FLAGS} -L ./libs/minilibx -lmlx -framework OpenGL -framework AppKit
	make clean

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

bonus: all

.PHONY: all clean fclean re bonus