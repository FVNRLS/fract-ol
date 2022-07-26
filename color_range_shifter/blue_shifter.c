/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_shifter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:25:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/25 18:30:00 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

void    increase_blue(t_gui *gui)
{
    int t;
    int r;
    int g;
    int b;

    t = get_transparency(gui->color->out);
    r = get_red(gui->color->out);
    g = get_green(gui->color->out);
    b = get_blue(gui->color->out);
    if (b < 255)
    {
        b += SHIFT_FACTOR;
        if (b > 255)
            b = 255;
    }
    gui->color->out = convert_rgb_to_hex(t, r, g, b);
    update_image(gui);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}

void    decrease_blue(t_gui *gui)
{
    int t;
    int r;
    int g;
    int b;

    t = get_transparency(gui->color->out);
    r = get_red(gui->color->out);
    g = get_green(gui->color->out);
    b = get_blue(gui->color->out);
    if (b > 0)
    {
        b -= SHIFT_FACTOR;
        if (b <= 0)
            b = 0;
    }
    gui->color->out = convert_rgb_to_hex(t, r, g, b);
    update_image(gui);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}
