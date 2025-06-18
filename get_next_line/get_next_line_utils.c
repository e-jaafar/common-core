/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:27:53 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/06/19 00:44:54 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_alloc_empty(void)
{
	char	*empty;

	empty = (char *)malloc(1 * sizeof(char));
	if (!empty)
		return (NULL);
	empty[0] = '\0';
	return (empty);
}

char	*ft_strjoin(char *s1, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*s1_alias;
	size_t	s1_len;

	if (!buff)
		return (NULL);
	s1_alias = s1;
	if (!s1_alias)
		s1_alias = ft_strjoin_alloc_empty();
	if (!s1_alias)
		return (NULL);
	s1_len = ft_strlen(s1_alias);
	str = (char *)malloc(sizeof(char) * (s1_len + ft_strlen(buff) + 1));
	if (!str)
	{
		if (!s1)
			free(s1_alias);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1_alias[i])
	{
		str[i] = s1_alias[i];
		i++;
	}
	while (buff[j])
		str[i++] = buff[j++];
	str[i] = '\0';
	if (!s1)
		free(s1_alias);
	return (str);
}
