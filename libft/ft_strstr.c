/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:38:31 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/15 20:03:52 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (s2 == NULL || ft_strlen(s2) == 0)
		return ((char *)s1);
	while (i < ft_strlen(s1))
	{
		if (ft_strncmp((char *)&s1[i], s2, ft_strlen(s2)) == 0)
			return ((result = (char *)&s1[i]));
		i++;
	}
	return (NULL);
}
