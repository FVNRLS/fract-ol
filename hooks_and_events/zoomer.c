/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoomer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:42:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/23 12:55:39 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//TODO: how to follow mouse??? INCOMPLETE!!!
// zoomed image should work with arrow keys!

void    zoom_in(t_gui *gui)
{
    gui->fract->zoom_mod *= 0.75;
    gui->fract->zoom_x_mod = gui->mouse_x_pos;
    gui->fract->zoom_y_mod = gui->mouse_y_pos;
    apply_mods(gui);
}

void    zoom_out(t_gui *gui)
{
    gui->fract->zoom_mod /= 0.75;
    gui->fract->zoom_x_mod = gui->mouse_x_pos;
    gui->fract->zoom_y_mod = gui->mouse_y_pos;
    apply_mods(gui);
}