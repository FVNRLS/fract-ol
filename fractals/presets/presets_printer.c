/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presets_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:18:21 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/07 18:22:33 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void    print_preset(char **argv, t_gui *gui, t_color *color)
{
    if (ft_strncmp(argv[2], "MATRIX", 6) == 0)
        print_mandelbrot_matrix(gui);
}
