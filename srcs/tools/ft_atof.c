/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:01:20 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/27 16:08:39 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static int	count_digits(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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
	len = count_digits(str);
	while (len--)
		double_val /= 10;
	if ((int_val + int_val) > 0)
		return (double_val);
	else
		return (-double_val);
}
