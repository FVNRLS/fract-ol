/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/04 19:06:13 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"
/*
 * The function mimics the behaviour of mlx_pixel_put but is many times faster.
 * y and x are coordinates whee to input a pixel.
 */

int main(int argc, char **argv)
{
    check_args_nbr(argc);
    print_fractal(argv);
    system("leaks fractol");
    return (0);
}