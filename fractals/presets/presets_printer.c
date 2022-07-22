/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presets_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:18:21 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 13:10:27 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

bool    check_print_preset(char **argv, t_gui *gui, t_fract *fr, t_color *color)
{
    color->preset_found = false;
    if (ft_strncmp(argv[3], "MATRIX", 6) == 0)
        print_mandelbrot_matrix(gui, fr, color);
    else if (ft_strncmp(argv[3], "STD_BLUE", 8) == 0)
        print_mandelbrot_std_blue(gui, fr, color);
    else if (ft_strncmp(argv[3], "STD_RED", 7) == 0)
        print_mandelbrot_std_red(gui, fr, color);
    else if (ft_strncmp(argv[3], "STD_TEAL", 8) == 0)
        print_mandelbrot_std_teal(gui, fr, color);
    else if (ft_strncmp(argv[3], "STD_GREEN", 9) == 0)
        print_mandelbrot_std_green(gui, fr, color);
    else if (ft_strncmp(argv[3], "ACID", 4) == 0)
        print_mandelbrot_psych_acid(gui, fr, color);
    else if (ft_strncmp(argv[3], "CMYK", 4) == 0)
        print_mandelbrot_psych_cmyk(gui, fr, color);
    else if (ft_strncmp(argv[3], "DEPRESSIVE", 10) == 0)
        print_mandelbrot_psych_depressive(gui, fr, color);
    else if (ft_strncmp(argv[3], "BLOODY", 6) == 0)
        print_mandelbrot_psych_bloody(gui, fr, color);
    else if (ft_strncmp(argv[3], "UGLY", 4) == 0)
        print_mandelbrot_psych_ugly(gui, fr, color);
    return (color->preset_found);
}

void    update_image_to_3D(t_gui *gui, t_fract *fr, t_color *color)
{
    mlx_destroy_image(gui->mlx, gui->img);
    gui->img = mlx_new_image(gui->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
    gui->addr = mlx_get_data_addr(gui->img, &gui->bits_per_pixel, &gui->line_length, &gui->endian);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    print_3D_mandelbrot(gui, fr, color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    color->preset_found = true;
}

void    update_image_to_standard(t_gui *gui, t_fract *fr, t_color *color)
{
    mlx_destroy_image(gui->mlx, gui->img);
    gui->img = mlx_new_image(gui->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
    gui->addr = mlx_get_data_addr(gui->img, &gui->bits_per_pixel, &gui->line_length, &gui->endian);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    print_standard_mandelbrot(gui, fr, color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    color->preset_found = true;
}

void    update_image_to_psychedelic(t_gui *gui, t_fract *fr, t_color *color)
{
    mlx_destroy_image(gui->mlx, gui->img);
    gui->img = mlx_new_image(gui->mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
    gui->addr = mlx_get_data_addr(gui->img, &gui->bits_per_pixel, &gui->line_length, &gui->endian);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    print_psychedelic_mandelbrot(gui, fr, color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    color->preset_found = true;
}
