
#ifndef WINDOW_H
# define WINDOW_H

typedef struct	s_gui
{
    void	*mlx;
    void	*win;
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}	    t_gui;

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

# define ESC_PRESS(x) (x == 53 || x == 12)
# define LEFT_PRESS(x) (x == 123)
# define RIGHT_PRESS(x) (x == 124)
# define DOWN_PRESS(x) (x == 125)
# define UP_PRESS(x) (x == 126)

#endif