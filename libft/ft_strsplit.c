/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:38:29 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 16:30:28 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Alloue et retourne un tableau de chaînes de caractères fraîches.
** En divisant s en utilisant le caractère c comme délimiteur.
** FONCTION NON STANDARD.
*/

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*custo_strdrup(char const *s, char c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static void	ft_process_split(char **result, char *tmp, int i[3])
{
	while (i[0] < i[2])
	{
		if (!tmp[i[0]])
			i[0]++;
		else
		{
			result[i[1]] = ft_strdup(&tmp[i[0]]);
			i[1]++;
			i[0] += ft_strlen(&tmp[i[0]]);
		}
	}
	result[i[1]] = NULL;
}

char	**ft_strsplit(char const *s, char c)
{
	char	**result;
	char	*tmp;
	int		i[3];

	if (s == NULL)
		return (NULL);
	tmp = ft_strdup(s);
	i[2] = ft_strlen(s);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	ft_process_split(result, tmp, i);
	return (result);
}
