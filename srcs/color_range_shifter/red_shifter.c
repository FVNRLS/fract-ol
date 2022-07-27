/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_shifter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:34:57 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:00:12 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

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
