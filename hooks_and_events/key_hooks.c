/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:53:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 12:52:18 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*TODO:
 * 1) ARROW KEYS (UP, DOWN, LEFT, RIGHT) -> move pos of fractal in the window
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
    t_color color;

    if (keycode == ONE)
        print_mandelbrot_matrix(gui, gui->fract, &color);
    else if (keycode == TWO)
        print_mandelbrot_std_blue(gui, gui->fract, &color);
    else if (keycode == THREE)
        print_mandelbrot_std_red(gui, gui->fract, &color);
    else if (keycode == FOUR)
        print_mandelbrot_std_teal(gui, gui->fract, &color);
    else if (keycode == FIVE)
        print_mandelbrot_std_green(gui, gui->fract, &color);
    else if (keycode == SIX)
        print_mandelbrot_psych_acid(gui, gui->fract, &color);
    else if (keycode == SEVEN)
        print_mandelbrot_psych_cmyk(gui, gui->fract, &color);
    else if (keycode == EIGHT)
        print_mandelbrot_psych_depressive(gui, gui->fract, &color);
    else if (keycode == NINE)
        print_mandelbrot_psych_bloody(gui, gui->fract, &color);
    else if (keycode == ZERO)
        print_mandelbrot_psych_ugly(gui, gui->fract, &color);
}

static void check_arrow_keys(int keycode, t_gui *gui)
{
    if (keycode == UP)
        move_up(gui);
}

static int  check_keys(int keycode, t_gui *gui)
{
    if (keycode == ESC)
        ft_close(gui);
    check_presets(keycode, gui);
    check_arrow_keys(keycode, gui);
    return (0);
}

void    check_win_hooks(t_gui *gui)
{
    mlx_key_hook(gui->win, check_keys, gui);
    mlx_hook(gui->win, ON_DESTROY, 0, ft_close, gui);
}
