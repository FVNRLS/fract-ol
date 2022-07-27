/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize_mandelbrot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:44:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/20 13:51:00 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void colorize_bgr(t_gui *img, t_color *color, t_fract *fr)
{
    int     init_out;
    double  mod_bgr;


    init_out = color->out;
    mod_bgr = (double)fr->x_cor / (double )(WINSIZE);
    color->out = new_bgr_gradient(color->out, mod_bgr);
    my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
    if (fr->iter >= 5 && fr->iter <= 9)
    {
        if (fr->iter % 2 == 0 && mod_bgr > 0.175 && mod_bgr < 0.675)
            color->out = new_bgr_gradient(color->out, (1 - mod_bgr));
        else if (mod_bgr > 0.675)
            color->out = new_bgr_gradient(color->out, (0 - mod_bgr));
        my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
        color->out = init_out;
    }
}

static void colorize_span(t_gui *img, t_color *color, t_fract *fr)
{
    int     init_outln;
    double  mod_outln;

    init_outln = color->outln;
    if (fr->iter % 2 == 0)
    {
        mod_outln = (double )fr->iter / 16;
        color->outln = new_outln_gradient(color->out, mod_outln);
    }
    else
        color->outln = BLACK;
    my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
    color->outln = init_outln;
}

void    colorize_with_gradient(t_gui *img, t_fract *fr, t_color *color)
{
    if (fr->iter < fr->max_iter)
    {
       if (fr->iter < 10)
           colorize_bgr(img, color, fr);
       else if (fr->iter >= 10 && fr->iter <= 16)
           colorize_span(img, color, fr);
       else if (fr->iter > 16 && fr->iter < fr->max_iter)
            my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
    }
    else
        my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->in);
}

void    colorize_with_basic_colors(t_gui *img, t_fract *fr, t_color *color)
{
    if (fr->iter < fr->max_iter)
    {
        if (fr->iter < 10)
            my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
        else if (fr->iter > 16 && fr->iter < fr->max_iter)
            my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
    }
    else
        my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->in);
}

void    colorize_with_aura(t_gui *img, t_fract *fr, t_color *color)
{
    if (fr->iter < fr->max_iter)
    {
        int     init_out;

        if (fr->iter < 10)
        {
            init_out = color->out;
            if (fr->iter % 2 == 0)
                color->out = new_aura(color->out, fr);
            else
                color->out = color->in;
            my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
            color->out = init_out;
        }
        else if (fr->iter >= 10 && fr->iter <= 16)
            colorize_span(img, color, fr);
        else if (fr->iter > 16 && fr->iter < fr->max_iter)
            my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
    }
    else
        my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->in);
}