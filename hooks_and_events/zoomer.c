/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoomer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:42:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/25 16:04:39 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_in(t_gui *gui, int x, int y)
{
    t_fract *fr;
    double	re_pos;
    double	im_pos;

    fr = gui->fract;
    fr->zoom_activated = true;
    re_pos = fr->x_offset + (((double)x / WINDOW_WIDTH) * fr->view_scope);
    im_pos = fr->y_offset - (((double)y / WINDOW_HEIGHT) * fr->view_scope);
    fr->view_scope = ZOOM * gui->fract->view_scope;
    fr->new_x_offset = re_pos - (((double)x / WINDOW_WIDTH) * fr->view_scope);
    fr->new_y_offset = im_pos + (((double)y / WINDOW_HEIGHT) * fr->view_scope);
    update_image(gui);
}

void    zoom_out(t_gui *gui, int x, int y)
{
    t_fract *fr;
    double  zoom;
    double	re_pos;
    double	im_pos;

    zoom = 1/ZOOM;
    fr = gui->fract;
    fr->zoom_activated = true;
    re_pos = fr->x_offset + (((double) x / WINDOW_WIDTH) * fr->view_scope);
    im_pos = fr->y_offset - (((double) y / WINDOW_HEIGHT) * fr->view_scope);
    fr->view_scope = zoom * gui->fract->view_scope;
    fr->new_x_offset = re_pos - (((double) x / WINDOW_WIDTH) * fr->view_scope);
    fr->new_y_offset = im_pos + (((double) y / WINDOW_HEIGHT) * fr->view_scope);
    update_image(gui);
}