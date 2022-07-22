/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:35:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 15:44:32 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*TODO:
 * 1) ZOOM (IN + OUT) to the actual point
 * 2) Left click = change julia
 * 3) Right click = change another fractal
 *
 * */

int close_window(t_gui *gui)
{
    mlx_destroy_window(gui->mlx, gui->win);
    free(gui->mlx);
    gui->mlx = NULL;
    exit (0);
}

void    check_mouse_hooks(int keycode, t_gui *gui)
{
    if (keycode == ZOOM_IN)
        zoom_in(gui);
    else if (keycode == ZOOM_OUT)
        zoom_out(gui);
}