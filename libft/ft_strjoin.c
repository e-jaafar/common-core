/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:37:13 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 13:10:01 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une nouvelle chaîne de caractères.
** Qui est le résultat de la concaténation de 's1' et 's2'.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*single;
	int		i;
	int		j;
	int		total_length;

	if (!s1 || !s2)
		return (NULL);
	total_length = ft_strlen(s1) + ft_strlen(s2);
	single = (char *)malloc(sizeof(char) * (total_length + 1));
	if (!single)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		single[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		single[i + j] = s2[j];
		j++;
	}
	single[i + j] = '\0';
	return (single);
}
