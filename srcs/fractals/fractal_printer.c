/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:36:36 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/26 17:39:15 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void    print_mandelbrot(int argc, char **argv, t_gui *gui, t_fract *fr, t_color *color)
{
    init_mods(fr);
    if (argc == 4 && ft_strcmp(argv[2], "PRESET") == 0)
    {
        check_mandelbrot_presets(argv, gui, fr, color);
        return ;
    }
    else
    {
        check_mandelbrot_args(argc, gui);
        init_colors(argv, color);
        check_colors(gui, color);
        print_3D_mandelbrot(gui, fr, color);
    }
    print_current_fractal_info(gui->fract, gui->color);
}

void    print_julia(int argc, char **argv, t_gui *gui, t_fract *fr, t_color *color)
{
    fr->type = JULIA;
    init_mods(fr);
    check_julia_args(argc, gui);
    init_colors(argv, color);
    check_colors(gui, color);
    gui->fract->j_re = atof(argv[5]);
    gui->fract->j_im = atof(argv[6]);
    if (gui->fract->j_re > 1 || gui->fract->j_im > 1)
        print_error(WRONG_CONSTANTS);
    print_standard_julia(gui, fr, color);
    print_current_fractal_info(gui->fract, gui->color);
}

void    print_burning_ship(int argc, char **argv, t_gui *gui, t_fract *fr, t_color *color)
{
    init_mods(fr);
    check_burning_ship_args(argc, gui);
    init_colors(argv, color);
    check_colors(gui, color);
    print_standard_burning_ship(gui, fr, color);
    print_current_fractal_info(gui->fract, gui->color);
}
