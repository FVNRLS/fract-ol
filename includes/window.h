
#ifndef WINDOW_H
# define WINDOW_H

# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <float.h>
# include "../minilibx/mlx.h"


# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

# define ESC_PRESS(x) (x == 53 || x == 12)
# define LEFT_PRESS(x) (x == 123)
# define RIGHT_PRESS(x) (x == 124)
# define DOWN_PRESS(x) (x == 125)
# define UP_PRESS(x) (x == 126)

#endif