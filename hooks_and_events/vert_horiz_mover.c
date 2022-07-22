/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_horiz_mover.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:26:13 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 11:25:38 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


//TODO: problem leaks and image and segfault!!!
void    move_up(t_gui *gui)
{
    gui->vert_mod -= 0.2;
    mlx_destroy_image(gui->mlx, gui->img);
    gui->img = mlx_new_image(gui->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
    gui->addr = mlx_get_data_addr(gui->img, &gui->bits_per_pixel, &gui->line_length, &gui->endian);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    printf("type is: %d\n", gui->type);
    if (gui->type == MANDELBROT_3D)
        print_3D_mandelbrot(gui, gui->color);
    else if (gui->type == MANDELBROT_STD)
        print_standard_mandelbrot(gui, gui->color);
    else if (gui->type == MANDELBROT_PSYCHEDELIC)
        print_psychedelic_mandelbrot(gui, gui->color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}