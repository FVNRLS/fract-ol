/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/20 13:05:32 by rmazurit         ###   ########.fr       */
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

typedef struct s_fract
{
    double  c_re;
    double  c_im;
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

}        t_fract;


//ADDITIONAL MLX FUNCTIONS
void	my_mlx_pixel_put(t_gui *data, int x, int y, int color);

//FRACTALS
void    print_fractal(int argc, char **argv);
void    print_3D_mandelbrot(t_gui *gui, t_color *color);
void    print_basic_mandelbrot(t_gui *gui, t_color *color);
void    print_psychedelic_mandelbrot(t_gui *gui, t_color *color);

//PRESETS
void    print_preset(char **argv, t_gui *gui, t_color *color);
void    print_mandelbrot_matrix(t_gui *gui);
void    print_mandelbrot_std_blue(t_gui *gui);
void    print_mandelbrot_std_red(t_gui *gui);
void    print_mandelbrot_std_teal(t_gui *gui);
void    print_mandelbrot_std_green(t_gui *gui);
void    print_mandelbrot_psych_acid(t_gui *gui);


//TOOLS
int	ft_strncmp(const char *s1, const char *s2, size_t n);

//ERRORS
void    print_error(int error);
void    check_mandelbrot(int argc, t_gui *gui, t_color *color);
bool    check_mandelbrot_args(int argc, t_gui *gui, t_color *color);
bool    check_mandelbrot_colors(int argc, t_gui *gui, t_color *color);

//INITIALIZERS
void    init_mandelbrot(t_fract *fr);
void    init_colors(char **argv, t_color *color, t_gui *gui);
void    init_main_inside_colors(char **argv, t_color *color);
void    init_additional_inside_colors(char **argv, t_color *color);
void    init_main_outside_colors(char **argv, t_color *color);
void    init_additional_outside_colors(char **argv, t_color *color);
void    init_main_outline_colors(char **argv, t_color *color);
void    init_additional_outline_colors(char **argv, t_color *color);


//COLORIZER
int	get_transparency(int trgb);
int	get_red(int trgb);
int	get_green(int trgb);
int	get_blue(int trgb);
int	convert_rgb_to_hex(int t, int r, int g, int b);
int new_bgr_gradient(int trgb, double mod);
int new_outln_gradient(int trgb, double mod);
int new_aura(int trgb, t_fract *fr);
void    colorize_with_gradient(t_gui *img, t_fract *fr, t_color *color);
void    colorize_with_basic_colors(t_gui *img, t_fract *fr, t_color *color);
void    colorize_with_aura(t_gui *img, t_fract *fr, t_color *color);

//WINDOW KEY HOOKS
void    check_win_hooks(t_gui *gui);
int	    close_win(int keycode, t_gui *gui);


#endif