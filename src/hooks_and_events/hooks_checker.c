/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:13:29 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:41:32 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
	Function to different keycodes.
 	See src/hooks_and_events/key_hooks.c for more info.
*/
static int	check_keys(int keycode, t_gui *gui)
{
	if (keycode == ESC)
		close_window(gui);
	check_presets(keycode, gui);
	check_arrow_keys(keycode, gui);
	check_fractal_hotkeys(keycode, gui);
	check_color_shift_keys(keycode, gui);
	check_info_printing_keys(keycode);
	return (0);
}

/*
	Checks for following actions and performs them respectively:
 	1)	mlx_hook:
 		Interaction with the window elements (minimize, close)
 	2)  mlx_key_hook:
 		Interaction with keyboard.
	3)	mlx_mouse_hook:
		Interaction with keyboard.
*/
void	check_win_hooks(t_gui *gui)
{
	mlx_hook(gui->win, ON_DESTROY, 0, close_window, gui);
	mlx_key_hook(gui->win, check_keys, gui);
	mlx_mouse_hook(gui->win, check_mouse_hooks, gui);
}
