/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:00:40 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/19 15:29:09 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	process_node(t_list **new_list, t_list *lst,
			void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*new_node;

	content = f(lst->content);
	if (!content)
	{
		ft_lstclear(new_list, del);
		return (0);
	}
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		del(content);
		ft_lstclear(new_list, del);
		return (0);
	}
	ft_lstadd_back(new_list, new_node);
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		if (!process_node(&new_list, lst, f, del))
			return (NULL);
		lst = lst->next;
	}
	return (new_list);
}
