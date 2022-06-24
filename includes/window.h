
#ifndef WINDOW_H
# define WINDOW_H

# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <float.h>
# include "./minilibx/mlx.h"


# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

# define MAX_ITER (50)
# define IMG_HEIGHT (600)
# define IMG_WIDTH (600)
# define JULIA (2)
# define MANDELBROT (1)
# define ESC_PRESS(x) (x == 53 || x == 12)
# define LEFT_PRESS(x) (x == 123)
# define RIGHT_PRESS(x) (x == 124)
# define DOWN_PRESS(x) (x == 125)
# define UP_PRESS(x) (x == 126)

#endif