/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outline_color_initializer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:54:18 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/06 09:54:18 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/fractol.h"

void    init_main_outline_colors(char **argv, t_color *color)
{
    if (ft_strncmp(argv[4], "WHITE", 5) == 0)
        color->outln = WHITE;
    else if (ft_strncmp(argv[4], "BLACK", 5) == 0)
        color->outln = BLACK;
    else if (ft_strncmp(argv[4], "RED", 3) == 0)
        color->outln = RED;
    else if (ft_strncmp(argv[4], "LIME", 4) == 0)
        color->outln = LIME;
    else if (ft_strncmp(argv[4], "BLUE", 4) == 0)
        color->outln = BLUE;
    else if (ft_strncmp(argv[4], "YELLOW", 6) == 0)
        color->outln = YELLOW;
    else if (ft_strncmp(argv[4], "CYAN", 4) == 0)
        color->outln = CYAN;
    else if (ft_strncmp(argv[4], "MAGENTA", 7) == 0)
        color->outln = MAGENTA;
}

void    init_additional_outline_colors(char **argv, t_color *color)
{
    if (ft_strncmp(argv[4], "SILVER", 6) == 0)
        color->outln = SILVER;
    else if (ft_strncmp(argv[4], "GRAY", 4) == 0)
        color->outln = GRAY;
    else if (ft_strncmp(argv[4], "MAROON", 6) == 0)
        color->outln = MAROON;
    else if (ft_strncmp(argv[4], "OLIVE", 5) == 0)
        color->outln = OLIVE;
    else if (ft_strncmp(argv[4], "GREEN", 5) == 0)
        color->outln = GREEN;
    else if (ft_strncmp(argv[4], "PURPLE", 6) == 0)
        color->outln = PURPLE;
    else if (ft_strncmp(argv[4], "TEAL", 4) == 0)
        color->outln = TEAL;
    else if (ft_strncmp(argv[4], "NAVY", 4) == 0)
        color->outln = NAVY;
}