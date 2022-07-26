/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:34:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/26 17:34:49 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void    print_terminal_usage()
{
    ft_printf("                                     ✩░▒▓▆▅▃▂▁USAGE▁▂▃▅▆▓▒░✩\n");
    ft_printf(".-----------------------------------------------------------"
              "-----------------------------------------.\n"
              "|    MANDELBROT:     MANDELBROT INSIDE_COLOR OUTSIDE_COLOR"
              " OUTLINE_COLOR                             |\n"
              "|    JULIA:          JULIA INSIDE_COLOR OUTSIDE_COLOR "
              "OUTLINE_COLOR REAL_CONSTANT IMAGINARY_CONSTANT |\n"
              "|    BURNING_SHIP:   BURNING_SHIP INSIDE_COLOR "
              "OUTSIDE_COLOR OUTLINE_COLOR                           |\n"
              "|    PRESETS:        MANDELBROT PRESET PRESET_NAME"
              "                                                   |\n"
              "|                                                     "
              "                                               |\n"
              "|    (PRESS 'C' TO SHOW VALID COLORS AND PRESETS)          "
              "                                          |\n"
              "|    (PRESS 'K' TO SHOW VALID JULIA CONSTANTS         "
              "                                               |\n"
              ".---------------------------------------------------------"
              "-------------------------------------------.\n");
}

static void print_fractal_type(t_fract *fr)
{
    if (fr->type == MANDELBROT_3D)
        ft_printf("\nCurrent fractal:                   3D Mandelbrot\n");
    else if (fr->type == MANDELBROT_STD)
        ft_printf("\nCurrent fractal:                   Standard Mandelbrot\n");
    else if (fr->type == MANDELBROT_PSYCHEDELIC)
        ft_printf("\nCurrent fractal:                   Psychedelic Mandelbrot\n");
    else if (fr->type == JULIA)
        ft_printf("\nCurrent fractal:                   Julia \n");
    else if (fr->type == BURNING_SHIP)
        ft_printf("\nCurrent fractal:                   Burning Ship \n");
}

void    print_current_fractal_info(t_fract *fr, t_color *color)
{
    int r;
    int g;
    int b;

    print_fractal_type(fr);
    r = get_red(color->out);
    g = get_green(color->out);
    b = get_blue(color->out);
    ft_printf("Current background RGB Value:      %d  %d  %d\n\n", r, g, b);
}

void    print_error(int error)
{
    if (error == NO_INPUT)
    {
        ft_printf("\nError! (No input)\nInput a fractal name "
                  "as a first parameter!\n\n");
    }
    else if (error == WRONG_FRACTAL)
        ft_printf("\nError! (Wrong input)\nInput a valid fractal name!\n\n");
    else if (error == WRONG_COLOR)
        ft_printf("\nError! (Wrong input)\nInput a valid color!\n\n");
    else if (error == TOO_MANY_ARGUMENTS)
        ft_printf("\nError! (Too many arguments)\n\n");
    else if (error == TOO_FEW_ARGUMENTS)
        ft_printf("\nError! (Too few arguments)\n\n");
    else if (error == WRONG_CONSTANTS)
        ft_printf("\nError! (The provided constants are invalid)\n\n");
}

void    print_usage_info(void)
{
    print_terminal_usage();
    print_valid_colors();
    print_valid_julia_consts();
    ft_printf("                 ✩░▒▓▆▅▃▂▁HOTKEYS▁▂▃▅▆▓▒░✩\n");
    print_main_hotkeys_info();
    print_add_hotkeys_info();
}