# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 17:29:32 by rmazurit          #+#    #+#              #
#    Updated: 2022/07/04 11:46:08 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		fractol

CC 			= 		cc

FLAGS		= 		-Wall -Wextra -Werror -g3

SRC 		= 		./main.c											\
					./fractals/mandelbrot.c								\
					./fractal_creater.c									\
					./error_manager.c									\
					./tools/ft_strncmp.c								\

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