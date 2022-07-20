/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:53:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/20 11:15:46 by rmazurit         ###   ########.fr       */
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
    gui->mlx = NULL;
    exit (0);
}

static void check_presets(int keycode, t_gui *gui)
{
    if (keycode == ONE)
        print_mandelbrot_matrix(gui);
    else if (keycode == TWO)
        print_mandelbrot_std_blue(gui);
    else if (keycode == THREE)
        print_mandelbrot_std_red(gui);
    else if (keycode == FOUR)
        print_mandelbrot_std_teal(gui);
    else if (keycode == FIVE)
        print_mandelbrot_std_green(gui);
    else if (keycode == SIX)
        print_mandelbrot_psych_acid(gui);
}


static int  check_keys(int keycode, t_gui *gui)
{
    if (keycode == ESC)
        ft_close(gui);
    check_presets(keycode, gui);

    return (0);
}


void    check_win_hooks(t_gui *gui)
{
    mlx_key_hook(gui->win, check_keys, gui);
    mlx_hook(gui->win, ON_DESTROY, 0, ft_close, gui);
}
