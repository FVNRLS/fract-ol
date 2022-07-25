/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoomer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:42:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/25 13:49:41 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//TODO: how to follow mouse??? INCOMPLETE!!!
// zoomed image should work with arrow keys!

//void    zoom_in(t_gui *gui)
//{
//    gui->fract->zoom_mod *= 0.75;
//    gui->fract->zoom_x_mod = gui->mouse_x_pos;
//    gui->fract->zoom_y_mod = gui->mouse_y_pos;
//    apply_mods(gui);
//}

//// maybe i should add +2 or -2 to convet into right coord ??
//static void convert_mouse_pos(t_gui *gui)
//{
//    gui->mouse_x_pos =
//    gui->mouse_y_pos = (gui->mouse_y_pos / WINDOW_HEIGHT) * gui->fract->view_scope;
//}

void	zoom_in(t_gui *gui, int x, int y)
{
    double	re_pos;
    double	im_pos;

    gui->fract->zoom_activated = true;
    gui->mouse_x_pos = (double) x;
    gui->mouse_y_pos = (double) y;
    re_pos = gui->fract->horiz + ((gui->mouse_x_pos / WINDOW_WIDTH) * gui->fract->view_scope);
    im_pos = gui->fract->vert - ((gui->mouse_y_pos / WINDOW_HEIGHT) * gui->fract->view_scope);
//    convert_mouse_pos(gui);

    gui->fract->view_scope = ZOOM * gui->fract->view_scope;
    gui->fract->zoom_x_mod = re_pos - ((gui->mouse_x_pos / WINDOW_WIDTH) * gui->fract->view_scope);
    gui->fract->zoom_y_mod = im_pos + ((gui->mouse_y_pos / WINDOW_WIDTH) * gui->fract->view_scope);
    apply_mods(gui);
    gui->fract->zoom_activated = false;
}


void    zoom_out(t_gui *gui)
{
    double  zoom;

    zoom = 1/ZOOM;
    gui->fract->zoom_x_mod = gui->mouse_x_pos;
    gui->fract->zoom_y_mod = gui->mouse_y_pos;
    apply_mods(gui);
}