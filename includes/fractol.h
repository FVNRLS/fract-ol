/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/03 18:30:46 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include <stdio.h>

# include "window.h"

typedef struct	s_data
{
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_data;

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

}       t_fract;

//ADDITIONAL MLX FUNCTIONS
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//FRACTALS
void    print_mandelbrot(t_data *img);


#endif