/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presets_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:18:21 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:27:39 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fractol.h"

bool	print_presets(char **argv, t_gui *gui, t_fract *fr, t_color *color)
{
	color->preset_found = false;
	if (ft_strcmp(argv[3], "MATRIX") == 0)
		print_mandelbrot_matrix(gui, fr, color);
	else if (ft_strcmp(argv[3], "STD_BLUE") == 0)
		print_mandelbrot_std_blue(gui, fr, color);
	else if (ft_strcmp(argv[3], "STD_RED") == 0)
		print_mandelbrot_std_red(gui, fr, color);
	else if (ft_strcmp(argv[3], "STD_TEAL") == 0)
		print_mandelbrot_std_teal(gui, fr, color);
	else if (ft_strcmp(argv[3], "STD_GREEN") == 0)
		print_mandelbrot_std_green(gui, fr, color);
	else if (ft_strcmp(argv[3], "ACID") == 0)
		print_mandelbrot_psych_acid(gui, fr, color);
	else if (ft_strcmp(argv[3], "CMYK") == 0)
		print_mandelbrot_psych_cmyk(gui, fr, color);
	else if (ft_strcmp(argv[3], "DEPRESSIVE") == 0)
		print_mandelbrot_psych_depress(gui, fr, color);
	else if (ft_strcmp(argv[3], "BLOODY") == 0)
		print_mandelbrot_psych_bloody(gui, fr, color);
	else if (ft_strcmp(argv[3], "UGLY") == 0)
		print_mandelbrot_psych_ugly(gui, fr, color);
	return (color->preset_found);
}
