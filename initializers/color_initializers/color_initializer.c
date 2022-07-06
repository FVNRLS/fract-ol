/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:12:38 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/05 10:44:25 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/fractol.h"

static void init_inside_color(char **argv, t_color *color)
{
    color->in = NO_COLOR;
    init_main_inside_colors(argv, color);
    if (color->in != NO_COLOR)
        return ;
    init_additional_inside_colors(argv, color);
}

static void init_outside_color(char **argv, t_color *color)
{
    color->out = NO_COLOR;
    if (color->in == NO_COLOR)
        return ;
    init_main_outside_colors(argv, color);
    if (color->out != NO_COLOR)
        return ;
    init_additional_outside_colors(argv, color);
}

static void init_outline_color(char **argv, t_color *color)
{
    color->outln = NO_COLOR;
    if (color->in == NO_COLOR || color->out == NO_COLOR)
        return ;
    init_main_outline_colors(argv, color);
    if (color->outln != NO_COLOR)
        return ;
    init_additional_outline_colors(argv, color);
}

void    init_colors(char **argv, t_color *color, void **mlx, void **win)
{

    init_inside_color(argv, color);
    init_outside_color(argv, color);
    init_outline_color(argv, color);
    if (color->in == NO_COLOR || color->out == NO_COLOR || color->outln == NO_COLOR)
    {
        print_error(WRONG_COLOR);
        free(*mlx);
        free(*win);
        exit (EXIT_FAILURE);
    }
}
