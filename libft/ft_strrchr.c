/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:37:51 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 17:50:56 by jael-m-r         ###   ########.fr       */
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
	int	len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[len]);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
