/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_psychedelic.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:58:16 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/07 10:58:16 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void    print_mandelbrot_psych_acid(t_gui *gui)
{
    t_color color;

    color.out = LIME;
    color.in = PURPLE;
    color.outln = YELLOW;
    mlx_destroy_image(gui->mlx, gui->img);
    gui->img = mlx_new_image(gui->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
    gui->addr = mlx_get_data_addr(gui->img, &gui->bits_per_pixel, &gui->line_length, &gui->endian);
    print_psychedelic_mandelbrot(gui, &color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}