/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:13:29 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 15:13:29 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int  check_keys(int keycode, t_gui *gui)
{
    if (keycode == ESC)
        close_window(gui);
    check_presets(keycode, gui);
    check_arrow_keys(keycode, gui);
    return (0);
}

void    check_win_hooks(t_gui *gui)
{
    mlx_key_hook(gui->win, check_keys, gui);
    mlx_hook(gui->win, ON_DESTROY, 0, close_window, gui);
}