/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:53:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/24 15:35:09 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*TODO:
 * 1) optional: 360 degree rotation on key press
 * 4) change transparency of background with some key (+ -)
 *
 *
 * */

void check_presets(int keycode, t_gui *gui)
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
        print_mandelbrot_psych_depressive(gui, gui->fract, gui->color);
    else if (keycode == NINE)
        print_mandelbrot_psych_bloody(gui, gui->fract, gui->color);
    else if (keycode == ZERO)
        print_mandelbrot_psych_ugly(gui, gui->fract, gui->color);
}

void    check_arrow_keys(int keycode, t_gui *gui)
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

void    check_fractal_hotkeys(int keycode, t_gui *gui)
{
    if (keycode == J)
        update_image_to_julia(gui, gui->fract, gui->color);
    if (keycode == B)
        update_image_to_burningship(gui, gui->fract, gui->color);
}
