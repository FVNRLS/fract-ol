/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_freer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit rmazurit@student.42heilbronn.de   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:20:35 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/28 11:22:41 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

/*
	frees the initialized void pointers.
*/
void	free_all(t_gui *gui)
{
	free(gui->mlx);
	free(gui->win);
}
