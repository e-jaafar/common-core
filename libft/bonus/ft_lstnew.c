/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:00:43 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 13:03:15 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Alloue et retourne un nouvel élément
** La variable 'content' est initialisée avec la valeur de 'content'.
** La variable 'next' est initialisée à NULL.
*/

t_list	*ft_lstnew(void const *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		return (NULL);
	}
	new->content = (void *)content;
	new->next = NULL;
	return (new);
}
