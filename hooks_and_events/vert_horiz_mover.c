/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_horiz_mover.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:26:13 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/21 18:17:03 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


//TODO: problem leaks and image and segfault!!!
void    move_up(t_gui *gui)
{
    gui->vert_mod -= 0.2;
    mlx_destroy_image(gui->mlx, gui->img);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
    print_3D_mandelbrot(gui, gui->color);
    mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
}