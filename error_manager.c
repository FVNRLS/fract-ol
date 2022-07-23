/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:34:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/23 13:56:41 by rmazurit         ###   ########.fr       */
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

void    check_mandelbrot_colors(t_gui *gui, t_color *color)
{
    if (color->in == NO_COLOR || color->out == NO_COLOR || color->outln == NO_COLOR)
    {
        print_error(WRONG_COLOR);
        free_all(gui);
        exit(EXIT_FAILURE);
    }
}

void    check_julia_args(int argc, char **argv, t_gui *gui)
{
    if (argc != 4)
    {
        if (argc < 4)
            print_error(TOO_FEW_ARGUMENTS);
        else if (argc > 4)
            print_error(TOO_MANY_ARGUMENTS);
        free_all(gui);
        exit(EXIT_FAILURE);
    }
    else
    {
        gui->fract->j_re = atof(argv[2]);
        gui->fract->j_im = atof(argv[3]);
        printf("j_re: %lf\n", gui->fract->j_re);
        printf("j_im: %lf\n", gui->fract->j_im);
    }
}