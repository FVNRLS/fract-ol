/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/01 19:08:58 by rmazurit         ###   ########.fr       */
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

/*
 * -2 = min. of scope
 * 2 = max of scope
 * */
void scale_coords(double *x, double *y)
{
    *x = (-2 + ((*x / WINDOW_WIDTH) * 4));
    *y = (2 - ((*y / WINDOW_HEIGHT) * 4));

}

int calc_mandelbrot(double x, double y)
{
    int     i;
    double  z_re;
    double  z_im;
    double  z_re2;
    double  z_im2;
    scale_coords(&x, &y);
//    printf("x: %f, y: %f\n",x, y );
    z_re = 0;
    z_im = 0;
    z_re2 = 0;
    z_im2 = 0;
    i = 0;
    while ((z_re2 + z_im2) < 4 && i <= MAX_ITER)
    {
        z_re2 = pow(z_re, 2);
        z_im2 = pow(z_im, 2);
        z_re = z_re2 - z_im2 + x;
        z_im = (2 * z_re * z_im) + y;
        i++;
    }
    return (i);
}

int main(void)
{
    void	*mlx;
    void	*win;
    t_data	img;
    double  x;
    double  y;
    int     iter;

    mlx = mlx_init();
    win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");

    img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    x = 0;
    y = 0;
    while (y <= WINDOW_HEIGHT)
    {
        while (x <= WINDOW_WIDTH)
        {
            iter = calc_mandelbrot(x, y);
            if (iter < MAX_ITER)
                my_mlx_pixel_put(&img, x, y, 0x00FF0000);
            x++;
        }
        x = 0;
        y++;
    }
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);
    mlx_loop(mlx);

    mlx_destroy_window(mlx, win);
    free(mlx);
    return (0);
}