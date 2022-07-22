/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:08:02 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 13:50:07 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

void    check_mods(t_gui *gui)
{
    if (gui->fract->vert_mod <= -0.5 || gui->fract->vert_mod >= 2.5)
        init_mods(gui->fract);
    else if (gui->fract->horiz_mod <= -0.2 || gui->fract->horiz_mod >= 2.2)
        init_mods(gui->fract);
}

static void init_vert_horiz_mods(t_fract *fr)
{
    fr->vert_mod = 1;
    fr->horiz_mod = 1;
}

void init_mods(t_fract *fr)
{
    init_vert_horiz_mods(fr);
}

