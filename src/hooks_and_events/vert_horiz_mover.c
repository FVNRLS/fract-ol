/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_horiz_mover.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit rmazurit@student.42heilbronn.de   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:26:13 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:43:42 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

/*
 	Modifies the view_scope (see fractals scaling functions) to move
 	the fractal picture up/down/left/right.
*/
void	move_up(t_gui *gui)
{
	gui->fract->vert_mod -= 0.10 * gui->fract->view_scope;
	update_image(gui);
}

void	move_down(t_gui *gui)
{
	gui->fract->vert_mod += 0.10 * gui->fract->view_scope;
	update_image(gui);
}

void	move_left(t_gui *gui)
{
	gui->fract->horiz_mod -= 0.10 * gui->fract->view_scope;
	update_image(gui);
}

void	move_right(t_gui *gui)
{
	gui->fract->horiz_mod += 0.10 * gui->fract->view_scope;
	update_image(gui);
}
