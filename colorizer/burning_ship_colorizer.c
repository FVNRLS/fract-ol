///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   burning_ship_colorizer.c                           :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2022/07/24 14:12:16 by rmazurit          #+#    #+#             */
///*   Updated: 2022/07/24 14:12:16 by rmazurit         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
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
        color->outln = BLUE;
    my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
    color->outln = init_outln;
}

void    colorize_burning_ship(t_gui *img, t_fract *fr, t_color *color)
{
    if (fr->iter < fr->max_iter)
    {
        if (fr->iter < 10)
            colorize_bgr(img, color, fr);
        else if (fr->iter >= 10 && fr->iter < 16)
            colorize_span(img, color, fr);
        else if (fr->iter >= 16 && fr->iter < fr->max_iter)
        {
            if (fr->iter % 3 == 0 && fr->iter % 10 != 0)
                my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, SILVER);
            if (fr->iter % 10 == 0)
                my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, TEAL);
            else
                my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
        }
    }
    else
        my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->in);
}