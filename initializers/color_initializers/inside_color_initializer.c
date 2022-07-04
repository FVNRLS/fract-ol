/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_color_initializer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:40:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/04 19:51:46 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/fractol.h"

bool    init_main_inside_colors(char **argv, t_color *color)
{
    color->in = WRONG_COLOR;
    if (ft_strncmp(argv[2], "WHITE", 5) == 0)
        color->in = WHITE;
    else if (ft_strncmp(argv[2], "BLACK", 5) == 0)
        color->in = BLACK;
    else if (ft_strncmp(argv[2], "RED", 3) == 0)
        color->in = RED;
    else if (ft_strncmp(argv[2], "LIME", 4) == 0)
        color->in = LIME;
    else if (ft_strncmp(argv[2], "BLUE", 4) == 0)
        color->in = BLUE;
    else if (ft_strncmp(argv[2], "YELLOW", 6) == 0)
        color->in = YELLOW;
    else if (ft_strncmp(argv[2], "CYAN", 4) == 0)
        color->in = CYAN;
    else if (ft_strncmp(argv[2], "MAGENTA", 7) == 0)
    color->in = MAGENTA;
    if (color->in == WRONG_COLOR)
        return (false);
    return (true);
}

bool    init_additional_inside_colors(char **argv, t_color *color)
{
    if (color->in != WRONG_COLOR)
        return (true);
    color->in = WRONG_COLOR;
    if (ft_strncmp(argv[2], "SILVER", 6) == 0)
        color->in = SILVER;
    else if (ft_strncmp(argv[2], "GRAY", 4) == 0)
        color->in = GRAY;
    else if (ft_strncmp(argv[2], "MAROON", 6) == 0)
        color->in = MAROON;
    else if (ft_strncmp(argv[2], "OLIVE", 5) == 0)
        color->in = OLIVE;
    else if (ft_strncmp(argv[2], "GREEN", 5) == 0)
        color->in = GREEN;
    else if (ft_strncmp(argv[2], "PURPLE", 6) == 0)
        color->in = PURPLE;
    else if (ft_strncmp(argv[2], "TEAL", 4) == 0)
        color->in = TEAL;
    else if (ft_strncmp(argv[2], "NAVY", 4) == 0)
        color->in = NAVY;
    if (color->in == WRONG_COLOR)
        return (false);
    return (true);
}
