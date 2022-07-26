/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:20:32 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/25 16:04:39 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
 * -2 = min. of scope
 * 2 = max of scope
 * The values are used to modify the positioning of the fractal.
 * */
static void scale_mandelbrot_coords(t_fract *fr)
{
    fr->x_scal = (double)fr->x_cor / WINDOW_WIDTH;
    fr->y_scal = (double)fr->y_cor / WINDOW_HEIGHT;
    if (fr->zoom_activated == true)
    {
        fr->x_offset = fr->new_x_offset;
        fr->y_offset = fr->new_y_offset;
    }
    fr->c_re = (fr->x_offset * fr->horiz_mod) + (fr->x_scal * fr->view_scope);
    fr->c_im = (fr->y_offset * fr->vert_mod) - (fr->y_scal * fr->view_scope);

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

void    print_3D_mandelbrot(t_gui *gui, t_fract *fr, t_color *color)
{
    fr->x_cor = 0;
    fr->y_cor = 0;
    fr->left_padded = false;
    fr->type = MANDELBROT_3D;
    while (fr->y_cor <= WINDOW_HEIGHT)
    {
        while (fr->x_cor <= WINDOW_WIDTH)
        {
            fr->iter = calc_mandelbrot(fr);
            colorize_with_gradient(gui, fr, color);
            fr->x_cor++;
        }
        fr->x_cor = 0;
        fr->y_cor++;
    }
}

void    print_standard_mandelbrot(t_gui *gui, t_fract *fr, t_color *color)
{
    fr->x_cor = 0;
    fr->y_cor = 0;
    fr->left_padded = false;
    fr->type = MANDELBROT_STD;
    while (fr->y_cor <= WINDOW_HEIGHT)
    {
        while (fr->x_cor <= WINDOW_WIDTH)
        {
            fr->iter = calc_mandelbrot(fr);
            colorize_with_basic_colors(gui, fr, color);
            fr->x_cor++;
        }
        fr->x_cor = 0;
        fr->y_cor++;
    }
}

void    print_psychedelic_mandelbrot(t_gui *gui, t_fract *fr, t_color *color)
{
    fr->x_cor = 0;
    fr->y_cor = 0;
    fr->left_padded = true;
    fr->type = MANDELBROT_PSYCHEDELIC;
    while (fr->y_cor <= WINDOW_HEIGHT)
    {
        while (fr->x_cor <= WINDOW_WIDTH)
        {
            fr->iter = calc_mandelbrot(fr);
            colorize_with_aura(gui, fr, color);
            fr->x_cor++;
        }
        fr->x_cor = 0;
        fr->y_cor++;
    }
}