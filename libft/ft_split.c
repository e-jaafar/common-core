/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 23:36:29 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/17 13:28:45 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static size_t	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static char	*get_next_word(char const *s, char c, size_t *pos)
{
	char	*word;
	size_t	len;
	size_t	i;

	while (s[*pos] == c)
		(*pos)++;
	len = 0;
	while (s[*pos + len] && s[*pos + len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[*pos + i];
		i++;
	}
	word[i] = '\0';
	*pos += len;
	return (word);
}

static char	**create_array(char const *s, char c, size_t words)
{
	char	**tab;
	size_t	i;
	size_t	pos;

	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < words)
	{
		tab[i] = get_next_word(s, c, &pos);
		if (!tab[i])
		{
			free_split(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	return (create_array(s, c, words));
}
