/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:36:36 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:34:27 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	print_mandelbrot(t_args *args, t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	if (args->argc == 4 && ft_strcmp(args->argv[2], "PRESET") == 0)
	{
		check_pres_input(args->argv, gui, fr, color);
		return ;
	}
	else
	{
		check_mandelbrot_args(args->argc, gui);
		init_colors(args->argv, color);
		check_colors(gui, color);
		print_3d_mandelbrot(gui, fr, color);
	}
	print_usage_info();
	print_current_fractal_info(gui->fract, gui->color);
}

void	print_julia(t_args *args, t_gui *gui, t_fract *fr, t_color *color)
{
	fr->type = JULIA;
	init_mods(fr);
	check_julia_args(args->argc, gui);
	init_colors(args->argv, color);
	check_colors(gui, color);
	gui->fract->j_re = atof(args->argv[5]);
	gui->fract->j_im = atof(args->argv[6]);
	if (gui->fract->j_re > 1 || gui->fract->j_im > 1)
	{
		print_error(WRONG_CONSTANTS);
		free_all(gui);
		exit(EXIT_FAILURE);
	}
	print_standard_julia(gui, fr, color);
	print_usage_info();
	print_current_fractal_info(gui->fract, gui->color);
}

void	print_burn_ship(t_args *args, t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	check_burning_ship_args(args->argc, gui);
	init_colors(args->argv, color);
	check_colors(gui, color);
	print_std_burn_ship(gui, fr, color);
	print_usage_info();
	print_current_fractal_info(gui->fract, gui->color);
}
