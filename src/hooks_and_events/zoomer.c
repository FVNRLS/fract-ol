/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoomer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:42:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/28 11:46:07 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

/*
	Zooms in the fractol picture to the point of the mouse pointer.
	The unscaled x/y mouse coordinates come from function check_mouse_hooks,
	(hooks_and_events/mouse_hooks.c).
	To zoom is a calculation of steps, needed to move the spot of the
	mouse pointer towards the center of the window.
	
	For that the actual positions should be calculated:
	-> re_pos (horizontal offset, related to scaled x coordinate).
	-> im_pos (vertical offset, related to scaled y coordinate).
	
	Then the view scope is modified by a standard factor ZOOM, defined in:
	incl/gui.h
	
	After that the new offsets (horizontal and vertical) should be calculated,
	which is the difference between, multiplied by the modified view_scope:
	-> (re_pos - scaled x mouse pos.) * modified view scope
	-> (im_pos - scaled y mouse pos.) * modified view scope
	Then function update_image triggers a recalculation of the appropriate
	fractal with the new modified offset (previous offset becomes new_offset).
	
	When zoom hook is activated, zoom_activated flag is set, so every fractol
	calculation relies every time on the changed offset values 
	(not on the initial offset!).
*/
void	zoom_in(t_gui *gui, int x, int y)
{
	t_fract	*fr;
	double	re_pos;
	double	im_pos;

	fr = gui->fract;
	fr->zoom_activated = true;
	re_pos = fr->x_offset + (((double)x / WINSIZE) * fr->view_scope);
	im_pos = fr->y_offset - (((double)y / WINSIZE) * fr->view_scope);
	fr->view_scope = ZOOM * gui->fract->view_scope;
	fr->new_x_offset = re_pos - (((double)x / WINSIZE) * fr->view_scope);
	fr->new_y_offset = im_pos + (((double)y / WINSIZE) * fr->view_scope);
	update_image(gui);
}

/*
	Works the same way like zoom_in.
	The only difference is that view scope is modified with 1/ZOOM factor.
*/
void	zoom_out(t_gui *gui, int x, int y)
{
	t_fract	*fr;
	double	zoom;
	double	re_pos;
	double	im_pos;

	zoom = 1 / ZOOM;
	fr = gui->fract;
	fr->zoom_activated = true;
	re_pos = fr->x_offset + (((double) x / WINSIZE) * fr->view_scope);
	im_pos = fr->y_offset - (((double) y / WINSIZE) * fr->view_scope);
	fr->view_scope = zoom * gui->fract->view_scope;
	fr->new_x_offset = re_pos - (((double) x / WINSIZE) * fr->view_scope);
	fr->new_y_offset = im_pos + (((double) y / WINSIZE) * fr->view_scope);
	update_image(gui);
}
