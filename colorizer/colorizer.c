/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:48:45 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/05 12:33:17 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void modify_transparency(int *t, int mod)
{
    *t = 256 / mod;
}

int get_new_gradient(int trgb, int mod)
{
    int t;
    int r;
    int g;
    int b;
    int new_color;

    t = get_transparency(trgb);
    r = get_red(trgb);
    g = get_green(trgb);
    b = get_blue(trgb);
    modify_transparency(&t, mod);
    new_color = convert_rgb_to_hex(t, r, g, b);
    return (new_color);
}


