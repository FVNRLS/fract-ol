/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:13:25 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/23 17:54:46 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void scale_julia_coords(t_fract *fr)
{
    fr->c_re = (fr->horiz * 1) + (((double)fr->x_cor / WINDOW_WIDTH) * 4);
    fr->c_im = (fr->vert * 1) - (((double )fr->y_cor / WINDOW_HEIGHT) * 4);
}

static int calc_julia(t_fract *fr)
{
    init_julia(fr);
    scale_julia_coords(fr);
    fr->z_re = fr->c_re;
    fr->z_im = fr->c_im;
    while(fr->z < 4 && fr->iter < fr->max_iter)
    {
        fr->z = pow(fr->z_re, 2) + pow(fr->z_im, 2);
        fr->sum_re = pow(fr->z_re, 2) - pow(fr->z_im, 2) + fr->j_re;
        fr->sum_im = 2 * (fr->z_re * fr->z_im) + fr->j_im;
        fr->z_re = fr->sum_re;
        fr->z_im = fr->sum_im;
        fr->iter++;
    }
    return (fr->iter);
}

void    print_standard_julia(t_gui *gui, t_fract *fr, t_color *color)
{
    fr->x_cor = 0;
    fr->y_cor = 0;
    fr->left_padded = false;
    while (fr->y_cor <= WINDOW_HEIGHT)
    {
        while (fr->x_cor <= WINDOW_WIDTH)
        {
            fr->iter = calc_julia(fr);
            if (fr->iter < fr->max_iter)
                my_mlx_pixel_put(gui, fr->x_cor, fr->y_cor, RED);
            else
                my_mlx_pixel_put(gui, fr->x_cor, fr->y_cor, BLACK);
            fr->x_cor++;
        }
        fr->iter = 0;
        fr->x_cor = 0;
        fr->y_cor++;
    }
}