/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:50:58 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 12:56:41 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la chaîne de caractères 's' sur le descripteur de fichier donné.
*/

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || !s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
