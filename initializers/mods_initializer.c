/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:08:02 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/25 15:10:30 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

static void init_vert_horiz_mods(t_fract *fr)
{
    fr->vert_mod = 1;
    fr->horiz_mod = 1;
    fr->view_scope = 4;
}

static void init_zoom_factor(t_fract *fr)
{
    fr->new_x_offset = 0;
    fr->new_y_offset = 0;
    fr->zoom_activated = false;
}

void init_mods(t_fract *fr)
{
    init_vert_horiz_mods(fr);
    init_zoom_factor(fr);
}

void apply_mods(t_gui *gui)
{
    if (gui->fract->type == MANDELBROT_3D)
        update_image_to_3D(gui, gui->fract, gui->color);
    else if (gui->fract->type == MANDELBROT_STD)
        update_image_to_standard(gui, gui->fract, gui->color);
    else if (gui->fract->type == MANDELBROT_PSYCHEDELIC)
        update_image_to_psychedelic(gui, gui->fract, gui->color);
    else if (gui->fract->type == JULIA)
        update_image_to_julia(gui, gui->fract, gui->color);
    else if (gui->fract->type == BURNING_SHIP)
        update_image_to_burningship(gui, gui->fract, gui->color);
}
