/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:53:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/06 19:47:29 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*TODO:
 * 1) ARROW KEYS (UP, DOWN, LEFT, RIGHT) -> move pos of fractol in the window
 * 2) from 1 to 9 -> different presets (psychodelic)
 * 3) WASD --> look up in subject
 * 4) change transparency of background with some key (+ -)
 * 5) change gradient steps to fill (- +)
 *
 *
 * */

int	ft_close(t_gui *gui)
{
    mlx_destroy_window(gui->mlx, gui->win);
    free(gui->mlx);
    exit (0);
}

int	check_keys(int keycode, t_gui *gui)
{
    if (keycode == ESC)
        ft_close(gui);
    return (0);
}


void    check_win_hooks(t_gui *gui)
{

    mlx_key_hook(gui->win, check_keys, gui);
    mlx_hook(gui->win, ON_DESTROY, 0, ft_close, gui);
}
