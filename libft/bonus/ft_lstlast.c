/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:00:37 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 13:02:44 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** return le dernier element d'une list
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
