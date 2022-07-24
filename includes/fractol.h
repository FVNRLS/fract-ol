/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/24 11:20:39 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# include "../minilibx/mlx.h"
# include "colors.h"
# include "error_flags.h"
# include "hooks.h"
# include "window.h"

//FRACTAL TYPES MACROS
# define MANDELBROT_3D              1
# define MANDELBROT_STD             2
# define MANDELBROT_PSYCHEDELIC     3
# define JULIA                      4


typedef struct s_fract
{
    double  c_re;
    double  c_im;
    double  j_re;
    double  j_im;
    double  z;
    double  z_re;
    double  z_im;
    double  sum_re;
    double  sum_im;
    int     x_cor;
    int     y_cor;
    int     iter;
    int     max_iter;
    bool    left_padded;
    double  horiz;
    double  vert;
    double  vert_mod;
    double  horiz_mod;
    int     type;
    double  zoom_mod;
    double  zoom_x_mod;
    double  zoom_y_mod;
}        t_fract;

typedef struct s_color
{
    int     in;
    int     out;
    int     outln;
    bool    preset_found;
}           t_color;

typedef struct	s_gui
{
    void	*mlx;
    void	*win;
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
    double  mouse_x_pos;
    double  mouse_y_pos;

    t_fract    *fract;
    t_color    *color;
}	    t_gui;

//ADDITIONAL MLX FUNCTIONS
void	my_mlx_pixel_put(t_gui *data, int x, int y, int color);

//FRACTALS
void    print_fractal(int argc, char **argv);
void    print_mandelbrot(int argc, char **argv, t_gui *gui, t_fract *fr, t_color *color);
void    print_3D_mandelbrot(t_gui *gui, t_fract *fr, t_color *color);
void    print_standard_mandelbrot(t_gui *gui, t_fract *fr, t_color *color);
void    print_psychedelic_mandelbrot(t_gui *gui, t_fract *fr, t_color *color);
void    print_julia(int argc, char **argv, t_gui *gui, t_fract *fr, t_color *color);
void    print_standard_julia(t_gui *gui, t_fract *fr, t_color *color);
void    update_image_to_julia(t_gui *gui, t_fract *fr, t_color *color);

//PRESETS
void    check_presets(int keycode, t_gui *gui);
bool    check_print_preset(char **argv, t_gui *gui, t_fract *fr, t_color *color);
void    update_image_to_3D(t_gui *gui, t_fract *fr, t_color *color);
void    update_image_to_standard(t_gui *gui, t_fract *fr, t_color *color);
void    update_image_to_psychedelic(t_gui *gui, t_fract *fr, t_color *color);
void    print_mandelbrot_matrix(t_gui *gui, t_fract *fr, t_color *color);
void    print_mandelbrot_std_blue(t_gui *gui, t_fract *fr, t_color *color);
void    print_mandelbrot_std_red(t_gui *gui, t_fract *fr, t_color *color);
void    print_mandelbrot_std_teal(t_gui *gui, t_fract *fr, t_color *color);
void    print_mandelbrot_std_green(t_gui *gui, t_fract *fr, t_color *color);
void    print_mandelbrot_psych_acid(t_gui *gui, t_fract *fr, t_color *color);
void    print_mandelbrot_psych_cmyk(t_gui *gui, t_fract *fr, t_color *color);
void    print_mandelbrot_psych_depressive(t_gui *gui, t_fract *fr, t_color *color);
void    print_mandelbrot_psych_bloody(t_gui *gui, t_fract *fr, t_color *color);
void    print_mandelbrot_psych_ugly(t_gui *gui, t_fract *fr, t_color *color);

//TOOLS
double	ft_atof(const char *s);
int	    ft_atoi(const char *str);
int     ft_strlen(char *str);
int	    ft_strcmp(const char *s1, const char *s2);
void    free_all(t_gui *gui);

//ERRORS
void    print_error(int error);
void    check_mandelbrot(int argc, t_gui *gui, t_color *color);
void    check_mandelbrot_presets(char **argv, t_gui *gui, t_fract *fr, t_color *color);
void    check_mandelbrot_args(int argc, t_gui *gui);
void    check_colors(t_gui *gui, t_color *color);
void    check_julia_args(int argc, t_gui *gui);

//INITIALIZERS
void    init_mandelbrot(t_fract *fr);
void    init_julia(t_fract *fr);
void    init_colors(char **argv, t_color *color);
void    init_main_inside_colors(char **argv, t_color *color);
void    init_additional_inside_colors(char **argv, t_color *color);
void    init_main_outside_colors(char **argv, t_color *color);
void    init_additional_outside_colors(char **argv, t_color *color);
void    init_main_outline_colors(char **argv, t_color *color);
void    init_additional_outline_colors(char **argv, t_color *color);
void    init_mods(t_fract *fr);
void    check_mods(t_gui *gui);
void    apply_mods(t_gui *gui);

//COLORIZER
int	    get_transparency(int trgb);
int	    get_red(int trgb);
int	    get_green(int trgb);
int	    get_blue(int trgb);
int	    convert_rgb_to_hex(int t, int r, int g, int b);
int     new_bgr_gradient(int trgb, double mod);
int     new_outln_gradient(int trgb, double mod);
int     new_aura(int trgb, t_fract *fr);
void    colorize_img_to_black(t_gui *gui);
void    colorize_with_gradient(t_gui *img, t_fract *fr, t_color *color);
void    colorize_julia_with_gradient(t_gui *img, t_fract *fr, t_color *color);
void    colorize_with_basic_colors(t_gui *img, t_fract *fr, t_color *color);
void    colorize_with_aura(t_gui *img, t_fract *fr, t_color *color);

/* HOOKS */
void    check_win_hooks(t_gui *gui);

//ARROW KEYS HOOKS
void    check_arrow_keys(int keycode, t_gui *gui);
void    move_up(t_gui *gui);
void    move_down(t_gui *gui);
void    move_left(t_gui *gui);
void    move_right(t_gui *gui);

//MOUSE KEY/WHEEL HOOKS
int     check_mouse_hooks(int keycode, int x, int y, t_gui *gui);
int	    close_window(t_gui *gui);
void    zoom_in(t_gui *gui);
void    zoom_out(t_gui *gui);


#endif