/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:35:53 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 17:21:23 by rmazurit         ###   ########.fr       */
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
    gui->fract->zoom_x_mod = gui->mouse_x_pos /= WINDOW_WIDTH;
    gui->fract->zoom_y_mod = gui->mouse_y_pos /= WINDOW_HEIGHT;
}

int    check_mouse_hooks(int keycode, int x, int y, t_gui *gui)
{
    gui->mouse_x_pos = (double)x;
    gui->mouse_y_pos = (double)y;
    convert_mouse_pos(gui);
//    printf("zoom x: %lf\n", gui->mouse_x_pos);
//    printf("zoom y: %lf\n", gui->mouse_y_pos);
    if (keycode == ZOOM_IN)
    {
        gui->fract->zoom_activated = true;
        zoom_in(gui);
    }
    else if (keycode == ZOOM_OUT)
    {
        gui->fract->zoom_activated = true;
        zoom_out(gui);
    }
    return (0);
}