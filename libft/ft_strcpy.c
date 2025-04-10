/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:12:11 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/10 12:12:31 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	c[] = "Hello";
	char	copy[] = "testGGG";

	printf("ft_strcpy: %s\n", ft_strcpy("testGGG", "Hello"));
	printf("strcpy: %s\n", strcpy(copy, c));
}*/