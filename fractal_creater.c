/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:45:41 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/04 16:07:20 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

static void select_fractal(char **argv, void **mlx, void **win, t_data *img)
{
    if (ft_strncmp(argv[1], "MANDELBROT", 10) == 0)
        print_mandelbrot(img, argv);
//    else if (ft_strncmp(argv[1], "JULIA", 5) == 0)
//        exit(0); //TODO:print Julia!
    else
    {
        free(*mlx);
        free(*win);
        print_error(WRONG_FRACTAL);
        exit(EXIT_FAILURE);
    }
}

void    print_fractal(char **argv)
{
    void	*mlx;
    void	*win;
    t_data	img;
    t_color color;

    mlx = mlx_init();
    if (!mlx)
        exit(EXIT_FAILURE);
    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fract-ol");
    if (!win)
    {
        free(mlx);
        exit(EXIT_FAILURE);
    }
    img.img = mlx_new_image(mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    init_colors(argv, &color);
    select_fractal(argv, &mlx, &win, &img);
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);
    mlx_loop(mlx);
    mlx_destroy_window(mlx, win);
    free(mlx);
}