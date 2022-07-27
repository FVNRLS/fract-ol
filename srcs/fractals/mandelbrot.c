/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:20:32 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:33:54 by rmazurit         ###   ########.fr       */
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
static void	scale_mandelbrot_coords(t_fract *fr)
{
	fr->x_scal = (double)fr->x_cor / WINSIZE;
	fr->y_scal = (double)fr->y_cor / WINSIZE;
	if (fr->zoom_activated == true)
	{
		fr->x_offset = fr->new_x_offset;
		fr->y_offset = fr->new_y_offset;
	}
	fr->c_re = (fr->x_offset * fr->horiz_mod) + (fr->x_scal * fr->view_scope);
	fr->c_im = (fr->y_offset * fr->vert_mod) - (fr->y_scal * fr->view_scope);
}

/*
	Mandelbrot is a basic fractal from which other different fractal
 	types can be derived.

	Formula:
	z = z^2

	c is calculated from the provided scaled x and y coordinates.
	x forms the real constant c_re
	y forms the imaginary constant c_im

	The z is a complex number, consists of the real and imaginary parts
 	and is at the beginning 0.
	With the iterations grows the z_real and z_imaginary
	As long as the (z_real^2 + z_imaginary^2) are smaller than 4,
	the values remain in the Burning ship set and do not leave the scope,
	so the new z will be calculated, based on the previous z_real
	and z_imaginary values.

    For each iteration:
	--> The next z_real is calculated like this:
		(z_real^2 + z_imaginary^2) + real constant c_re
		(scaled and modified x coordinate).
	--> The next z_imaginary is determined like this:
		2 * (z_real + z_imaginary) + imaginary constant c_im
		(scaled and modified y coordinate)
*/
static int	calc_mandelbrot(t_fract *fr)
{
	init_mandelbrot(fr);
	scale_mandelbrot_coords(fr);
	while (fr->z < 4 && fr->iter < fr->max_iter)
	{
		fr->z = pow(fr->z_re, 2) + pow(fr->z_im, 2);
		fr->sum_re = pow(fr->z_re, 2) - pow(fr->z_im, 2) + fr->c_re;
		fr->sum_im = 2 * (fr->z_re * fr->z_im) + fr->c_im;
		fr->z_re = fr->sum_re;
		fr->z_im = fr->sum_im;
		fr->iter++;
	}
	return (fr->iter);
}

/*
	Concept:

	Go through each coordinate (pixel) from the window and throw it
	into the burning ship formula to calculate the number of iterations.
	Based on iterations decide with which color the pixel will be colorized.
    Colorize the background with gradient and print Mandelbrot in 3D form
    using different colorizing techniques.
*/
void	print_3d_mandelbrot(t_gui *gui, t_fract *fr, t_color *color)
{
	fr->x_cor = 0;
	fr->y_cor = 0;
	fr->left_padded = false;
	fr->type = MANDELBROT_3D;
	while (fr->y_cor <= WINSIZE)
	{
		while (fr->x_cor <= WINSIZE)
		{
			fr->iter = calc_mandelbrot(fr);
			colorize_with_gradient(gui, fr, color);
			fr->x_cor++;
		}
		fr->x_cor = 0;
		fr->y_cor++;
	}
}

/*
Concept:
	Go through each coordinate (pixel) from the window and throw it
	into the burning ship formula to calculate the number of iterations.
	Based on iterations decide with which color the pixel will be colorized.
    Colorize the background with persistent color, as well the outline and
    Mandelbrot itself.
    using different colorizing techniques.
*/
void	print_standard_mandelbrot(t_gui *gui, t_fract *fr, t_color *color)
{
	fr->x_cor = 0;
	fr->y_cor = 0;
	fr->left_padded = false;
	fr->type = MANDELBROT_STD;
	while (fr->y_cor <= WINSIZE)
	{
		while (fr->x_cor <= WINSIZE)
		{
			fr->iter = calc_mandelbrot(fr);
			colorize_with_basic_colors(gui, fr, color);
			fr->x_cor++;
		}
		fr->x_cor = 0;
		fr->y_cor++;
	}
}

/*
Concept:
	Go through each coordinate (pixel) from the window and throw it
	into the burning ship formula to calculate the number of iterations.
	Based on iterations decide with which color the pixel will be colorized.
    Use different colors on small iterations to create a psychedelic effect.
*/
void	print_psychedelic_mandelbrot(t_gui *gui, t_fract *fr, t_color *color)
{
	fr->x_cor = 0;
	fr->y_cor = 0;
	fr->left_padded = true;
	fr->type = MANDELBROT_PSYCHEDELIC;
	while (fr->y_cor <= WINSIZE)
	{
		while (fr->x_cor <= WINSIZE)
		{
			fr->iter = calc_mandelbrot(fr);
			colorize_with_aura(gui, fr, color);
			fr->x_cor++;
		}
		fr->x_cor = 0;
		fr->y_cor++;
	}
}
