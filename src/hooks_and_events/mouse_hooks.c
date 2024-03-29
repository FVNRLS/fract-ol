/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit rmazurit@student.42heilbronn.de   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:35:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:42:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

/*
	Close the window by pressing the red cross-button on the window.
 	Destroy the window and free all allocated items.
*/
int	close_window(t_gui *gui)
{
	mlx_destroy_window(gui->mlx, gui->win);
	free(gui->mlx);
	gui->mlx = NULL;
	exit (0);
}

/*
	Check functions to zoom in and out using the mouse wheel.
*/
int	check_mouse_hooks(int keycode, int x, int y, t_gui *gui)
{
	if (keycode == ZOOM_IN)
		zoom_in(gui, x, y);
	else if (keycode == ZOOM_OUT)
		zoom_out(gui, x, y);
	return (0);
}
