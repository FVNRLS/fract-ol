# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 17:29:32 by rmazurit          #+#    #+#              #
#    Updated: 2022/07/23 18:25:04 by rmazurit         ###   ########.fr        #
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
					./fractals/presets/presets_printer.c									\
					./fractals/presets/mandelbrot_psychedelic.c								\
					./fractals/presets/mandelbrot_standard.c								\
					./colorizer/colorizer.c													\
					./colorizer/hex_rgb_converters.c										\
					./colorizer/mandelbrot_colorizer.c										\
					./colorizer/julia_colorizer.c											\
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
					./tools/ft_strlen.c														\
					./tools/ft_strncmp.c													\
					./error_manager.c														\

OBJ 		= 		${SRC:.c=.o}

$(NAME): $(OBJ)
	make -C ./minilibx
	${CC} ${FLAGS} ${OBJ} -o fractol ${FLAGS} -L ./minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

# bonus: ${BONUS_NAME}

clean:
	rm -f ${OBJ}
	cd ./minilibx && make clean && cd ..

fclean: clean
	rm -f ${NAME}
	cd ./minilibx && make clean && cd ..

re: fclean all


.PHONY: all clean fclean re bonus




##add alater to compile without errors (see Makefile from Anna):
# -L ./minilibx -lmlx -framework OpenGL -framework AppKit