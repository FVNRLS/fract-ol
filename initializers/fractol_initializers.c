/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_initializers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:03:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/24 17:36:35 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

void    init_mandelbrot(t_fract *fr)
{
    fr->c_re = 0;
    fr->z = 0;
    fr->z_re = 0;
    fr->z_im = 0;
    fr->iter = 0;
    fr->max_iter = 600;
    fr->x_offset = -2.5;
    fr->y_offset = 2.0;
    if (fr->left_padded == true)
        fr->x_offset = -2.0;
}

void    init_julia(t_fract *fr)
{
    fr->c_re = 0;
    fr->z = 0;
    fr->z_re = 0;
    fr->z_im = 0;
    fr->iter = 0;
    fr->max_iter = 600;
    fr->x_offset = -2.0;
    fr->y_offset = 2.0;
}

void    init_burning_ship(t_fract *fr)
{
    fr->c_re = 0;
    fr->z = 0;
    fr->z_re = 0;
    fr->z_im = 0;
    fr->iter = 0;
    fr->max_iter = 600;
    fr->x_offset = -2.5;
    fr->y_offset = 2.5;
}
