/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:37:44 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 16:49:14 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Localise la première occurrence de la chaîne needle dans la chaîne haystack,
** où pas plus de len caractères sont recherchés.
** Les caractères apparaissant après un caractère `\0` ne sont pas recherchés.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)haystack);
	if (!len)
		return (NULL);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j]
			&& (i + j) < len)
		{
			j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>

void	main()
{
	char *texte = "Ceci est une chaîne de test";
	char *mot = "chaîne";
	
	printf("Mot trouvé : %s", ft_strnstr(texte, mot, 50));
}*/
