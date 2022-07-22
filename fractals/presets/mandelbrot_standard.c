/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_standard.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:57:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/20 17:01:17 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void    print_mandelbrot_matrix(t_gui *gui, t_fract *fr, t_color *color)
{
        color->out = BLACK;
        color->in = BLACK;
        color->outln = LIME;
        update_image_to_standard(gui, fr, color);
}

void    print_mandelbrot_std_blue(t_gui *gui, t_fract *fr, t_color *color)
{
    color->out = NAVY;
    color->in = BLACK;
    color->outln = WHITE;
    update_image_to_standard(gui, fr, color);
}

void    print_mandelbrot_std_red(t_gui *gui, t_fract *fr, t_color *color)
{
    color->out = RED;
    color->in = BLACK;
    color->outln = WHITE;
    update_image_to_standard(gui, fr, color);
}

void    print_mandelbrot_std_teal(t_gui *gui, t_fract *fr, t_color *color)
{
    color->out = TEAL;
    color->in = BLACK;
    color->outln = WHITE;
    update_image_to_standard(gui, fr, color);
}

void    print_mandelbrot_std_green(t_gui *gui, t_fract *fr, t_color *color)
{
    color->out = GREEN;
    color->in = BLACK;
    color->outln = WHITE;
    update_image_to_standard(gui, fr, color);
}