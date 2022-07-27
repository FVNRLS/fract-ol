/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:48:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 17:40:25 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
	Paints the whole image with black color to print a new fractal on it.
	This avoids overlapping of new and previous fractals and prints 
	the new one as it was intended.
	This is a very stupid technique, which requires a lot of instructions, but
	it avoids the slower way of printing an image.
		-->(destroy the image, allocate new image, get image params (addr.))
	unfortunately the minilibx does not suggest effective ways/functions to
	solve this problem...
*/
void	colorize_img_to_black(t_gui *gui)
{
	int	x_cor;
	int	y_cor;

	x_cor = 0;
	y_cor = 0;
	while (y_cor <= WINSIZE)
	{
		while (x_cor <= WINSIZE)
		{
			my_mlx_pixel_put(gui, x_cor, y_cor, BLACK);
			x_cor++;
		}
		x_cor = 0;
		y_cor++;
	}
}

/*
	Creates a new background color based on a modifier.
	For this purpose:
	1) The respective TRGB values are extracted from the color.
	2) The transparency (T) is modified using the mod.
	3) The color is recreated with the modified T value.
*/
int	new_bgr_gradient(int trgb, double mod)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	new_color;

	t = 200 * mod;
	r = get_red(trgb);
	g = get_green(trgb);
	b = get_blue(trgb);
	new_color = convert_rgb_to_hex(t, r, g, b);
	return (new_color);
}

/*
	Creates a new outline color based on a modifier.
	For this purpose:
	1) The respective TRGB values are extracted from the color.
	2) The transparency (T) is modified using the mod.
	3) The color is recreated with the modified T value.
*/
int	new_outln_gradient(int trgb, double mod)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	new_color;

	t = 200 * mod;
	r = get_red(trgb);
	g = get_green(trgb);
	b = get_blue(trgb);
	new_color = convert_rgb_to_hex(t, r, g, b);
	return (new_color);
}

/*
	Creates a new fab value based on the number of iterations. 
	For coordinates leaving the fractal scope quickly (the first iterations).
	For this purpose:
	1) The respective TRGB values are extracted from the color.
	2) The transparency (T) is modified using the iteration.
	3) The color is recreated with the modified T value.
*/
int	new_aura(int trgb, t_fract *fr)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	new_color;

	t = 20 * fr->iter;
	r = get_red(trgb);
	g = get_green(trgb);
	b = get_blue(trgb);
	new_color = convert_rgb_to_hex(t, r, g, b);
	return (new_color);
}

/*
	Creates a new fab value based on the number of iterations, whose 
	value is an inversion (opposite of the current color value).
	For this purpose:
	1) The respective TRGB values are extracted from the color.
	2) The RGB is modified using the iteration with the following formula:
		<255 - CURRENT_COLOR_VALUE>
	3) The color is recreated with the modified RGB values.
*/
int	invert_colors(int trgb, t_fract *fr)
{
	int	t;
	int	r;
	int	g;
	int	b;
	int	new_color;

	t = 20 * fr->iter;
	r = get_red(trgb);
	g = get_green(trgb);
	b = get_blue(trgb);
	r = 255 - r;
	g = 255 - g;
	b = 255 - b;
	new_color = convert_rgb_to_hex(t, r, g, b);
	return (new_color);
}
