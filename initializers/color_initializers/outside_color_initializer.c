/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outside_color_initializer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:40:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/05 10:43:40 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/fractol.h"

void    init_main_outside_colors(char **argv, t_color *color)
{
    if (ft_strcmp(argv[3], "WHITE") == 0)
        color->out = WHITE;
    else if (ft_strcmp(argv[3], "BLACK") == 0)
        color->out = BLACK;
    else if (ft_strcmp(argv[3], "RED") == 0)
        color->out = RED;
    else if (ft_strcmp(argv[3], "LIME") == 0)
        color->out = LIME;
    else if (ft_strcmp(argv[3], "BLUE") == 0)
        color->out = BLUE;
    else if (ft_strcmp(argv[3], "YELLOW") == 0)
        color->out = YELLOW;
    else if (ft_strcmp(argv[3], "CYAN") == 0)
        color->out = CYAN;
    else if (ft_strcmp(argv[3], "MAGENTA") == 0)
        color->out = MAGENTA;
}

void    init_additional_outside_colors(char **argv, t_color *color)
{
    if (ft_strcmp(argv[3], "SILVER") == 0)
        color->out = SILVER;
    else if (ft_strcmp(argv[3], "GRAY") == 0)
        color->out = GRAY;
    else if (ft_strcmp(argv[3], "MAROON") == 0)
        color->out = MAROON;
    else if (ft_strcmp(argv[3], "OLIVE") == 0)
        color->out = OLIVE;
    else if (ft_strcmp(argv[3], "GREEN") == 0)
        color->out = GREEN;
    else if (ft_strcmp(argv[3], "PURPLE") == 0)
        color->out = PURPLE;
    else if (ft_strcmp(argv[3], "TEAL") == 0)
        color->out = TEAL;
    else if (ft_strcmp(argv[3], "NAVY") == 0)
        color->out = NAVY;
}