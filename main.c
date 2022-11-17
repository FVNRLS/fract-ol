/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit rmazurit@student.42heilbronn.de   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/28 12:00:43 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This program is able to create 3 types of fractals:
	Mandelbrot (incl. different presets)
	Julia
	Burning Ship (bonus)

	Each fractal is created using a specific calculation and rendered using 
	the library 'minilibx'.
	
	Using hotkeys it is possible to manipulate the fractal image.
	The following manipulations are available:
	Color Shift
	Zoom into the specific area (zoom follows mouse)
	Moving the fractal in different directions with arrow keys.
*/

#include "./incl/fractol.h"

int	main(int argc, char **argv)
{
	print_fractal(argc, argv);
	return (0);
}
