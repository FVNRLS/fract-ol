/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:08:02 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/28 10:55:42 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	init_vert_horiz_mods(t_fract *fr)
{
	fr->vert_mod = 1;
	fr->horiz_mod = 1;
	fr->view_scope = 4;
}

static void	init_zoom_factor(t_fract *fr)
{
	fr->new_x_offset = 0;
	fr->new_y_offset = 0;
	fr->zoom_activated = false;
}

/*
	Initializes the starting modifiers for horizontal and vertical offset, as 
	well as the view scope.
	If an action happens (pressing arrow keys or using mouse wheel),
	the modifiers change and affect the fractal scaling.
	
	By default the zoom_activated flag is set to false.
	When zoom was activated once, the horizontal and vertical offset are
	derived from the new_x_offset and new_y_offset (not from standard init!).
	So with every next zooming the calculation relies on the modified offset.
*/
void	init_mods(t_fract *fr)
{
	init_vert_horiz_mods(fr);
	init_zoom_factor(fr);
}
