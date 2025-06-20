/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:27:06 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/06/20 19:45:19 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_read_spec
{
	size_t	len;
	size_t	cap;
	ssize_t	bytes;
}	t_read_spec;

char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*new_line(char *line);
char	*ft_get_line(int fd, char *line);
char	*ft_get_next_line(char *line);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif