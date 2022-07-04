/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/04 12:49:06 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"
/*
 * The function mimics the behaviour of mlx_pixel_put but is many times faster.
 * y and x are coordinates whee to input a pixel.
 */

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        print_error(NO_INPUT);
        return (EXIT_FAILURE);
    }
    if (argc > 6)
    {
        print_error(TOO_MANY_ARGUMENTS);
        return (EXIT_FAILURE);
    }
    print_fractal(argv);
    system("leaks fractol");
    return (0);
}