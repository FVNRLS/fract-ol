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

#include "../../incl/fractol.h"

/*
 	If user provided 'PRESET' as the second argument:
 		Check if user input matches with available presets.

	Otherwise:
	1) Check the number of arguments for validity.
	2) Check the colors for validity.
	3) If valid -> print Mandelbrot fractal in 3D.

	If one or more arguments are invalid - print a corresponding error message
 	and print the instructions how to use the program.
	Otherwise - just print the instructions.
 */
void	print_mandelbrot(t_args *args, t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	if (args->argc == 4 && ft_strcmp(args->argv[2], "PRESET") == 0)
		check_pres_input(args->argv, gui, fr, color);
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

/*
	1) Check the number of arguments for validity.
	2) Check the colors for validity.
	3) If valid --> convert the real and imaginary constants from user
		input and check for validity.
 	4) If everything is valid - print Julia fractal.

	If one or more arguments are invalid - print a corresponding error message
 	and print the instructions how to use the program.
 	Otherwise - just print the instructions.
 */
void	print_julia(t_args *args, t_gui *gui, t_fract *fr, t_color *color)
{
	fr->type = JULIA;
	init_mods(fr);
	check_julia_args(args->argc, gui);
	init_colors(args->argv, color);
	check_colors(gui, color);
	gui->fract->j_re = ft_atof(args->argv[5]);
	gui->fract->j_im = ft_atof(args->argv[6]);
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

/*
	Otherwise:
	1) Check the number of arguments for validity.
	2) Check the colors for validity.
	3) If valid -> print Burning Ship fractal.

	If one or more arguments are invalid - print a corresponding error message
 	and print the instructions how to use the program.
	Otherwise - just print the instructions.
 */
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
