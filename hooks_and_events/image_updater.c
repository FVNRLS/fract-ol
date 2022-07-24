/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_updater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:34:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/24 11:36:22 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    update_image_to_3D(t_gui *gui, t_fract *fr, t_color *color)
{
    colorize_img_to_black(gui);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    print_3D_mandelbrot(gui, fr, color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    color->preset_found = true;
}

void    update_image_to_standard(t_gui *gui, t_fract *fr, t_color *color)
{
    colorize_img_to_black(gui);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    print_standard_mandelbrot(gui, fr, color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    color->preset_found = true;
}

void    update_image_to_psychedelic(t_gui *gui, t_fract *fr, t_color *color)
{
    colorize_img_to_black(gui);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    print_psychedelic_mandelbrot(gui, fr, color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    color->preset_found = true;
}

void    update_image_to_julia(t_gui *gui, t_fract *fr, t_color *color)
{
    colorize_img_to_black(gui);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    print_standard_julia(gui, fr, color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    color->preset_found = true;
}
