/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:36:36 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/23 13:56:41 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void    print_mandelbrot(int argc, char **argv, t_gui *gui, t_fract *fr, t_color *color)
{
    init_mods(fr);
    if (argc == 4 && ft_strncmp(argv[2], "PRESET", 6) == 0)
    {
        check_mandelbrot_presets(argv, gui, fr, color);
        return ;
    }
    else
    {
        check_mandelbrot_args(argc, gui);
        init_colors(argv, color);
        check_mandelbrot_colors(gui, color);
        print_3D_mandelbrot(gui, fr, color);
    }
}

void    print_julia(int argc, char **argv, t_gui *gui, t_fract *fr, t_color *color)
{
        check_julia_args(argc, argv, gui);
//        init_colors(argv, color);
//        check_mandelbrot_colors(gui, color);
//        print_standard_julia(gui, fr, color);
}
