/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:00:32 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 13:02:23 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Parcourt la liste 'lst' et applique 'f' au contenu de chaque élément.
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f || !lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
