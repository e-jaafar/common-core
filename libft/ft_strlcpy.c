/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:15:22 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 16:48:32 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy the string src to dst (including the terminating '\0').
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	c[] = "Hello";
	char	copy[] = "tastGGG";

	printf("ft_strlcpy: %zu\n", ft_strlcpy(copy, c, 4));
	printf("strlcpy: %lu\n", strlcpy(copy, c, 2));
	printf("dest: %s", copy);
}
*/