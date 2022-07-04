/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outside_color_initializer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:40:15 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/04 17:35:06 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/fractol.h"

bool    init_main_outside_colors(char **argv, t_color *color)
{
    color->out = WRONG_COLOR;
    if (ft_strncmp(argv[3], "WHITE", 5) == 0)
        color->out = WHITE;
    else if (ft_strncmp(argv[3], "BLACK", 5) == 0)
        color->out = BLACK;
    else if (ft_strncmp(argv[3], "RED", 3) == 0)
        color->out = RED;
    else if (ft_strncmp(argv[3], "LIME", 4) == 0)
        color->out = LIME;
    else if (ft_strncmp(argv[3], "BLUE", 4) == 0)
        color->out = BLUE;
    else if (ft_strncmp(argv[3], "YELLOW", 6) == 0)
        color->out = YELLOW;
    else if (ft_strncmp(argv[3], "CYAN", 4) == 0)
        color->out = CYAN;
    else if (ft_strncmp(argv[3], "MAGENTA", 7) == 0)
        color->out = MAGENTA;
    if (color->out == WRONG_COLOR)
        return (false);
    return (true);
}

bool    init_additional_outside_colors(char **argv, t_color *color)
{
    if (color->out != WRONG_COLOR)
        return (true);
    color->out = WRONG_COLOR;
    if (ft_strncmp(argv[3], "SILVER", 6) == 0)
        color->out = SILVER;
    else if (ft_strncmp(argv[3], "GRAY", 4) == 0)
        color->out = GRAY;
    else if (ft_strncmp(argv[3], "MAROON", 6) == 0)
        color->out = MAROON;
    else if (ft_strncmp(argv[3], "OLIVE", 5) == 0)
        color->out = OLIVE;
    else if (ft_strncmp(argv[3], "GREEN", 5) == 0)
        color->out = GREEN;
    else if (ft_strncmp(argv[3], "PURPLE", 6) == 0)
        color->out = PURPLE;
    else if (ft_strncmp(argv[3], "TEAL", 4) == 0)
        color->out = TEAL;
    else if (ft_strncmp(argv[3], "NAVY", 4) == 0)
        color->out = NAVY;
    if (color->out == WRONG_COLOR)
        return (false);
    return (true);
}