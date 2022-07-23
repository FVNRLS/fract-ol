/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_colorizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:27:14 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/23 19:28:31 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void colorize_bgr(t_gui *img, t_color *color, t_fract *fr)
{
    double  mod_bgr;

    mod_bgr = (double)fr->x_cor / (double )(WINDOW_WIDTH);
    color->out = new_bgr_gradient(color->out, mod_bgr);
    my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
}

static void colorize_span(t_gui *img, t_color *color, t_fract *fr)
{
    int     init_outln;
    double  mod_outln;

    init_outln = color->outln;
    if (fr->iter % 2 == 0)
    {
        mod_outln = (double)fr->iter / 16;
        color->outln = new_outln_gradient(color->out, mod_outln);
    }
    else
        color->outln = BLACK;
    my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
    color->outln = init_outln;
}

static void colorize_inner_part(t_gui *img, t_color *color, t_fract *fr)
{
    int     init_in;
    double  mod_bgr;

    mod_bgr = (double)fr->x_cor / (double )(WINDOW_WIDTH);
    init_in = color->in;
    color->in = new_bgr_gradient(color->out, mod_bgr);
    my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
    color->in = init_in;
}


void    colorize_julia_with_gradient(t_gui *img, t_fract *fr, t_color *color)
{
    if (fr->iter < fr->max_iter)
    {
        if (fr->iter < 20)
            colorize_bgr(img, color, fr);
        else if (fr->iter >= 20 && fr->iter < 100)
            colorize_span(img, color, fr);
        else if (fr->iter >= 100 && fr->iter < 200)
            my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, NAVY);
        else if (fr->iter >= 200 && fr->iter < 300)
            my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, SILVER);
        else if (fr->iter >= 300 && fr->iter <= 400)
            my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, PURPLE);
        else if (fr->iter > 400 && fr->iter < fr->max_iter)
            colorize_inner_part(img, color, fr);
    }
    else
        my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->in);
}