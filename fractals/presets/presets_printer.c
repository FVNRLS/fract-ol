/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presets_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:18:21 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/20 13:38:50 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void    print_preset(char **argv, t_gui *gui, t_color *color)
{
    if (ft_strncmp(argv[2], "MATRIX", 6) == 0)
        print_mandelbrot_matrix(gui);
}

void    update_image_to_psychedelic(t_gui *gui, t_color *color)
{
    mlx_destroy_image(gui->mlx, gui->img);
    gui->img = mlx_new_image(gui->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
    gui->addr = mlx_get_data_addr(gui->img, &gui->bits_per_pixel, &gui->line_length, &gui->endian);
    print_psychedelic_mandelbrot(gui, color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}

void    update_image_to_standard(t_gui *gui, t_color *color)
{
    mlx_destroy_image(gui->mlx, gui->img);
    gui->img = mlx_new_image(gui->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
    gui->addr = mlx_get_data_addr(gui->img, &gui->bits_per_pixel, &gui->line_length, &gui->endian);
    print_standard_mandelbrot(gui, color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}