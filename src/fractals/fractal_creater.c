/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_creater.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:45:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 15:30:13 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

/*
 	The function mimics the behaviour of mlx_pixel_put but is many times faster.
 	y and x are coordinates where to input a pixel.
 	line_length and bits_per_pixel values are system values and are
 	calculated from the function mlx_get_data_addr
 */
void	my_mlx_pixel_put(t_gui *gui, int x, int y, int color)
{
	char	*dst;

	dst = gui->addr + ((y * gui->line_length) + (x * gui->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
	Selects a fractal based on the user input.
	If the fractal name is incorrect or the user does not enter anything,
	the corresponding error message appears and the program exits in clean way
	(set pointer memory is freed).
*/
void	select_fractal(t_gui *gui, t_fract *fr, t_color *c, t_args *args)
{
	if (args->argc == 1)
	{
		print_error(NO_INPUT);
		free_all(gui);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(args->argv[1], "MANDELBROT") == 0)
		print_mandelbrot(args, gui, fr, c);
	else if (ft_strcmp(args->argv[1], "JULIA") == 0)
		print_julia(args, gui, fr, c);
	else if (ft_strcmp(args->argv[1], "BURNING_SHIP") == 0)
		print_burn_ship(args, gui, fr, c);
	else
	{
		print_error(WRONG_FRACTAL);
		free_all(gui);
		exit(EXIT_FAILURE);
	}
}

static void	protect_malloc(t_gui *gui)
{
	if (!gui->win)
	{
		free(gui->mlx);
		exit(EXIT_FAILURE);
	}
}

/*
 	Initializes all required structures.
	Creates a new window and a new image.
	Selects and prints a fractal based on the user input.
	Starts check_win_hooks loop that checks for user input (hooks)
 	from keyboard and mouse.
	Starts mlx_loop that constantly updates the image.
 */
void	print_fractal(int argc, char **argv)
{
	t_gui	gui;
	t_fract	fr;
	t_color	color;
	t_args	args;

	gui.fract = &fr;
	gui.color = &color;
	gui.args = &args;
	args.argc = argc;
	args.argv = argv;
	gui.mlx = mlx_init();
	if (!gui.mlx)
		exit(EXIT_FAILURE);
	gui.win = mlx_new_window(gui.mlx, WINSIZE, WINSIZE, "fract-ol");
	protect_malloc(&gui);
	gui.img = mlx_new_image(gui.mlx, WINSIZE, WINSIZE);
	gui.addr = mlx_get_data_addr(gui.img, &gui.bits_per_pixel,
			&gui.line_length, &gui.endian);
	select_fractal(&gui, &fr, &color, &args);
	mlx_put_image_to_window(gui.mlx, gui.win, gui.img, 0, 0);
	check_win_hooks(&gui);
	mlx_loop(gui.mlx);
}
