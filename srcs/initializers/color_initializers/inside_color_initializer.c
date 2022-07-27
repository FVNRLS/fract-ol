/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_color_initializer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:40:24 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:46:59 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fractol.h"

void	init_main_inside_colors(char **argv, t_color *color)
{
	if (ft_strcmp(argv[2], "WHITE") == 0)
		color->in = WHITE;
	else if (ft_strcmp(argv[2], "BLACK") == 0)
		color->in = BLACK;
	else if (ft_strcmp(argv[2], "RED") == 0)
		color->in = RED;
	else if (ft_strcmp(argv[2], "LIME") == 0)
		color->in = LIME;
	else if (ft_strcmp(argv[2], "BLUE") == 0)
		color->in = BLUE;
	else if (ft_strcmp(argv[2], "YELLOW") == 0)
		color->in = YELLOW;
	else if (ft_strcmp(argv[2], "CYAN") == 0)
		color->in = CYAN;
	else if (ft_strcmp(argv[2], "MAGENTA") == 0)
	color->in = MAGENTA;
}

void	init_additional_inside_colors(char **argv, t_color *color)
{
	color->in = NO_COLOR;
	if (ft_strcmp(argv[2], "SILVER") == 0)
		color->in = SILVER;
	else if (ft_strcmp(argv[2], "GRAY") == 0)
		color->in = GRAY;
	else if (ft_strcmp(argv[2], "MAROON") == 0)
		color->in = MAROON;
	else if (ft_strcmp(argv[2], "OLIVE") == 0)
		color->in = OLIVE;
	else if (ft_strcmp(argv[2], "GREEN") == 0)
		color->in = GREEN;
	else if (ft_strcmp(argv[2], "PURPLE") == 0)
		color->in = PURPLE;
	else if (ft_strcmp(argv[2], "TEAL") == 0)
		color->in = TEAL;
	else if (ft_strcmp(argv[2], "NAVY") == 0)
		color->in = NAVY;
}
