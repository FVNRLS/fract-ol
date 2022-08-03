/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_colorizer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:06:55 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 17:44:08 by rmazurit         ###   ########.fr       */
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
	Colorizes the transition (span) of the fractol from background 
	to the fractol outline (iterations 14 - 32).
	The interations were chosen by experience and it was also noticed that 
	in the area the mast sail of the ship is rendered better and very detailed.
	
	The initial value of color->out (background color) is stored in init_out.
	Based on the current iteration value a new color is assigned to color->out.
	The pixel is then printed on the image.
	The color value is reset to the initial value.

	If you zoom in on the mast sail and the ship you can see multicolored 
	areas around - that's the span ;)
*/
static void	colorize_span(t_gui *img, t_color *color, t_fract *fr)
{
	int		init_out;
	double	mod_out;

	init_out = color->out;
	mod_out = (24 -(double)fr->iter) / 24;
	color->out = new_outln_gradient(color->out, mod_out);
	my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
	color->out = init_out;
}

/*
	Decides on the basis of the iterations how to colorize Burning Ship.
	1) Coordinates that are far from the set value fr->max_iter
		are marked as background (0-13 iterations).
	2) Coordinates with iterations between 14 and 31 are the span.
		(transition from the background to the actual ship)
	3) From 32 iterations the outine starts, which colorizes the mast sail.
		(color->outl)
	4) All values above fr->max_iter are colorized with coor->in'.
		They are deep in the Burning Ship formula - that means 
		they will most likely not leave the scope.
*/
void	colorize_burning_ship(t_gui *img, t_fract *fr, t_color *color)
{
	if (fr->iter < fr->max_iter)
	{
		if (fr->iter < 14)
			colorize_bgr(img, color, fr);
		else if (fr->iter >= 14 && fr->iter < 32)
			colorize_span(img, color, fr);
		else if (fr->iter >= 32 && fr->iter < fr->max_iter)
			my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
	}
	else
		my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->in);
}
