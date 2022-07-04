/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:12:38 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/04 19:31:59 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/fractol.h"

static bool    init_inside_color(char **argv, t_color *color)
{
    bool    main_color_initialized;
    bool    additional_color_initialized;

    main_color_initialized = false;
    additional_color_initialized = false;
    main_color_initialized = init_main_inside_colors(argv, color);
    additional_color_initialized = init_additional_inside_colors(argv, color);
    if (main_color_initialized == false && additional_color_initialized == false)
        return (false);
    return (true);
}

static bool    init_outside_color(char **argv, t_color *color)
{
    bool    main_color_initialized;
    bool    additional_color_initialized;

    main_color_initialized = false;
    additional_color_initialized = false;
    main_color_initialized = init_main_outside_colors(argv, color);
    additional_color_initialized = init_additional_outside_colors(argv, color);
    if (main_color_initialized == false && additional_color_initialized == false)
        return (false);
    return (true);
}

void    init_colors(char **argv, t_color *color, void **mlx, void **win)
{
    bool in_color_initialized;
    bool out_color_initialized;

    in_color_initialized = init_inside_color(argv, color);
    out_color_initialized = init_outside_color(argv, color);
    if (in_color_initialized == false || out_color_initialized == false)
    {
        print_error(WRONG_COLOR);
        free(*mlx);
        free(*win);
        exit (EXIT_FAILURE);
    }
}
