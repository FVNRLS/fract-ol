/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:48:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/24 13:00:07 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void    colorize_img_to_black(t_gui *gui)
{
    int x_cor;
    int y_cor;

    x_cor = 0;
    y_cor = 0;
    while (y_cor <= WINSIZE)
    {
        while (x_cor <= WINSIZE)
        {
            my_mlx_pixel_put(gui, x_cor, y_cor, BLACK);
            x_cor++;
        }
        x_cor = 0;
        y_cor++;
    }
}

int new_bgr_gradient(int trgb, double mod)
{
    int t;
    int r;
    int g;
    int b;
    int new_color;

    t = 200 * mod;
    r = get_red(trgb);
    g = get_green(trgb);
    b = get_blue(trgb);
    new_color = convert_rgb_to_hex(t, r, g, b);
    return (new_color);
}

int new_outln_gradient(int trgb, double mod)
{
    int t;
    int r;
    int g;
    int b;
    int new_color;

    t = 200 * mod;
    r = get_red(trgb);
    g = get_green(trgb);
    b = get_blue(trgb);
    new_color = convert_rgb_to_hex(t, r, g, b);
    return (new_color);
}

int new_aura(int trgb, t_fract *fr)
{
    int t;
    int r;
    int g;
    int b;
    int new_color;

    t = 20 * fr->iter;
    r = get_red(trgb);
    g = get_green(trgb);
    b = get_blue(trgb);
    new_color = convert_rgb_to_hex(t, r, g, b);
    return (new_color);
}

int invert_colors(int trgb, t_fract *fr)
{
    int t;
    int r;
    int g;
    int b;
    int new_color;

    t = 20 * fr->iter;
    r = get_red(trgb);
    g = get_green(trgb);
    b = get_blue(trgb);
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
    new_color = convert_rgb_to_hex(t, r, g, b);
    return (new_color);
}
