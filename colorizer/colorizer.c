/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:48:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/20 12:48:49 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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


