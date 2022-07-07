/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_standard.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:57:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/07 17:58:37 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int    print_mandelbrot_matrix(t_gui *gui)
{
    {
        t_color color;

        color.out = BLACK;
        color.in = BLACK;
        color.outln = LIME;
        mlx_destroy_image(gui->mlx, gui->img);
        gui->img = mlx_new_image(gui->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
        gui->addr = mlx_get_data_addr(gui->img, &gui->bits_per_pixel, &gui->line_length, &gui->endian);
        print_basic_mandelbrot(gui, &color);
        mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    }
}
