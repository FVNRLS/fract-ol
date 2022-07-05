/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:20:32 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/05 19:07:25 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * -2 = min. of scope
 * 2 = max of scope
 * */
static void scale_coords(t_fract *fr, double x, double y)
{
    fr->c_re = (-2.5 + ((x / WINDOW_WIDTH) * 4));
    fr->c_im = (2 - ((y / WINDOW_HEIGHT) * 4));
}

static int calc_mandelbrot(t_fract *fr, double x, double y)
{
    int i;

    init_mandelbrot(fr);
    scale_coords(fr, x, y);
    i = 0;
    while(fr->z < 4 && i < fr->max_iter)
    {
        fr->z = pow(fr->z_re, 2) + pow(fr->z_im, 2);
        fr->sum_re = pow(fr->z_re, 2) - pow(fr->z_im, 2) + fr->c_re;
        fr->sum_im = 2 * (fr->z_re * fr->z_im) + fr->c_im;
        fr->z_re = fr->sum_re;
        fr->z_im = fr->sum_im;
        i++;
    }
    return (i);
}

//TODO: simplify!!!
void    print_mandelbrot(t_data *img, t_color *color, char **argv)
{
    t_fract fr;

    int x;
    int y;
    int iter;
    int init_color;
    double mod_bgr;
    double mod_outln;

    x = 0;
    y = 0;
    init_color = color->out;
    while (y <= WINDOW_HEIGHT)
    {
        while (x <= WINDOW_WIDTH)
        {
            iter = calc_mandelbrot(&fr, x, y);
            if (iter < fr.max_iter)
            {
                mod_bgr = (double)x / (double )(WINDOW_WIDTH);
                color->out = new_bgr_gradient(color->out, mod_bgr);
                if (iter >= 5 && iter <= 9)
                {
                    if (iter % 2 == 0 && mod_bgr > 0.175 && mod_bgr < 0.675)
                        color->out = new_bgr_gradient(color->out, (1 - mod_bgr));
                    if (mod_bgr > 0.675)
                    {
                        color->out = new_bgr_gradient(color->out, (0 - mod_bgr));
                    }
                }
                if (iter >= 10 && iter <= 16)
                {
                    if (iter % 2 == 0)
                        color->out = LIME;
                    else
                        color->out = NAVY;
                    color->out = new_bgr_gradient(color->out, mod_bgr);
                    mod_outln = (double )iter / 16;
                    color->out = new_outln_gradient(color->out, mod_outln);
                }
                if (iter > 16 && iter < fr.max_iter)
                {
                    color->out = LIME;
                }
                my_mlx_pixel_put(img, x, y, color->out);
                color->out = init_color;
            }
            else
                my_mlx_pixel_put(img, x, y, color->in);
            x++;
        }
        x = 0;
        y++;
    }
}