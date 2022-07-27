/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outline_color_initializer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:54:18 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:47:37 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/fractol.h"

void	init_main_outline_colors(char **argv, t_color *color)
{
	if (ft_strcmp(argv[4], "WHITE") == 0)
		color->outln = WHITE;
	else if (ft_strcmp(argv[4], "BLACK") == 0)
		color->outln = BLACK;
	else if (ft_strcmp(argv[4], "RED") == 0)
		color->outln = RED;
	else if (ft_strcmp(argv[4], "LIME") == 0)
		color->outln = LIME;
	else if (ft_strcmp(argv[4], "BLUE") == 0)
		color->outln = BLUE;
	else if (ft_strcmp(argv[4], "YELLOW") == 0)
		color->outln = YELLOW;
	else if (ft_strcmp(argv[4], "CYAN") == 0)
		color->outln = CYAN;
	else if (ft_strcmp(argv[4], "MAGENTA") == 0)
		color->outln = MAGENTA;
}

void	init_additional_outline_colors(char **argv, t_color *color)
{
	if (ft_strcmp(argv[4], "SILVER") == 0)
		color->outln = SILVER;
	else if (ft_strcmp(argv[4], "GRAY") == 0)
		color->outln = GRAY;
	else if (ft_strcmp(argv[4], "MAROON") == 0)
		color->outln = MAROON;
	else if (ft_strcmp(argv[4], "OLIVE") == 0)
		color->outln = OLIVE;
	else if (ft_strcmp(argv[4], "GREEN") == 0)
		color->outln = GREEN;
	else if (ft_strcmp(argv[4], "PURPLE") == 0)
		color->outln = PURPLE;
	else if (ft_strcmp(argv[4], "TEAL") == 0)
		color->outln = TEAL;
	else if (ft_strcmp(argv[4], "NAVY") == 0)
		color->outln = NAVY;
}
