/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:26:39 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/06/20 19:08:44 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static void	*ft_memcpy(void *dest, const void *src, size_t n)
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

static char	*ft_realloc_and_copy(char *original, size_t old_size,
		size_t new_size)
{
	char	*new_ptr;

	new_ptr = (char *)malloc(new_size);
	if (!new_ptr)
	{
		if (original)
			free(original);
		return (NULL);
	}
	if (original)
	{
		ft_memcpy(new_ptr, original, old_size);
		free(original);
	}
	return (new_ptr);
}

char	*ft_get_line(int fd, char *line)
{
	char		buffer[BUFFER_SIZE];
	ssize_t		bytes_read;
	size_t		line_len;
	size_t		buffer_cap;

	line_len = 0;
	buffer_cap = 0;
	if (line)
	{
		line_len = ft_strlen(line);
		buffer_cap = line_len;
	}
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		if (line_len + bytes_read > buffer_cap)
		{
			buffer_cap = (line_len + bytes_read) * 2;
			line = ft_realloc_and_copy(line, line_len, buffer_cap);
			if (!line)
				return (NULL);
		}
		ft_memcpy(line + line_len, buffer, bytes_read);
		line_len += bytes_read;
	}
	if (bytes_read == -1 || (bytes_read == 0 && line_len == 0))
	{
		if (line)
			free(line);
		return (NULL);
	}
	if (line_len > 0)
	{
		line = ft_realloc_and_copy(line, line_len, line_len + 1);
		if (!line)
			return (NULL);
		line[line_len] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line_storage[1024];
	char		*next_line_to_return;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	line_storage[fd] = ft_get_line(fd, line_storage[fd]);
	if (!line_storage[fd])
		return (NULL);
	next_line_to_return = ft_get_next_line(line_storage[fd]);
	if (!next_line_to_return)
	{
		free(line_storage[fd]);
		line_storage[fd] = NULL;
		return (NULL);
	}
	line_storage[fd] = new_line(line_storage[fd]);
	return (next_line_to_return);
}
