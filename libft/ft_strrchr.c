/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:37:51 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/19 15:59:58 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Localise la première occurrence de c dans la chaîne s.
** Le caractère nul de fin de chaîne est considéré comme faisant partie 
** de la chaîne.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

void	main()
{
	char	*s = "bonjour teste";
	char	c = 't';

	printf("%s", ft_strrchr(s, c));
}*/
