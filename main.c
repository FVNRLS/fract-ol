/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:16:10 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/29 13:14:25 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int main(void)
{
    void	*mlx_ptr;
    void	*win_ptr;
    // bool	game_is_on;

    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (1);
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
    if (win_ptr == NULL)
    {
        free(win_ptr);
        return (1);
    }
    while (1)
        ;
//    mlx_destroy_window(mlx_ptr, win_ptr);
//    free(mlx_ptr);
    return (0);
}