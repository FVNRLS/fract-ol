/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:45:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/24 10:31:32 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * The function mimics the behaviour of mlx_pixel_put but is many times faster.
 * y and x are coordinates whee to input a pixel.
 */

void	my_mlx_pixel_put(t_gui *gui, int x, int y, int color)
{
    char	*dst;

    dst = gui->addr + (y * gui->line_length + x * (gui->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void select_fractal(t_gui *gui, t_fract *fr, t_color *color, int argc, char **argv)
{
    if (argc == 1)
    {
        print_error(NO_INPUT);
        free_all(gui);
        exit(EXIT_FAILURE);
    }
    if (ft_strncmp(argv[1], "MANDELBROT", 10) == 0)
        print_mandelbrot(argc, argv, gui, fr, color);
    else if (ft_strncmp(argv[1], "JULIA", 5) == 0)
        print_julia(argc, argv, gui, fr, color);
}

void    print_fractal(int argc, char **argv)
{
   t_gui    gui;
   t_fract fr;
   t_color color;

    gui.fract = &fr;
    gui.color = &color;
    gui.mlx = mlx_init();
    if (!gui.mlx)
        exit(EXIT_FAILURE);
    gui.win = mlx_new_window(gui.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fract-ol");
    if (!gui.win)
    {
        free(gui.mlx);
        exit(EXIT_FAILURE);
    }
    gui.img = mlx_new_image(gui.mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
    gui.addr = mlx_get_data_addr(gui.img, &gui.bits_per_pixel, &gui.line_length, &gui.endian);
    select_fractal(&gui, &fr, &color, argc, argv);
    mlx_put_image_to_window(gui.mlx, gui.win, gui.img, 0, 0);
    check_win_hooks(&gui);
    mlx_loop(gui.mlx);
}