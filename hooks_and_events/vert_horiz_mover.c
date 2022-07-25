/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_horiz_mover.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:26:13 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/25 15:42:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    move_up(t_gui *gui)
{
    gui->fract->vert_mod -= 0.10 * gui->fract->view_scope;
    apply_mods(gui);
}

void    move_down(t_gui *gui)
{
    gui->fract->vert_mod += 0.10 * gui->fract->view_scope;
    apply_mods(gui);
}

void    move_left(t_gui *gui)
{
    gui->fract->horiz_mod -= 0.10 * gui->fract->view_scope;
    apply_mods(gui);
}

void    move_right(t_gui *gui)
{
    gui->fract->horiz_mod += 0.10 * gui->fract->view_scope;
    apply_mods(gui);
}