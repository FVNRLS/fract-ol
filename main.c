/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/03 19:06:08 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO:
// 1) protect all creations (window, img...)

#include "./includes/fractol.h"
/*
 * The function mimics the behaviour of mlx_pixel_put but is many times faster.
 * y and x are coordinates whee to input a pixel.
 */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void    create_window(void *mlx, void *win, t_data *img)
{
    mlx = mlx_init();
    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fract-ol"); //TODO: what is the problem???????

    img->img = mlx_new_image(mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

}

void    print_fractol(void)
{
    void	*mlx;
    void	*win;
    t_data	img;

//    mlx = mlx_init();
//    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fract-ol");
//
//    img.img = mlx_new_image(mlx, WINDOW_HEIGHT, WINDOW_WIDTH);
//    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    create_window(&mlx, &win, &img); //TODO: what is the problem???????
    print_mandelbrot(&img);
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);
    mlx_loop(mlx);

    mlx_destroy_window(mlx, win);
    free(mlx);
}

int main(void)
{
    print_fractol();
    return (0);
}