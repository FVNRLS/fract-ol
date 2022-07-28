/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:12:46 by rmazurit          #+#    #+#             */
/*   Updated: 2022/07/28 11:24:11 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Mimics the function strcmp(const char *str1, const char *str2)
This function return values that are as follows −
1) if Return value < 0, then it indicates str1 is less than str2.
2) if Return value > 0, then it indicates str2 is less than str1.
3) if Return value = 0, then it indicates str1 is equal to str2.
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
