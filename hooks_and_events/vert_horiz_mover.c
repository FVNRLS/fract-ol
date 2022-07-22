/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_horiz_mover.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:26:13 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 13:46:44 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void apply_mods(t_gui *gui)
{
    check_mods(gui);
    if (gui->fract->type == MANDELBROT_3D)
        update_image_to_3D(gui, gui->fract, gui->color);
    else if (gui->fract->type == MANDELBROT_STD)
        update_image_to_standard(gui, gui->fract, gui->color);
    else if (gui->fract->type == MANDELBROT_PSYCHEDELIC)
        update_image_to_psychedelic(gui, gui->fract, gui->color);
}

void    move_up(t_gui *gui)
{
    gui->fract->vert_mod -= 0.15;
    apply_mods(gui);
}

void    move_down(t_gui *gui)
{
    gui->fract->vert_mod += 0.15;
    apply_mods(gui);
}

void    move_left(t_gui *gui)
{
    gui->fract->horiz_mod -= 0.15;
    apply_mods(gui);
}

void    move_right(t_gui *gui)
{
    gui->fract->horiz_mod += 0.15;
    apply_mods(gui);
}