/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoomer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:42:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 16:10:33 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    zoom_in(t_gui *gui)
{
    gui->fract->zoom *= 0.75;
    apply_mods(gui);
}

void    zoom_out(t_gui *gui)
{
    gui->fract->zoom /= 0.75;
    apply_mods(gui);
}