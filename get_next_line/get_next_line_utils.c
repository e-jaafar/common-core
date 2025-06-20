/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:27:53 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/06/20 19:50:30 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

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
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*new_line(char *line)
{
	int		i;
	char	*str;
	size_t	remainder_len;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || !line[i + 1])
	{
		free(line);
		return (NULL);
	}
	remainder_len = ft_strlen(line + i + 1);
	str = (char *)malloc(sizeof(char) * (remainder_len + 1));
	if (!str)
	{
		free(line);
		return (NULL);
	}
	ft_memcpy(str, line + i + 1, remainder_len);
	str[remainder_len] = '\0';
	free(line);
	return (str);
}

char	*ft_get_next_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!line || !line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = line[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
