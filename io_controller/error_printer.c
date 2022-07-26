/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:34:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/26 11:35:18 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//TODO:
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
