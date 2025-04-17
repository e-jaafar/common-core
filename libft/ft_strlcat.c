/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:14:30 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 16:48:39 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Concatenate strings with the same input parameters and output result.
** Designed to be safer.
** LIBC FUNCTION.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	c[9] = "Hello ";
	char	b[] = "zzaa";
	printf("%u\n", ft_strlcat(c, b, 9));
	//printf("%lu\n", strlcat(c, b, 9));
	printf("%s", c);
}*/