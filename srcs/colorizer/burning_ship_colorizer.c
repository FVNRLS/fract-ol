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
#include "../../includes/fractol.h"

static void colorize_bgr(t_gui *img, t_color *color, t_fract *fr)
{
    double  mod_bgr;

    mod_bgr = (double)fr->x_cor / (double )(WINSIZE);
    color->out = new_bgr_gradient(color->out, mod_bgr);
    my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
}

static void colorize_span(t_gui *img, t_color *color, t_fract *fr)
{
    int     init_out;
    double  mod_out;

    init_out = color->out;
    mod_out =  (24 -(double)fr->iter) / 24;
    color->out = new_outln_gradient(color->out, mod_out);
    my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->out);
    color->out = init_out;
}

void    colorize_burning_ship(t_gui *img, t_fract *fr, t_color *color)
{
    if (fr->iter < fr->max_iter)
    {
        if (fr->iter < 14)
            colorize_bgr(img, color, fr);
        else if (fr->iter >= 14 && fr->iter < 32)
            colorize_span(img, color, fr);
        else if (fr->iter >= 32 && fr->iter < fr->max_iter)
                my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->outln);
    }
    else
        my_mlx_pixel_put(img, fr->x_cor, fr->y_cor, color->in);
}