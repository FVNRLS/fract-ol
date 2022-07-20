/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_psychedelic.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:58:16 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/20 13:38:50 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void    print_mandelbrot_psych_acid(t_gui *gui)
{
    t_color color;

    color.out = LIME;
    color.in = PURPLE;
    color.outln = YELLOW;
    update_image_to_psychedelic(gui, &color);
}

void    print_mandelbrot_psych_cmyk(t_gui *gui)
{
    t_color color;

    color.out = MAGENTA;
    color.in = CYAN;
    color.outln = YELLOW;
    update_image_to_psychedelic(gui, &color);
}

void    print_mandelbrot_psych_depressive(t_gui *gui)
{
    t_color color;

    color.out = GRAY;
    color.in = BLACK;
    color.outln = SILVER;
    update_image_to_psychedelic(gui, &color);
}

void    print_mandelbrot_psych_bloody(t_gui *gui)
{
    t_color color;

    color.out = MAROON;
    color.in = BLACK;
    color.outln = WHITE;
    update_image_to_psychedelic(gui, &color);
}

void    print_mandelbrot_psych_ugly(t_gui *gui)
{
    t_color color;

    color.out = OLIVE;
    color.in = GREEN;
    color.outln = RED;
    update_image_to_psychedelic(gui, &color);
}