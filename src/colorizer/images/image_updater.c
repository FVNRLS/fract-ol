/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit rmazurit@student.42heilbronn.de   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:56:22 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/03 18:32:58 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/fractol.h"

/*
	Main updater of fractal images.
	Decides which fractal to print on the window based on the fractal type.
	The types are derived from the macros 
	and can be modified under /incl/fractol.h
*/
void	update_image(t_gui *gui)
{
	if (gui->fract->type == MANDELBROT_3D)
		update_image_to_3d(gui, gui->fract, gui->color);
	else if (gui->fract->type == MANDELBROT_STD)
		update_image_to_standard(gui, gui->fract, gui->color);
	else if (gui->fract->type == MANDELBROT_PSYCHEDELIC)
		update_image_to_psychedelic(gui, gui->fract, gui->color);
	else if (gui->fract->type == JULIA)
		update_image_to_julia(gui, gui->fract, gui->color);
	else if (gui->fract->type == BURNING_SHIP)
		update_image_to_burningship(gui, gui->fract, gui->color);
}
