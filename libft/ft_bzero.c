/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:26:49 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/10 12:51:33 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		s[i++] = '\0';
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello";

	ft_bzero(str, 5);
	printf("%s", str);
}*/
