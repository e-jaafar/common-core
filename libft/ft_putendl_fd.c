/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:46:00 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 12:49:10 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche la chaîne de caractères 's' sur le descripteur de fichier donné,
** suivie d'un saut de ligne.
*/

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
