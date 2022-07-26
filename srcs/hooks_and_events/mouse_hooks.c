/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:35:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/26 18:23:31 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int close_window(t_gui *gui)
{
    mlx_destroy_window(gui->mlx, gui->win);
    free(gui->mlx);
    gui->mlx = NULL;
    exit (0);
}

int    check_mouse_hooks(int keycode, int x, int y, t_gui *gui)
{
    if (keycode == ZOOM_IN)
        zoom_in(gui, x, y);
    else if (keycode == ZOOM_OUT)
        zoom_out(gui, x, y);
    return (0);
}