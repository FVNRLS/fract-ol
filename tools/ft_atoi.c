/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:01:52 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/23 14:03:13 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_atoi(const char *str)
{
    int	i;
    int	sign;
    int	res;

    i = 0;
    sign = 1;
    res = 0;
    while (str[i] == '\r' || str[i] == '\t' || str[i] == ' '
           || str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
        i++;
    if (str[i] == '-')
    {
        sign *= (-1);
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] <= '9' && str[i] >= '0')
    {
        res = (str[i] - '0') + (res * 10);
        i++;
    }
    return (res * sign);
}
