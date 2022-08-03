/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_shifter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:25:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 16:36:33 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
	Increases the Blue value of the RGB value of a predefined color 
	by a constant value 'SHIFT_FACTOR'.
	The constant is located and can be modified under: /includes/bonus.h

	The shifting is realized in the following steps:
	1) TRGB values are extracted from the HEX color value.
	2) Blue is increased by SHIFT_FACTOR.
		If B is already at max. value (255) it will not be increased further.
	3) The TRGB value is converted back to HEX color value.
	4) The new HEX color value is assigned to background color color->out.
	5) The changed fractol is printed.
*/
void	increase_blue(t_gui *gui)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_transparency(gui->color->out);
	r = get_red(gui->color->out);
	g = get_green(gui->color->out);
	b = get_blue(gui->color->out);
	if (b < 255)
	{
		b += SHIFT_FACTOR;
		if (b > 255)
			b = 255;
	}
	gui->color->out = convert_rgb_to_hex(t, r, g, b);
	update_image(gui);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}

/*
	Decreases the Blue value of the RGB value of a predefined color 
	by a constant value 'SHIFT_FACTOR'.
	The constant is located and can be modified under: /includes/bonus.h

	The shifting is realized in the following steps:
	1) TRGB values are extracted from the HEX color value.
	2) Blue is increased by SHIFT_FACTOR.
		If B is already at min. value (0) it will not be decreased further.
	3) The TRGB value is converted back to HEX color value.
	4) The new HEX color value is assigned to background color color->out.
	5) The changed fractol is printed.
*/
void	decrease_blue(t_gui *gui)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_transparency(gui->color->out);
	r = get_red(gui->color->out);
	g = get_green(gui->color->out);
	b = get_blue(gui->color->out);
	if (b > 0)
	{
		b -= SHIFT_FACTOR;
		if (b <= 0)
			b = 0;
	}
	gui->color->out = convert_rgb_to_hex(t, r, g, b);
	update_image(gui);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}
