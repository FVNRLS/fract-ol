/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_colorizer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:44:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 18:38:13 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
	Colorizes the fractal background with a slight gradient (light -> dark).
	To calculate the gradient, firstly a modifiator mod_bgr is calculated.
	For this, the pixel x-coordinate is divided by the window size.
	The modifier is used by the new_bgr_gradient function to set new color.
	Finally the pixel is printed to the image.
	Also creates a simple 3D effect by printing for iterations between 5 and 9
	a new gradient color, based on the background color and the modifier.
	Otherwise a color with opposite transparency is printed.
	But this is only for coordinates with even iterations and is limited in 
	scope mod_bgr (from left and right), so the Mandelbrot is limited from
	both sides on the x-axis (left: 0.175 right:0.675).
	The scope is calculated with following formula:
		current_x_coordinate / WINSIZE
	If you try to move the fractal with arrow keys, you will notice that the 
	fractal leaves the scope (small animation effect), because the scope 
	values do not adapt to the changed coordinates.
*/
static void	colorize_bgr(t_gui *img, t_color *color, t_fract *fr)
{
	int		init_out;
	double	mod_bgr;

	init_out = color->out;
	mod_bgr = (double)fr->x_cor / (double )(WINSIZE);
	color->out = new_bgr_gradient(color->out, mod_bgr);
	my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
	if (fr->iter >= 5 && fr->iter <= 9)
	{
		if (fr->iter % 2 == 0 && mod_bgr > 0.175 && mod_bgr < 0.675)
			color->out = new_bgr_gradient(color->out, (1 - mod_bgr));
		else if (mod_bgr > 0.675)
			color->out = new_bgr_gradient(color->out, (0 - mod_bgr));
		my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
		color->out = init_out;
	}
}

/*
	Colorizes the iner transitions (span) of the Mandelbrot fractal.
	The initial value of color->outln (outline color) is stored in init_outln.
	Based on the current iter. value a new color is assigned to color->outln.
	The pixel is then printed on the image.
	The color value is reset to the initial value.
	All even-iteration-coordinates are colorized with the modified outline color.
	Otherwise - with Black. 
		--> creation of contrast-effect.
*/
static void	colorize_span(t_gui *img, t_color *color, t_fract *fr)
{
	int		init_outln;
	double	mod_outln;

	init_outln = color->outln;
	if (fr->iter % 2 == 0)
	{
		mod_outln = (double )fr->iter / 16;
		color->outln = new_outln_gradient(color->out, mod_outln);
	}
	else
		color->outln = BLACK;
	my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
	color->outln = init_outln;
}

/*
	Decides on the basis of the iterations how to colorize Mandelbrot.
	1) Coordinates that are far from the set value fr->max_iter
		are marked as background (0-10 iterations).
		The background is colorized with 3D effect, based on iterations
		and scope modification.
	2) Coordinates with iterations between 10 and 16 are the span.
		(transition from the background to outline part of Mandelbrot).
	3) Outline is everything between 16 and fr->max_iter and is colorized
		with color->outln
	4) All values above fr->max_iter are colorized with color->in.
		They are very deep in the Mandelbrot formula - that means 
		they will most likely not leave the scope.
*/
void	colorize_with_gradient(t_gui *img, t_fract *fr, t_color *color)
{
	if (fr->iter < fr->max_iter)
	{
		if (fr->iter < 10)
			colorize_bgr(img, color, fr);
		else if (fr->iter >= 10 && fr->iter <= 16)
			colorize_span(img, color, fr);
		else if (fr->iter > 16 && fr->iter < fr->max_iter)
			my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
	}
	else
		my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->in);
}

/*
	Decides on the basis of the iterations how to colorize Mandelbrot.
	1) Coordinates that are far from the set value fr->max_iter
		are marked as background (0-10 iterations).
		The background is colorized with a basic persistent color.
	2) Outline is everything between 16 and fr->max_iter and is colorized
		with color->outln
	3) All values above fr->max_iter are colorized with color->in.
		They are very deep in the Mandelbrot formula - that means 
		they will most likely not leave the scope.
*/
void	colorize_with_basic_colors(t_gui *img, t_fract *fr, t_color *color)
{
	if (fr->iter < fr->max_iter)
	{
		if (fr->iter < 16)
			my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
		else if (fr->iter >= 16 && fr->iter < fr->max_iter)
			my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
	}
	else
		my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->in);
}

/*
	Decides on the basis of the iterations how to colorize Mandelbrot.
	1) Coordinates that are far from the set value fr->max_iter
		are marked as background (0-10 iterations).
		The background is colorized with Psychedelic effect, based on 
		iteration numbers.
	2) Coordinates with iterations between 10 and 16 are the span.
		(transition from the background to outline part of Mandelbrot).
	3) Outline is everything between 16 and fr->max_iter and is colorized
		with color->outln.
	4) All values above fr->max_iter are colorized with color->in.
		They are very deep in the Mandelbrot formula - that means 
		they will most likely not leave the scope.
*/
void	colorize_with_aura(t_gui *img, t_fract *fr, t_color *color)
{
	int	init_out;

	if (fr->iter < fr->max_iter)
	{
		if (fr->iter < 10)
		{
			init_out = color->out;
			if (fr->iter % 2 == 0)
				color->out = new_aura(color->out, fr);
			else
				color->out = color->in;
			my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
			color->out = init_out;
		}
		else if (fr->iter >= 10 && fr->iter <= 16)
			colorize_span(img, color, fr);
		else if (fr->iter > 16 && fr->iter < fr->max_iter)
			my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
	}
	else
		my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->in);
}
