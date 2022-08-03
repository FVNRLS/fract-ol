/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_colorizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:27:14 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 18:34:10 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

/*
	Colorizes the fractal background with a slight gradient (light -> dark).
	To calculate the gradient, firstly a modifiator mod_bgr is calculated.
	For this, the pixel x-coordinate is divided by the window size.
	The modifier is used by the new_bgr_gradient function to set new color.
	Finally the pixel is printed to the image.
*/
static void	colorize_bgr(t_gui *img, t_color *color, t_fract *fr)
{
	double	mod_bgr;

	mod_bgr = (double)fr->x_cor / (double )(WINSIZE);
	color->out = new_bgr_gradient(color->out, mod_bgr);
	my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
}

/*
	Colorizes the iner transitions (span) of the Julia fractal.
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
		mod_outln = (double)fr->iter / 16;
		color->outln = new_outln_gradient(color->out, mod_outln);
	}
	else
		color->outln = BLACK;
	my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
	color->outln = init_outln;
}

/*
	Colorize inner deep part of Julia with different gradients, 
	based on the color->in.
*/
static void	colorize_inner_part(t_gui *img, t_color *color, t_fract *fr)
{
	int		init_in;
	double	mod_bgr;

	mod_bgr = (double)fr->x_cor / (double )(WINSIZE);
	init_in = color->in;
	color->in = new_bgr_gradient(color->out, mod_bgr);
	my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
	color->in = init_in;
}

/*
	Depending on the current iteration value, inverts the 
	color and prints the inverted pixels into the image.
	Depending on the iter. value, the color were picked from
	color->in/out/outln.
	The inverted colors are printed only for even iterations.
	Otherwise - only the initial colors (in/out/outln).
*/
void	colorize_with_inverted_colors(t_gui *img, t_fract *fr, t_color *color)
{
	int	init_color;
	int	inv;

	inv = NO_COLOR;
	init_color = NO_COLOR;
	if (fr->iter >= 100 && fr->iter < 200)
		init_color = color->in;
	else if (fr->iter >= 200 && fr->iter < 300)
		init_color = color->out;
	else if (fr->iter >= 300 && fr->iter < 400)
		init_color = color->outln;
	inv = invert_colors(init_color, fr);
	if (fr->iter % 2 == 0)
		my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, inv);
	else
		my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, init_color);
}

/*
	Decides on the basis of the iterations how to colorize Julia.
	1) Coordinates that are far from the set value fr->max_iter
		are marked as background (0-20 iterations).
	2) Coordinates with iterations between 20 and 100 are the span.
		(transition from the background to outside part of Julia).
	3) Between 100 and 400 iterations the biggest inner part\
		i colorized with different inverted colors, depending on the
		iterations.
	4) The deepest inner Julia part is colorized with gradient.
	5) All values above fr->max_iter are colorized with color->in.
		They are very deep in the Julia formula - that means 
		they will most likely not leave the scope.
*/
void	colorize_julia_with_gradient(t_gui *img, t_fract *fr, t_color *color)
{
	if (fr->iter < fr->max_iter)
	{
		if (fr->iter < 20)
			colorize_bgr(img, color, fr);
		else if (fr->iter >= 20 && fr->iter < 100)
			colorize_span(img, color, fr);
		else if (fr->iter >= 100 && fr->iter < 400)
			colorize_with_inverted_colors(img, fr, color);
		else if (fr->iter >= 400 && fr->iter < fr->max_iter)
			colorize_inner_part(img, color, fr);
	}
	else
		my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->in);
}
