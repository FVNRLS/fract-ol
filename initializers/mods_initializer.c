/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:08:02 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/25 18:56:19 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

static void init_vert_horiz_mods(t_fract *fr)
{
    fr->vert_mod = 1;
    fr->horiz_mod = 1;
    fr->view_scope = 4;
}

static void init_zoom_factor(t_fract *fr)
{
    fr->new_x_offset = 0;
    fr->new_y_offset = 0;
    fr->zoom_activated = false;
}

void init_mods(t_fract *fr)
{
    init_vert_horiz_mods(fr);
    init_zoom_factor(fr);
}

