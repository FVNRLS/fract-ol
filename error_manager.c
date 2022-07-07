/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:34:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/07 18:53:02 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

//TODO:
// check if fractol name sets to number of args!
// check presets
// printf the MENU

void    print_error(int error)
{
    if (error == NO_INPUT)
        write(2, "Error! (No input)\nInput for Mandelbrot fractal: "
                 "<FRACTAL_NAME> <INSIDE_COLOR> <OUTSIDE_COLOR>\n", 94);
    else if (error == WRONG_FRACTAL)
        write(2, "Error! (Wrong input)\nChoose another <FRACTAL_NAME>\n", 51);
    else if (error == WRONG_COLOR)
        write(2, "Error! (Wrong input)\nChoose another <COLOR>\n", 45);
    else if (error == TOO_MANY_ARGUMENTS)
        write(2, "Error! (Too many arguments)\nInput for Mandelbrot fractal: "
                 "<FRACTAL_NAME> <INSIDE_COLOR> <OUTSIDE_COLOR>\n", 104);
    else if (error == TOO_FEW_ARGUMENTS)
        write(2, "Error! (Too few arguments)\nInput for Mandelbrot fractal: "
                 "<FRACTAL_NAME> <INSIDE_COLOR> <OUTSIDE_COLOR>\n", 103);
}

bool    check_mandelbrot_args(int argc, t_gui *gui, t_color *color)
{
    if (argc != 5)
    {
        if (argc == 1)
            print_error(NO_INPUT);
        else if (argc < 5)
            print_error(TOO_FEW_ARGUMENTS);
        else if (argc > 5)
            print_error(TOO_MANY_ARGUMENTS);
        return (false);
    }
    return (true);
}

bool    check_mandelbrot_colors(int argc, t_gui *gui, t_color *color)
{
    if (color->in == NO_COLOR || color->out == NO_COLOR || color->outln == NO_COLOR)
    {
        print_error(WRONG_COLOR);
        return (false);
    }
    return (true);
}