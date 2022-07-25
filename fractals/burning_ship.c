/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:11:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/24 18:22:35 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * -2 = min. of scope
 * 2 = max of scope
 * The values are used to modify the positioning of the fractal.
 * */
static void scale_burning_ship(t_fract *fr)
{
    fr->x_scal = (double)fr->x_cor / WINDOW_WIDTH;
    fr->y_scal = (double)fr->y_cor / WINDOW_HEIGHT;
    fr->c_re = (fr->horiz * fr->horiz_mod) + (fr->x_scal * fr->view_scope);
    fr->c_im = (fr->vert * fr->vert_mod) - (fr->y_scal * fr->view_scope);
}

static int calc_burning_ship(t_fract *fr)
{
    init_burning_ship(fr);
    scale_burning_ship(fr);
    while(fr->z < 4 && fr->iter < fr->max_iter)
    {
        fr->z = pow(fr->z_re, 2) + pow(fr->z_im, 2);
        fr->sum_re = pow(fr->z_re, 2) - pow(fr->z_im, 2) + fr->c_re;
        fr->sum_im = fabs(2 * (fr->z_re * fr->z_im)) - fr->c_im;
        fr->z_re = fr->sum_re;
        fr->z_im = fr->sum_im;
        fr->iter++;
    }
    return (fr->iter);
}

void    print_standard_burning_ship(t_gui *gui, t_fract *fr, t_color *color)
{
    fr->x_cor = 0;
    fr->y_cor = 0;
    fr->type = BURNING_SHIP;
    while (fr->y_cor <= WINDOW_HEIGHT)
    {
        while (fr->x_cor <= WINDOW_WIDTH)
        {
            fr->iter = calc_burning_ship(fr);
            colorize_burning_ship(gui, fr, color);
            fr->x_cor++;
        }
        fr->x_cor = 0;
        fr->y_cor++;
    }
    fr->iter = 0;
    fr->x_cor = 0;
    fr->y_cor++;
}
