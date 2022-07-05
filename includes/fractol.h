/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/05 15:53:56 by rmazurit         ###   ########.fr       */
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
    int     max_iter;
}        t_fract;

//ADDITIONAL MLX FUNCTIONS
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//FRACTALS
void    print_mandelbrot(t_data *img, t_color *color, char **argv);
void    print_fractal(char **argv);

//TOOLS
int	ft_strncmp(const char *s1, const char *s2, size_t n);

//ERRORS
void    print_error(int error);
void    check_args_nbr(int argc);

//INITIALIZERS
void    init_mandelbrot(t_fract *fr);
void    init_colors(char **argv, t_color *color, void **mlx, void **win);
void    init_main_inside_colors(char **argv, t_color *color);
void    init_additional_inside_colors(char **argv, t_color *color);
void    init_main_outside_colors(char **argv, t_color *color);
void    init_additional_outside_colors(char **argv, t_color *color);

//COLORIZER
int	get_transparency(int trgb);
int	get_red(int trgb);
int	get_green(int trgb);
int	get_blue(int trgb);
int	convert_rgb_to_hex(int t, int r, int g, int b);
int new_bgr_gradient(int trgb, double mod);
int new_outln_gradient(int trgb, double mod);


#endif