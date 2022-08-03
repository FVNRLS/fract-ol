/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:12:38 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/03 18:32:58 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incl/fractol.h"

static void	init_inside_color(char **argv, t_color *color)
{
	color->in = NO_COLOR;
	init_main_inside_colors(argv, color);
	if (color->in != NO_COLOR)
		return ;
	init_additional_inside_colors(argv, color);
}

static void	init_outside_color(char **argv, t_color *color)
{
	color->out = NO_COLOR;
	if (color->in == NO_COLOR)
		return ;
	init_main_outside_colors(argv, color);
	if (color->out != NO_COLOR)
		return ;
	init_additional_outside_colors(argv, color);
}

static void	init_outline_color(char **argv, t_color *color)
{
	color->outln = NO_COLOR;
	if (color->in == NO_COLOR || color->out == NO_COLOR)
		return ;
	init_main_outline_colors(argv, color);
	if (color->outln != NO_COLOR)
		return ;
	init_additional_outline_colors(argv, color);
}

/*
	Checks for the user color input validity and initializes following colors:
	--> inside, outline, background.
	If color input is invalid, then the color gets 'NO_COLOR' flag and
	program exits with a appropriate error message.
	The available colors can be derived from incl/colors.h
	
	Important:
	The initialization order is important in this function, because each 
	next step relies on the previous!
	inside->outside->outline
*/
void	init_colors(char **argv, t_color *color)
{
	init_inside_color(argv, color);
	init_outside_color(argv, color);
	init_outline_color(argv, color);
}
