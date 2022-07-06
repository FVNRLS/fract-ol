/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/06 17:36:42 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void    check_leaks(void)
{
    system("leaks fractol");
}

int main(int argc, char **argv)
{
    atexit(check_leaks);
    check_args_nbr(argc);
    print_fractal(argv);
    return (0);
}