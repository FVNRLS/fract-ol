/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:53:58 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/06 17:45:31 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_close(t_gui *gui)
{
    mlx_destroy_window(gui->mlx, gui->win);
    free(gui->mlx);
    exit (0);
}

int	check_keys(int keycode, t_gui *gui)
{
    if (keycode == 12)
        ft_close(gui);
    return (0);
}


void    check_win_hooks(t_gui *gui)
{

    mlx_key_hook(gui->win, check_keys, gui);
    mlx_hook(gui->win, ON_DESTROY, 0, ft_close, gui);



}
