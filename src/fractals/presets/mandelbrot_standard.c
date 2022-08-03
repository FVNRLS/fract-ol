/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_standard.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:57:31 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 18:49:14 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/fractol.h"

/*
	Lime on Black - Enter the Matrix...
*/
void	print_mandelbrot_matrix(t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	color->out = BLACK;
	color->in = BLACK;
	color->outln = LIME;
	update_image_to_standard(gui, fr, color);
}

/*
	Black Mandelbrot with blue background and white outline.
*/
void	print_mandelbrot_std_blue(t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	color->out = NAVY;
	color->in = BLACK;
	color->outln = WHITE;
	update_image_to_standard(gui, fr, color);
}

/*
	Black Mandelbrot with red background and white outline.
*/
void	print_mandelbrot_std_red(t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	color->out = RED;
	color->in = BLACK;
	color->outln = WHITE;
	update_image_to_standard(gui, fr, color);
}

/*
	Black Mandelbrot with 42 School background and white outline.
*/
void	print_mandelbrot_std_teal(t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	color->out = TEAL;
	color->in = BLACK;
	color->outln = WHITE;
	update_image_to_standard(gui, fr, color);
}

/*
	Black Mandelbrot with green background and white outline.
*/
void	print_mandelbrot_std_green(t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	color->out = GREEN;
	color->in = BLACK;
	color->outln = WHITE;
	update_image_to_standard(gui, fr, color);
}
