/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:01:20 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/23 14:19:37 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_atof(const char *s)
{
    char	*str;
    double	int_val;
    double	double_val;
    int		len;

    str = (char *)s;
    int_val = (double)ft_atoi(str);
    while (*str && *str != '.')
        str++;
    if (*str == '.')
        str++;
    double_val = (double)ft_atoi(str);
    len = ft_strlen(str);
    while (len--)
        double_val /= 10;
    if ((int_val + int_val) > 0)
        return (double_val);
    else
        return (-double_val);
}