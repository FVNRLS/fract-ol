/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit rmazurit@student.42heilbronn.de   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:53:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:42:15 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

/*
	Compare the input keycode with presets codes (from 0 to 9).
 	If the user input matches the existing keycode - print appropriate preset.
*/
void	check_presets(int keycode, t_gui *gui)
{
	if (keycode == ONE)
		print_mandelbrot_matrix(gui, gui->fract, gui->color);
	else if (keycode == TWO)
		print_mandelbrot_std_blue(gui, gui->fract, gui->color);
	else if (keycode == THREE)
		print_mandelbrot_std_red(gui, gui->fract, gui->color);
	else if (keycode == FOUR)
		print_mandelbrot_std_teal(gui, gui->fract, gui->color);
	else if (keycode == FIVE)
		print_mandelbrot_std_green(gui, gui->fract, gui->color);
	else if (keycode == SIX)
		print_mandelbrot_psych_acid(gui, gui->fract, gui->color);
	else if (keycode == SEVEN)
		print_mandelbrot_psych_cmyk(gui, gui->fract, gui->color);
	else if (keycode == EIGHT)
		print_mandelbrot_psych_depress(gui, gui->fract, gui->color);
	else if (keycode == NINE)
		print_mandelbrot_psych_bloody(gui, gui->fract, gui->color);
	else if (keycode == ZERO)
		print_mandelbrot_psych_ugly(gui, gui->fract, gui->color);
}

/*
	Compare the input keycode with arrow keys keycodes.
 	Move the picture towards the appropriate direction if matches found.
*/
void	check_arrow_keys(int keycode, t_gui *gui)
{
	if (keycode == UP)
		move_up(gui);
	else if (keycode == DOWN)
		move_down(gui);
	else if (keycode == LEFT)
		move_left(gui);
	else if (keycode == RIGHT)
		move_right(gui);
}

/*
 	Compare the input keycode with keys 'J' and 'B'.
 	If matches found: print Julia/Burning Ship fractals.
*/
void	check_fractal_hotkeys(int keycode, t_gui *gui)
{
	if (keycode == J)
	{
		gui->fract->zoom_activated = false;
		update_image_to_julia(gui, gui->fract, gui->color);
	}
	else if (keycode == B)
	{
		gui->fract->zoom_activated = false;
		update_image_to_burningship(gui, gui->fract, gui->color);
	}
}

/*
	Compare the input keycode with keys (Q,A,W,S,E,D).
 	If there is a match:
 	Change the background RGB color value according to the pressed key.
*/
void	check_color_shift_keys(int keycode, t_gui *gui)
{
	if (keycode == Q)
		increase_red(gui);
	else if (keycode == A)
		decrease_red(gui);
	else if (keycode == W)
		increase_green(gui);
	else if (keycode == S)
		decrease_green(gui);
	else if (keycode == E)
		increase_blue(gui);
	else if (keycode == D)
		decrease_blue(gui);
}

/*
	Compare the input keycode with keys (I, C, K, H)
 	If there is a match:
 	Print the appropriate information to the stdout.
*/
void	check_info_printing_keys(int keycode)
{
	if (keycode == I)
		print_usage_info();
	else if (keycode == C)
		print_valid_colors();
	else if (keycode == K)
		print_valid_julia_consts();
	else if (keycode == H)
		print_all_hotkeys();
}
