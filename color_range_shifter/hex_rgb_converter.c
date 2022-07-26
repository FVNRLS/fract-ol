/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_rgb_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:48:07 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/05 11:53:56 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"

/*
 * Separate colors and combine them back together with bit shifting method.
 * */
int	get_transparency(int trgb)
{
    return ((trgb >> 24) & 0xFF);
}

int	get_red(int trgb)
{
    return ((trgb >> 16) & 0xFF);
}

int	get_green(int trgb)
{
    return ((trgb >> 8) & 0xFF);
}

int	get_blue(int trgb)
{
    return (trgb & 0xFF);
}

int	convert_rgb_to_hex(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}