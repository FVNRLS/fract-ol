/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:35:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 16:52:30 by rmazurit         ###   ########.fr       */
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

static void convert_mouse_pos(t_gui *gui)
{
    gui->mouse_x_pos /= WINDOW_WIDTH;
    gui->mouse_y_pos /= WINDOW_HEIGHT;
}

int    check_mouse_hooks(int keycode, int x, int y, t_gui *gui)
{
    if (keycode == ZOOM_IN)
    {
        mlx_mouse_get_pos(gui->win, &gui->mouse_x_pos, &gui->mouse_y_pos);
        convert_mouse_pos(gui);
        zoom_in(gui);
    }
    else if (keycode == ZOOM_OUT)
    {
        mlx_mouse_get_pos(gui->win, &gui->mouse_x_pos, &gui->mouse_y_pos);
        convert_mouse_pos(gui);
        zoom_out(gui);
    }
    return (0);
}