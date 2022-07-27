/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_flags.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:37:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 14:26:59 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "structs.h"

# define NO_ERROR           0
# define NO_INPUT           1
# define WRONG_FRACTAL      2
# define WRONG_COLOR        3
# define TOO_MANY_ARGUMENTS 4
# define TOO_FEW_ARGUMENTS  5
# define WRONG_CONSTANTS    6

//INPUT OUTPUT CONTROLLERS
void	print_error(int error);
void	print_usage_info(void);
void	print_valid_colors(void);
void	print_valid_julia_consts(void);
void	print_all_hotkeys(void);
void	print_current_fractal_info(t_fract *fr, t_color *color);

//ARGUMENTS CHECKERS
void	check_mandelbrot(int argc, t_gui *gui, t_color *color);
void	check_pres_input(char **argv, t_gui *gui, t_fract *fr, t_color *color);
void	check_mandelbrot_args(int argc, t_gui *gui);
void	check_colors(t_gui *gui, t_color *color);
void	check_julia_args(int argc, t_gui *gui);
void	check_burning_ship_args(int argc, t_gui *gui);

#endif
