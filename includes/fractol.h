/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:32:45 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/minilibx/mlx.h"
# include "../libs/ft_printf/ft_printf.h"
# include "structs.h"
# include "colors.h"
# include "errors.h"
# include "hooks.h"
# include "gui.h"
# include "bonus.h"

//FRACTAL TYPES MACROS
# define MANDELBROT_3D              1
# define MANDELBROT_STD             2
# define MANDELBROT_PSYCHEDELIC     3
# define JULIA                      4
# define BURNING_SHIP               5

//FRACTALS
void	print_fractal(int argc, char **argv);
void	print_mandelbrot(t_args *args, t_gui *gui, t_fract *fr, t_color *color);
void    print_3d_mandelbrot(t_gui *gui, t_fract *fr, t_color *color);
void	print_standard_mandelbrot(t_gui *gui, t_fract *fr, t_color *color);
void	print_psychedelic_mandelbrot(t_gui *gui, t_fract *fr, t_color *color);
void	print_julia(t_args *args, t_gui *gui, t_fract *fr, t_color *color);
void	print_standard_julia(t_gui *gui, t_fract *fr, t_color *color);

//PRESETS
void	check_presets(int keycode, t_gui *gui);
bool	print_presets(char **argv, t_gui *gui, t_fract *fr, t_color *color);
void	print_mandelbrot_matrix(t_gui *gui, t_fract *fr, t_color *color);
void	print_mandelbrot_std_blue(t_gui *gui, t_fract *fr, t_color *color);
void	print_mandelbrot_std_red(t_gui *gui, t_fract *fr, t_color *color);
void	print_mandelbrot_std_teal(t_gui *gui, t_fract *fr, t_color *color);
void	print_mandelbrot_std_green(t_gui *gui, t_fract *fr, t_color *color);
void	print_mandelbrot_psych_acid(t_gui *gui, t_fract *fr, t_color *color);
void	print_mandelbrot_psych_cmyk(t_gui *gui, t_fract *fr, t_color *color);
void	print_mandelbrot_psych_depress(t_gui *gui, t_fract *fr, t_color *color);
void	print_mandelbrot_psych_bloody(t_gui *gui, t_fract *fr, t_color *color);
void	print_mandelbrot_psych_ugly(t_gui *gui, t_fract *fr, t_color *color);

//INITIALIZERS
void	init_mandelbrot(t_fract *fr);
void	init_julia(t_fract *fr);
void	init_burning_ship(t_fract *fr);
void	init_colors(char **argv, t_color *color);
void	init_main_inside_colors(char **argv, t_color *color);
void	init_additional_inside_colors(char **argv, t_color *color);
void	init_main_outside_colors(char **argv, t_color *color);
void	init_additional_outside_colors(char **argv, t_color *color);
void	init_main_outline_colors(char **argv, t_color *color);
void	init_additional_outline_colors(char **argv, t_color *color);
void	init_mods(t_fract *fr);
void	check_mods(t_gui *gui);
void	update_image(t_gui *gui);

//TOOLS
double	ft_atof(const char *s);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	free_all(t_gui *gui);

#endif
