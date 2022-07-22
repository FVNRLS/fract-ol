/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:08:02 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/22 11:33:30 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

static void init_vert_horiz_mods(t_fract *fr)
{
    fr->vert_mod = 1;
    fr->horiz_mod = 1;
}

void init_mods(t_fract *fr)
{
    init_vert_horiz_mods(fr);
}

