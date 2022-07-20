/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:20:32 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/20 13:14:07 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * -2 = min. of scope
 * 2 = max of scope
 * */
static void scale_mandelbrot_coords(t_fract *fr)
{
    double mod_horiz;
    double mod_vert;

    mod_horiz = -2.5;
    mod_vert = 2.0;
    if (fr->left_padded == true)
        mod_horiz = -2.0;

    fr->c_re = (mod_horiz + (((double)fr->x_cor / WINDOW_WIDTH) * 4));
    fr->c_im = (mod_vert - (((double )fr->y_cor / WINDOW_HEIGHT) * 4));
}

static int calc_mandelbrot(t_fract *fr)
{
    init_mandelbrot(fr);
    scale_mandelbrot_coords(fr);
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

void    print_3D_mandelbrot(t_gui *gui, t_color *color)
{
    t_fract fr;

    fr.x_cor = 0;
    fr.y_cor = 0;
    fr.left_padded = false;
    while (fr.y_cor <= WINDOW_HEIGHT)
    {
        while (fr.x_cor <= WINDOW_WIDTH)
        {
            fr.iter = calc_mandelbrot(&fr);
            colorize_with_gradient(gui, &fr, color);
            fr.x_cor++;
        }
        fr.x_cor = 0;
        fr.y_cor++;
    }
}

void    print_standard_mandelbrot(t_gui *gui, t_color *color)
{
    t_fract fr;

    fr.x_cor = 0;
    fr.y_cor = 0;
    fr.left_padded = false;
    while (fr.y_cor <= WINDOW_HEIGHT)
    {
        while (fr.x_cor <= WINDOW_WIDTH)
        {
            fr.iter = calc_mandelbrot(&fr);
            colorize_with_basic_colors(gui, &fr, color);
            fr.x_cor++;
        }
        fr.x_cor = 0;
        fr.y_cor++;
    }
}

void    print_psychedelic_mandelbrot(t_gui *gui, t_color *color)
{
    t_fract fr;

    fr.x_cor = 0;
    fr.y_cor = 0;
    fr.left_padded = true;
    while (fr.y_cor <= WINDOW_HEIGHT)
    {
        while (fr.x_cor <= WINDOW_WIDTH)
        {
            fr.iter = calc_mandelbrot(&fr);
            colorize_with_aura(gui, &fr, color);
            fr.x_cor++;
        }
        fr.x_cor = 0;
        fr.y_cor++;
    }
}