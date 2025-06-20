/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:26:39 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/06/20 18:32:03 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*local_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

static ssize_t	append_from_read(int fd, char **tmp_line, char *buffer)
{
	ssize_t	read_bytes;
	char	*new_tmp_line;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
		return (read_bytes);
	buffer[read_bytes] = '\0';
	new_tmp_line = local_strjoin(*tmp_line, buffer);
	if (!new_tmp_line)
	{
		if (*tmp_line)
			free(*tmp_line);
		*tmp_line = NULL;
		return (-1);
	}
	if (*tmp_line && *tmp_line != new_tmp_line)
		free(*tmp_line);
	*tmp_line = new_tmp_line;
	return (read_bytes);
}

static int	ft_get_line_read(int fd, char **tmp_line)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	read_bytes = 1;
	while (!ft_strchr(*tmp_line, '\n') && read_bytes > 0)
	{
		read_bytes = append_from_read(fd, tmp_line, buffer);
		if (read_bytes == -1)
		{
			free(buffer);
			return (-1);
		}
	}
	free(buffer);
	return (read_bytes);
}

char	*ft_get_line(int fd, char *line)
{
	char	*tmp_line;
	int		read_bytes;

	tmp_line = line;
	read_bytes = ft_get_line_read(fd, &tmp_line);
	if (read_bytes == -1)
	{
		if (tmp_line)
			free(tmp_line);
		return (NULL);
	}
	if (read_bytes == 0 && (!tmp_line || *tmp_line == '\0'))
	{
		if (tmp_line)
			free(tmp_line);
		return (NULL);
	}
	return (tmp_line);
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
