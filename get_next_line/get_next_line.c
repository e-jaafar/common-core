/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:26:39 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/06/20 19:45:17 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_realloc_and_copy(char *original, size_t old_size,
		size_t new_size)
{
	char	*new_ptr;

	new_ptr = (char *)malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (original)
	{
		ft_memcpy(new_ptr, original, old_size);
		free(original);
	}
	return (new_ptr);
}

static char	*ft_read_and_grow(int fd, char *line, t_read_spec *spec)
{
	char	buffer[BUFFER_SIZE];
	char	*temp;

	spec->bytes = read(fd, buffer, BUFFER_SIZE);
	if (spec->bytes <= 0)
		return (line);
	if (spec->len + spec->bytes + 1 > spec->cap)
	{
		spec->cap = (spec->len + spec->bytes) * 2;
		temp = ft_realloc_and_copy(line, spec->len, spec->cap);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		line = temp;
	}
	ft_memcpy(line + spec->len, buffer, spec->bytes);
	spec->len += spec->bytes;
	line[spec->len] = '\0';
	return (line);
}

static char	*finalize_line(char *line, ssize_t bytes_read)
{
	char	*temp;
	size_t	line_len;

	if (bytes_read == -1)
	{
		if (line)
			free(line);
		return (NULL);
	}
	if (!line || !*line)
	{
		if (line)
			free(line);
		return (NULL);
	}
	line_len = ft_strlen(line);
	temp = ft_realloc_and_copy(line, line_len, line_len + 1);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	temp[line_len] = '\0';
	return (temp);
}

char	*ft_get_line(int fd, char *line)
{
	t_read_spec	spec;

	spec.len = 0;
	spec.cap = 0;
	if (line)
	{
		spec.len = ft_strlen(line);
		spec.cap = spec.len;
	}
	spec.bytes = 1;
	while (spec.bytes > 0 && (!line || !ft_strchr(line, '\n')))
	{
		line = ft_read_and_grow(fd, line, &spec);
		if (!line)
			return (NULL);
	}
	return (finalize_line(line, spec.bytes));
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
