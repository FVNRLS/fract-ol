/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_b_shifter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:03:22 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/25 18:34:08 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

void    increase_green(t_gui *gui)
{
    int t;
    int r;
    int g;
    int b;

    t = get_transparency(gui->color->out);
    r = get_red(gui->color->out);
    g = get_green(gui->color->out);
    b = get_blue(gui->color->out);
    if (g < 255)
    {
        g += SHIFT_FACTOR;
        if (g > 255)
            g = 255;
    }
    gui->color->out = convert_rgb_to_hex(t, r, g, b);
    update_image(gui);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}

void    decrease_green(t_gui *gui)
{
    int t;
    int r;
    int g;
    int b;

    t = get_transparency(gui->color->out);
    r = get_red(gui->color->out);
    g = get_green(gui->color->out);
    b = get_blue(gui->color->out);
    if (r >= 0)
    {
        r -= SHIFT_FACTOR;
        if (r < 255)
            r = 0;
    }
    gui->color->out = convert_rgb_to_hex(t, r, g, b);
    update_image(gui);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}
