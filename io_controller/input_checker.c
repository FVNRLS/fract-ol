/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:37:06 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/26 11:38:55 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    check_mandelbrot_presets(char **argv, t_gui *gui, t_fract *fr, t_color *color)
{
    bool    preset_valid;

    preset_valid = check_print_preset(argv, gui, fr, color);
    if (preset_valid == true)
        return ;
    else
    {
        free_all(gui);
        exit(EXIT_FAILURE);
    }
}

void    check_mandelbrot_args(int argc, t_gui *gui)
{
    if (argc != 5)
    {
        if (argc < 5)
            print_error(TOO_FEW_ARGUMENTS);
        else if (argc > 5)
            print_error(TOO_MANY_ARGUMENTS);
        free_all(gui);
        exit(EXIT_FAILURE);
    }
}

void    check_colors(t_gui *gui, t_color *color)
{
    if (color->in == NO_COLOR || color->out == NO_COLOR || color->outln == NO_COLOR)
    {
        print_error(WRONG_COLOR);
        free_all(gui);
        exit(EXIT_FAILURE);
    }
}

void    check_julia_args(int argc, t_gui *gui)
{
    if (argc != 7)
    {
        if (argc < 7)
            print_error(TOO_FEW_ARGUMENTS);
        else if (argc > 7)
            print_error(TOO_MANY_ARGUMENTS);
        free_all(gui);
        exit(EXIT_FAILURE);
    }
}

void    check_burning_ship_args(int argc, t_gui *gui)
{
    if (argc != 5)
    {
        if (argc < 5)
            print_error(TOO_FEW_ARGUMENTS);
        else if (argc > 5)
            print_error(TOO_MANY_ARGUMENTS);
        free_all(gui);
        exit(EXIT_FAILURE);
    }
}
