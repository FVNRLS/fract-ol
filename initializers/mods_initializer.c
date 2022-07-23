/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:08:02 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/23 19:38:55 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

static void init_vert_horiz_mods(t_fract *fr)
{
    fr->vert_mod = 1;
    fr->horiz_mod = 1;
}

static void init_zoom_factor(t_fract *fr)
{
    fr->zoom_x_mod = 0;
    fr->zoom_x_mod = 0;
    fr->zoom_mod = 4;
}

void init_mods(t_fract *fr)
{
    init_vert_horiz_mods(fr);
    init_zoom_factor(fr);
}

void    check_mods(t_gui *gui)
{
    if (gui->fract->vert_mod <= -0.5 || gui->fract->vert_mod >= 2.5)
        init_mods(gui->fract);
    else if (gui->fract->horiz_mod <= -0.2 || gui->fract->horiz_mod >= 2.2)
        init_mods(gui->fract);
}

void apply_mods(t_gui *gui)
{
//    check_mods(gui);
    if (gui->fract->type == MANDELBROT_3D)
        update_image_to_3D(gui, gui->fract, gui->color);
    else if (gui->fract->type == MANDELBROT_STD)
        update_image_to_standard(gui, gui->fract, gui->color);
    else if (gui->fract->type == MANDELBROT_PSYCHEDELIC)
        update_image_to_psychedelic(gui, gui->fract, gui->color);
    else if (gui->fract->type == JULIA)
        update_image_to_julia(gui, gui->fract, gui->color);
}



