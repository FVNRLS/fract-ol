/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:34:19 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/04 13:07:48 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void    print_error(int error)
{
    if (error == NO_INPUT)
        write(1, "Error! (No input)\nInput: <FRACTAL_NAME> <COLOR>\n", 49);
    else if (error == WRONG_FRACTAL)
        write(1, "Error! (Wrong input)\nChoose another <FRACTAL_NAME>\n", 51);
    else if (error == WRONG_COLOR)
        write(1, "Error! (Wrong input)\nChoose another <COLOR>\n", 46);
    else if (error == TOO_MANY_ARGUMENTS)
        write(1, "Error! (Too many arguments)\nInput: <FRACTAL_NAME> "
                 "<COLOR>\n", 58); //TODO: edit!
}