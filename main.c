/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/26 12:42:03 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

//TODO:
// PROBLEM 1: segfault with window HEIGHT > 550!!!
// PROBLEM 2: with WINDOW_WIDTH 800 and HEIGHT 500 only 3/4 of fractol is rendered

void    check_leaks(void)
{
    system("leaks fractol");
}

int main(int argc, char **argv)
{
//    atexit(check_leaks);
    print_usage_info();
    print_fractal(argc, argv);
    return (0);
}