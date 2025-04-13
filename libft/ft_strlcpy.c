/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:15:22 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/10 12:15:24 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i] != '\0' && i < size - 1 && size > 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	c[] = "Hello";
	char	copy[] = "tastGGG";

	printf("ft_strlcpy: %u\n", ft_strlcpy(copy, c, 4));
	printf("strlcpy: %lu\n", strlcpy(copy, c, 2));
	printf("dest: %s", copy);
}*/