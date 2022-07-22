/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoomer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:42:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 19:46:03 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//TODO: how to follow mouse???

void    zoom_in(t_gui *gui)
{
    gui->fract->zoom_mod *= 0.75;
    gui->fract->zoom_x_mod = gui->mouse_x_pos - 0.15;
    gui->fract->zoom_y_mod = gui->mouse_y_pos - 0.15;
    apply_mods(gui);
    gui->fract->zoom_activated = false;
}

void    zoom_out(t_gui *gui)
{
    gui->fract->zoom_mod /= 0.75;
    apply_mods(gui);
    gui->fract->zoom_activated = false;
}