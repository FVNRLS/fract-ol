/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:11:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:28:29 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
 * -2 = min. of scope
 * 2 = max of scope
 * The values are used to modify the positioning of the fractal.
 * */
static void	scale_burning_ship(t_fract *fr)
{
	fr->x_scal = (double)fr->x_cor / WINSIZE;
	fr->y_scal = (double)fr->y_cor / WINSIZE;
	if (fr->zoom_activated == true)
	{
		fr->x_offset = fr->new_x_offset;
		fr->y_offset = fr->new_y_offset;
	}
	fr->c_re = (fr->x_offset * fr->horiz_mod) + (fr->x_scal * fr->view_scope);
	fr->c_im = (fr->y_offset * fr->vert_mod) - (fr->y_scal * fr->view_scope);
}

static int	calc_burning_ship(t_fract *fr)
{
	init_burning_ship(fr);
	scale_burning_ship(fr);
	while (fr->z < 4 && fr->iter < fr->max_iter)
	{
		fr->z = pow(fr->z_re, 2) + pow(fr->z_im, 2);
		fr->sum_re = pow(fr->z_re, 2) - pow(fr->z_im, 2) + fr->c_re;
		fr->sum_im = fabs(2 * (fr->z_re * fr->z_im)) - fr->c_im;
		fr->z_re = fr->sum_re;
		fr->z_im = fr->sum_im;
		fr->iter++;
	}
	return (fr->iter);
}

void	print_std_burn_ship(t_gui *gui, t_fract *fr, t_color *color)
{
	fr->x_cor = 0;
	fr->y_cor = 0;
	fr->type = BURNING_SHIP;
	while (fr->y_cor <= WINSIZE)
	{
		while (fr->x_cor <= WINSIZE)
		{
			fr->iter = calc_burning_ship(fr);
			colorize_burning_ship(gui, fr, color);
			fr->x_cor++;
		}
		fr->x_cor = 0;
		fr->y_cor++;
	}
	fr->iter = 0;
	fr->x_cor = 0;
	fr->y_cor++;
}
