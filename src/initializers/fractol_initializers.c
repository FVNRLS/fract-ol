/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_initializers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:03:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/28 10:37:39 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

/*
	Initializes the needed starting parameters for Mandelbrot calculation.
	Initialization happens for every coordinate (pixel) inside the function 
	calc_mandelbrot, which is used by the folowing functions:
	- print_3d_mandelbrot
	- print_standard_mandelbrot
	- print_psychedelic_mandelbrot
	Path: src/fractals/mandelbrot.c
*/
void	init_mandelbrot(t_fract *fr)
{
	fr->c_re = 0;
	fr->z = 0;
	fr->z_re = 0;
	fr->z_im = 0;
	fr->iter = 0;
	fr->max_iter = 600;
	fr->x_offset = -2.5;
	fr->y_offset = 2.0;
	if (fr->left_padded == true)
		fr->x_offset = -2.0;
}

/*
	Initializes the needed starting parameters for Julia calculation.
	Initialization happens for every coordinate (pixel) inside the function 
	calc_julia, which is used by the function print_standard_julia
	Path: src/fractals/julia.c
*/
void	init_julia(t_fract *fr)
{
	fr->c_re = 0;
	fr->z = 0;
	fr->z_re = 0;
	fr->z_im = 0;
	fr->iter = 0;
	fr->max_iter = 600;
	fr->x_offset = -2.0;
	fr->y_offset = 2.0;
}

/*
	Initializes the needed starting parameters for Bruning Ship calculation.
	Initialization happens for every coordinate (pixel) inside the function 
	calc_burning_ship, which is used by the function print_std_burn_ship
	Path: src/fractals/julia.c
*/
void	init_burning_ship(t_fract *fr)
{
	fr->c_re = 0;
	fr->z = 0;
	fr->z_re = 0;
	fr->z_im = 0;
	fr->iter = 0;
	fr->max_iter = 600;
	fr->x_offset = -2.5;
	fr->y_offset = 2.5;
}
