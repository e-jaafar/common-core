/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:26:39 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/06/19 00:44:54 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_get_line_read(int fd, char **tmp_line)
{
	char	*buffer;
	ssize_t	read_bytes;
	char	*new_tmp_line;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	read_bytes = 1;
	while (!ft_strchr(*tmp_line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (-1);
		}
		if (read_bytes == 0)
			break;
		buffer[read_bytes] = '\0';
		new_tmp_line = ft_strjoin(*tmp_line, buffer);
		if (!new_tmp_line)
		{
			free(buffer);
			return (-1);
		}
		if (*tmp_line && *tmp_line != new_tmp_line)
			free(*tmp_line);
		*tmp_line = new_tmp_line;
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
		if (tmp_line != line && tmp_line != NULL)
			free(tmp_line);
		return (NULL);
	}
	if (read_bytes == 0 && (!tmp_line || *tmp_line == '\0'))
	{
		if (tmp_line != NULL && tmp_line != line)
			free(tmp_line);
		if (tmp_line == NULL || (tmp_line != line && *tmp_line == '\0'))
			return (NULL);
	}
	return (tmp_line);
}

char	*new_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!line) // Sécurité
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	// Si pas de '\n' (line[i] == '\0') ou si '\n' est le dernier caractère (line[i+1] == '\0')
	if (!line[i] || !line[i + 1])
	{
		free(line);
		return (NULL);
	}
	// La nouvelle chaîne commence après le '\n' (à line[i+1])
	// Longueur de la chaîne restante = ft_strlen(line + i + 1)
	// Allocation = longueur restante + 1 (pour le '\0')
	str = (char *)malloc(sizeof(char) * (ft_strlen(line + i + 1) + 1));
	if (!str)
	{
		free(line); // Libérer l'ancienne ligne en cas d'échec d'allocation
		return (NULL);
	}
	i++; // Se déplacer après le '\n'
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line); // Libérer l\'ancienne ligne complète
	return (str); // Retourner la nouvelle chaîne (ce qui reste après le premier '\n')
}

char	*ft_get_next_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line || !line[i]) // Ajout de la vérification !line et !line[i] (pour ligne vide)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	// Si line[i] est '\n', on inclut le '\n'. Allocation: i (caractères avant \n) + 1 (\n) + 1 (\0) = i + 2
	// Si line[i] est '\0', on n\'inclut pas de '\n'. Allocation: i (caractères) + 1 (\0) = i + 1
	if (line[i] == '\n')
		str = (char *)malloc(sizeof(char) * (i + 2));
	else
		str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL); // L'appelant gère 'line'
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line_storage[1024];
	char		*next_line_to_return;
	char		*data_from_ft_get_line;
	char		*previous_line_storage_val;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);

	previous_line_storage_val = line_storage[fd];
	data_from_ft_get_line = ft_get_line(fd, previous_line_storage_val);

	if (data_from_ft_get_line == NULL)
	{
		if (previous_line_storage_val != NULL)
		{
			free(previous_line_storage_val);
			line_storage[fd] = NULL;
		}
		return (NULL);
	}

	if (data_from_ft_get_line != previous_line_storage_val && previous_line_storage_val != NULL)
	{
		free(previous_line_storage_val);
	}
	line_storage[fd] = data_from_ft_get_line;

	if (line_storage[fd] == NULL || *(line_storage[fd]) == '\0')
	{
		if (line_storage[fd] != NULL)
		{
			free(line_storage[fd]);
			line_storage[fd] = NULL;
		}
		return (NULL);
	}

	next_line_to_return = ft_get_next_line(line_storage[fd]);
	if (!next_line_to_return)
	{
		if (line_storage[fd] != NULL)
		{
			free(line_storage[fd]);
			line_storage[fd] = NULL;
		}
		return (NULL);
	}

	line_storage[fd] = new_line(line_storage[fd]);
	return (next_line_to_return);
}