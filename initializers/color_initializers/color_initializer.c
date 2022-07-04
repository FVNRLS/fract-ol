/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:12:38 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/04 16:39:51 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/fractol.h"

static void    init_inside_color(char **argv, t_color *color) //TODO: writeout colors!
{
    bool    color_initialized;

    color_initialized = false;
    color_initialized = init_main_inside_colors(argv, color);
    if (color_initialized == false)
        color_initialized = init_main_additional_colors(argv, color);
    if (color_initialized == false)



}

static void    init_outside_color(char **argv, t_color *color) //TODO: writeout colors!
{
    if (ft_strncmp(argv[3], "NAVY", 3) == 0)
        color->out = NAVY;
}

void    init_colors(char **argv, t_color *color)
{
    init_inside_color(argv, color);
    init_outside_color(argv, color);
}
