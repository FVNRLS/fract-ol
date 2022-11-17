/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   green_shifter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit rmazurit@student.42heilbronn.de   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:03:22 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/03 18:32:58 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

/*
	Increases the Green value of the RGB value of a predefined color 
	by a constant value 'SHIFT_FACTOR'.
	The constant is located and can be modified under: /incl/bonus.h

	The shifting is realized in the following steps:
	1) TRGB values are extracted from the HEX color value.
	2) Green is increased by SHIFT_FACTOR.
		If G is already at max. value (255) it will not be increased further.
	3) The TRGB value is converted back to HEX color value.
	4) The new HEX color value is assigned to background color color->out.
	5) The changed fractol is printed.
*/
void	increase_green(t_gui *gui)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_transparency(gui->color->out);
	r = get_red(gui->color->out);
	g = get_green(gui->color->out);
	b = get_blue(gui->color->out);
	if (g < 255)
	{
		g += SHIFT_FACTOR;
		if (g > 255)
			g = 255;
	}
	gui->color->out = convert_rgb_to_hex(t, r, g, b);
	update_image(gui);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}

/*
	Decreases the Green value of the RGB value of a predefined color 
	by a constant value 'SHIFT_FACTOR'.
	The constant is located and can be modified under: /incl/bonus.h

	The shifting is realized in the following steps:
	1) TRGB values are extracted from the HEX color value.
	2) Green is increased by SHIFT_FACTOR.
		If B is already at min. value (0) it will not be decreased further.
	3) The TRGB value is converted back to HEX color value.
	4) The new HEX color value is assigned to background color color->out.
	5) The changed fractol is printed.
*/
void	decrease_green(t_gui *gui)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_transparency(gui->color->out);
	r = get_red(gui->color->out);
	g = get_green(gui->color->out);
	b = get_blue(gui->color->out);
	if (g > 0)
	{
		g -= SHIFT_FACTOR;
		if (g <= 0)
			g = 0;
	}
	gui->color->out = convert_rgb_to_hex(t, r, g, b);
	update_image(gui);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}
