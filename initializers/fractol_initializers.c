/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_initializers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:03:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/05 11:15:49 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

void    init_mandelbrot(t_fract *fr)
{
    fr->c_re = 0;
    fr->c_im = 0;
    fr->z = 0;
    fr->z_re = 0;
    fr->z_im = 0;
    fr->max_iter = 600;
}
