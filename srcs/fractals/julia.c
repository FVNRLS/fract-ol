/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:13:25 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/28 10:13:35 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
	The function scales the input pixel coordinate to values suitable for
	Mandelbrot calculation.

	Offset:
	Initially the scaled starting point (0,0) is not in the middle, but starts
	from the top left corner of the window
		--> x/y offset is needed to print the fractal to the middle!
	The offset values are used to modify the positioning of the fractal.
	x_offset is the left-related offset of the fractal (x-axis)
		--> bigger offset will move the picture to the left
	y_offset is the top-related offset of the fractal (y-axis)
		--> bigger offset will move the picture to the bottom
	To understand the offset modification on zoom --> see comments on zoom.
	/srcs/hooks_and_events/zoomer.c

	Horizontal and Vertical Mods:
	The mods are used to modify the offset by a new factor and to move the
	fractal to left/right/top/down directions (modified with arrow keys).
	At the start the horiz_mod and vert_mod are set to 1.

	Scaling x and y coordinates (x_scal and y_scal):
	SCALED_COORD = ORIGINAL_COORD / WINDOW_SIZE

	View scope:
	Geometrically sets the scope of the circle in which the fractal is limited.
	Initially view_scope is set to 4, so the total window scope is from -2 to 2,
	what is a standard for fractals like Mandelbrot/Julia/Burning_Ship
	If view_scope increases, the fractal picture becomes smaller (zoom out).
	If view_scope decreases, the fractal picture becomes bigger (zoom in).
*/
static void	scale_julia_coords(t_fract *fr)
{
	fr->x_scal = (double)fr->x_cor / WINSIZE;
	fr->y_scal = (double)fr->y_cor / WINSIZE;
	if (fr->zoom_activated == true)
	{
		fr->x_offset = fr->new_x_offset;
		fr->y_offset = fr->new_y_offset;
	}
	fr->x_scal = (fr->x_offset * fr->horiz_mod) + (fr->x_scal * fr->view_scope);
	fr->y_scal = (fr->y_offset * fr->vert_mod) - (fr->y_scal * fr->view_scope);
}

/*
	Julia is derived from Mandelbrot fractal.
 	The difference is that real and imaginary constants are not derived from
 	the x and y coordinates, but are fixed and do not change during the calculation.

	Formula:
	z = (z^2) + c

	The z is a complex number, consists of the real and imaginary parts
 	in the beginning z_real and z_imaginary are calculated from the
 	provided scaled x and y coordinates.
	--> scaled x becomes first z_re
	--> scaled y becomes first z_im
	With the iterations grows the z_real and z_imaginary
	As long as the (z_real^2 + z_imaginary^2) are smaller than 4,
	the values remain in the Julia set and do not leave the scope,
	so the new z will be calculated, based on the previous z_real
	and z_imaginary values and the provided constant
 	(consists of a real and imaginary parts as well).

    For each iteration:
	--> The next z_real is calculated like this:
		(z_real^2 + z_imaginary^2) + real constant j_re
	--> The next z_imaginary is determined like this:
		2 * (z_real + z_imaginary) + imaginary constant j_im
*/
static int	calc_julia(t_fract *fr)
{
	init_julia(fr);
	scale_julia_coords(fr);
	fr->z_re = fr->x_scal;
	fr->z_im = fr->y_scal;
	while (fr->z < 4 && fr->iter < fr->max_iter)
	{
		fr->z = pow(fr->z_re, 2) + pow(fr->z_im, 2);
		fr->sum_re = pow(fr->z_re, 2) - pow(fr->z_im, 2) + fr->j_re;
		fr->sum_im = 2 * (fr->z_re * fr->z_im) + fr->j_im;
		fr->z_re = fr->sum_re;
		fr->z_im = fr->sum_im;
		fr->iter++;
	}
	return (fr->iter);
}

/*
	Concept:

	Go through each coordinate (pixel) from the window and throw it
	into the Julia formula to calculate the number of iterations.
	Based on iterations decide with which color the pixel will be colorized.
    Colorize the background with gradient and print Julia depending on the
    input constants (j_re & j_im) and using different colorizing techniques.
*/
void	print_standard_julia(t_gui *gui, t_fract *fr, t_color *color)
{
	fr->x_cor = 0;
	fr->y_cor = 0;
	fr->type = JULIA;
	while (fr->y_cor <= WINSIZE)
	{
		while (fr->x_cor <= WINSIZE)
		{
			fr->iter = calc_julia(fr);
			colorize_julia_with_gradient(gui, fr, color);
			fr->x_cor++;
		}
		fr->iter = 0;
		fr->x_cor = 0;
		fr->y_cor++;
	}
}
