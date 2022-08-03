/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_shifter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:34:57 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 16:39:28 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
	Increases the Red value of the RGB value of a predefined color 
	by a constant value 'SHIFT_FACTOR'.
	The constant is located and can be modified under: /includes/bonus.h

	The shifting is realized in the following steps:
	1) TRGB values are extracted from the HEX color value.
	2) Green is increased by SHIFT_FACTOR.
		If R is already at max. value (255) it will not be increased further.
	3) The TRGB value is converted back to HEX color value.
	4) The new HEX color value is assigned to background color color->out.
	5) The changed fractol is printed.
*/
void	increase_red(t_gui *gui)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_transparency(gui->color->out);
	r = get_red(gui->color->out);
	g = get_green(gui->color->out);
	b = get_blue(gui->color->out);
	if (r < 255)
	{
		r += SHIFT_FACTOR;
		if (r > 255)
			r = 255;
	}
	gui->color->out = convert_rgb_to_hex(t, r, g, b);
	update_image(gui);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}

/*
	Decreases the Red value of the RGB value of a predefined color 
	by a constant value 'SHIFT_FACTOR'.
	The constant is located and can be modified under: /includes/bonus.h

	The shifting is realized in the following steps:
	1) TRGB values are extracted from the HEX color value.
	2) Green is increased by SHIFT_FACTOR.
		If R is already at min. value (0) it will not be decreased further.
	3) The TRGB value is converted back to HEX color value.
	4) The new HEX color value is assigned to background color color->out.
	5) The changed fractol is printed.
*/
void	decrease_red(t_gui *gui)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_transparency(gui->color->out);
	r = get_red(gui->color->out);
	g = get_green(gui->color->out);
	b = get_blue(gui->color->out);
	if (r > 0)
	{
		r -= SHIFT_FACTOR;
		if (r <= 0)
			r = 0;
	}
	gui->color->out = convert_rgb_to_hex(t, r, g, b);
	update_image(gui);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}
