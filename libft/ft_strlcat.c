/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:14:30 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/10 12:57:03 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (i + j);
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