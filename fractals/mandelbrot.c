/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:20:32 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/06 15:22:50 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * -2 = min. of scope
 * 2 = max of scope
 * */
static void scale_coords(t_fract *fr)
{
    fr->c_re = (-2.5 + (((double)fr->x_cor / WINDOW_WIDTH) * 4));
    fr->c_im = (2 - (((double )fr->y_cor / WINDOW_HEIGHT) * 4));
}

static int calc_mandelbrot(t_fract *fr)
{
    init_mandelbrot(fr);
    scale_coords(fr);
    while(fr->z < 4 && fr->iter < fr->max_iter)
    {
        fr->z = pow(fr->z_re, 2) + pow(fr->z_im, 2);
        fr->sum_re = pow(fr->z_re, 2) - pow(fr->z_im, 2) + fr->c_re;
        fr->sum_im = 2 * (fr->z_re * fr->z_im) + fr->c_im;
        fr->z_re = fr->sum_re;
        fr->z_im = fr->sum_im;
        fr->iter++;
    }
    return (fr->iter);
}

void    print_mandelbrot(t_gui *gui, t_color *color)
{
    t_fract fr;

    fr.x_cor = 0;
    fr.y_cor = 0;
    while (fr.y_cor <= WINDOW_HEIGHT)
    {
        while (fr.x_cor <= WINDOW_WIDTH)
        {
            fr.iter = calc_mandelbrot(&fr);
            colorize_mandelbrot(gui, &fr, color);
            fr.x_cor++;
        }
        fr.x_cor = 0;
        fr.y_cor++;
    }
}