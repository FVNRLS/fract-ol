/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:44:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/06 11:16:31 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void colorize_bgr(t_data *img, t_color *color, int x, int y, int iter)
{
    int init_out;

    init_out = color->out;
    double mod_bgr;

    mod_bgr = (double)x / (double )(WINDOW_WIDTH);
    color->out = new_bgr_gradient(color->out, mod_bgr);
    my_mlx_pixel_put(img, x, y, color->out);
    if (iter >= 5 && iter <= 9)
    {
        if (iter % 2 == 0 && mod_bgr > 0.175 && mod_bgr < 0.675)
            color->out = new_bgr_gradient(color->out, (1 - mod_bgr));
        else if (mod_bgr > 0.675)
            color->out = new_bgr_gradient(color->out, (0 - mod_bgr));
        my_mlx_pixel_put(img, x, y, color->out);
        color->out = init_out;
    }
}

static void colorize_span(t_data *img, t_color *color, int x, int y, int iter)
{
    int init_outln;
    double mod_outln;

    init_outln = color->outln;
    if (iter % 2 == 0)
    {
        mod_outln = (double )iter / 16;
        color->outln = new_outln_gradient(color->out, mod_outln);
    }
    else
        color->outln = NAVY;
    my_mlx_pixel_put(img, x, y, color->outln);
    color->outln = init_outln;
}

void    colorize_mandelbrot(t_data *img, t_fract *fr, t_color *color, int x,
                            int y, int iter)
{
    if (iter < fr->max_iter)
    {
       if (iter < 10)
           colorize_bgr(img, color, x, y, iter);
        else if (iter >= 10 && iter <= 16)
           colorize_span(img, color, x, y, iter);
        else if (iter > 16 && iter < fr->max_iter)
            my_mlx_pixel_put(img, x, y, color->outln);
    }
    else
        my_mlx_pixel_put(img, x, y, color->in);
}
