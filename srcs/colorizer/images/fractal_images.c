/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:34:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 16:54:26 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fractol.h"

/*
	Prints a 3D Mandelbrot image on the window.
		To avoid overlapping of the images - first colorize the existing 
		image with black (the rendering works a bit faster with this technique).
	Sets the preset flag to true.
	Renews the fractal information on stdout.
*/
void	update_image_to_3d(t_gui *gui, t_fract *fr, t_color *color)
{
	colorize_img_to_black(gui);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	print_3d_mandelbrot(gui, fr, color);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	color->preset_found = true;
	print_current_fractal_info(gui->fract, gui->color);
}

/*
	Prints a Standard Mandelbrot image on the window.
		To avoid overlapping of the images - first colorize the existing 
		image with black (the rendering works a bit faster with this technique).
	Sets the preset flag to true.
	Renews the fractal information on stdout.
*/
void	update_image_to_standard(t_gui *gui, t_fract *fr, t_color *color)
{
	colorize_img_to_black(gui);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	print_standard_mandelbrot(gui, fr, color);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	color->preset_found = true;
	print_current_fractal_info(gui->fract, gui->color);
}

/*
	Prints a Psychedelic Mandelbrot image on the window.
		To avoid overlapping of the images - first colorize the existing 
		image with black (the rendering works a bit faster with this technique).
	Sets the preset flag to true.
	Renews the fractal information on stdout.
*/
void	update_image_to_psychedelic(t_gui *gui, t_fract *fr, t_color *color)
{
	colorize_img_to_black(gui);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	print_psychedelic_mandelbrot(gui, fr, color);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	color->preset_found = true;
	print_current_fractal_info(gui->fract, gui->color);
}

/*
	Prints a Julia fractol image on the window.
		To avoid overlapping of the images - first colorize the existing 
		image with black (the rendering works a bit faster with this technique).
	If the previous fractol type was not Julia, sets the real and imaginary
	constants to -0.7269 and 0.1889 respectively, because in normal case
	Julia needs the constants provided as stdargs.
	Sets the preset flag to true.
	Renews the fractal information on stdout.
*/
void	update_image_to_julia(t_gui *gui, t_fract *fr, t_color *color)
{
	if (fr->type != JULIA)
	{
		gui->fract->j_re = -0.7269;
		gui->fract->j_im = 0.1889;
	}
	colorize_img_to_black(gui);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	print_standard_julia(gui, fr, color);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	print_current_fractal_info(gui->fract, gui->color);
}

/*
	Prints a Burning Ship fractal image on the window.
		To avoid overlapping of the images - first colorize the existing 
		image with black (the rendering works a bit faster with this technique).
	Sets the preset flag to true.
	Renews the fractal information on stdout.
*/
void	update_image_to_burningship(t_gui *gui, t_fract *fr, t_color *color)
{
	colorize_img_to_black(gui);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	print_std_burn_ship(gui, fr, color);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	print_current_fractal_info(gui->fract, gui->color);
}
