/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:08:57 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 13:10:32 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts the initial portion of the string to its int representation.
*/

int	ft_atoi(const char *str)
{
	long	i;
	long	max;
	long	sign;
	long	result;

	i = 0;
	max = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (max >= 1)
			return (0);
		if (str[i] == '-')
			sign = -sign;
		max++;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return ((int)result * sign);
}
