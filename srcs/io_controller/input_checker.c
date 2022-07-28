/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:37:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/28 11:17:03 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
	Compares and prints the user input with available presets with the function 
	print_presets.
	If both matches - preset is valid 	-> print the preset.
	If not 								-> free alloc. memory and exit.
*/
void	check_pres_input(char **argv, t_gui *gui, t_fract *fr, t_color *color)
{
	bool	preset_valid;

	preset_valid = print_presets(argv, gui, fr, color);
	if (preset_valid == true)
		return ;
	else
	{
		free_all(gui);
		exit(EXIT_FAILURE);
	}
}

/*
	Checks the number of arguments, provided by user.
	If the number of args is not 4 (fractal, inside, background, outline colors)
	--> print appropriate error message, free alloc. memory and exit.
*/
void	check_mandelbrot_args(int argc, t_gui *gui)
{
	if (argc != 5)
	{
		if (argc < 5)
			print_error(TOO_FEW_ARGUMENTS);
		else if (argc > 5)
			print_error(TOO_MANY_ARGUMENTS);
		free_all(gui);
		exit(EXIT_FAILURE);
	}
}

/*
	Compares the user input with available colors.
	If there is no match:
	-> print the appropriate error message, free alloc. memory and exit.
*/
void	check_colors(t_gui *gui, t_color *color)
{
	if (color->in == NO_COLOR || color->out == NO_COLOR
		|| color->outln == NO_COLOR)
	{
		print_error(WRONG_COLOR);
		free_all(gui);
		exit(EXIT_FAILURE);
	}
}

/*
	Checks the number of arguments, provided by user.
	If the number of args is not 6 
	(fractal, inside, background, outline colors, real const, imaginary const)
	--> print appropriate error message, free alloc. memory and exit.
*/
void	check_julia_args(int argc, t_gui *gui)
{
	if (argc != 7)
	{
		if (argc < 7)
			print_error(TOO_FEW_ARGUMENTS);
		else if (argc > 7)
			print_error(TOO_MANY_ARGUMENTS);
		free_all(gui);
		exit(EXIT_FAILURE);
	}
}

/*
	Checks the number of arguments, provided by user.
	If the number of args is not 4 (fractal, inside, background, outline colors)
	--> print appropriate error message, free alloc. memory and exit.
*/
void	check_burning_ship_args(int argc, t_gui *gui)
{
	if (argc != 5)
	{
		if (argc < 5)
			print_error(TOO_FEW_ARGUMENTS);
		else if (argc > 5)
			print_error(TOO_MANY_ARGUMENTS);
		free_all(gui);
		exit(EXIT_FAILURE);
	}
}
