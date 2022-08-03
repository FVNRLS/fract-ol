/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_psychedelic.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:58:16 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 18:46:59 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fractol.h"

/*
	Psychedelic acid effect with use of pungent bright colors 
	(LIME + PURPLE + YELLOW)
*/
void	print_mandelbrot_psych_acid(t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	color->out = LIME;
	color->in = PURPLE;
	color->outln = YELLOW;
	update_image_to_psychedelic(gui, fr, color);
}

/*
	Standard CYAN MAGENTA YELLOW KEY color mixing 
	Thanks for my printing technology studies :))
*/
void	print_mandelbrot_psych_cmyk(t_gui *gui, t_fract *fr, t_color *color)
{
	color->out = MAGENTA;
	color->in = CYAN;
	color->outln = YELLOW;
	update_image_to_psychedelic(gui, fr, color);
}

/*
	Schwarz-graue Farbmischung
*/
void	print_mandelbrot_psych_depress(t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	color->out = GRAY;
	color->in = BLACK;
	color->outln = SILVER;
	update_image_to_psychedelic(gui, fr, color);
}

/*
	Use of the overlapping technique to print pixels of 2 fractals 
	on top of each other (--> the image will not be colorized black!)
	Thus, using the color 'MAROON', an effect of a bloodstain is created.
*/
void	print_mandelbrot_psych_bloody(t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	gui->img = mlx_new_image(gui->mlx, WINSIZE, WINSIZE);
	gui->addr = mlx_get_data_addr(gui->img, &gui->bits_per_pixel,
			&gui->line_length, &gui->endian);
	color->out = WHITE;
	color->in = BLACK;
	color->outln = NAVY;
	print_3d_mandelbrot(gui, fr, color);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	mlx_destroy_image(gui->mlx, gui->img);
	color->out = MAROON;
	color->in = BLACK;
	color->outln = WHITE;
	gui->img = mlx_new_image(gui->mlx, WINSIZE, WINSIZE);
	gui->addr = mlx_get_data_addr(gui->img, &gui->bits_per_pixel,
			&gui->line_length, &gui->endian);
	print_psychedelic_mandelbrot(gui, fr, color);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	color->preset_found = true;
}

/*
	Use of unsuitable contrasting colors.
*/
void	print_mandelbrot_psych_ugly(t_gui *gui, t_fract *fr, t_color *color)
{
	init_mods(fr);
	color->out = OLIVE;
	color->in = GREEN;
	color->outln = RED;
	update_image_to_psychedelic(gui, fr, color);
}
