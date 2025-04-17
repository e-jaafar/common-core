/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-m-r <jael-m-r@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:00:20 by jael-m-r          #+#    #+#             */
/*   Updated: 2025/04/16 13:01:05 by jael-m-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Adds the element new at the beginning of the list.
** NON STANDARD FUNCTION.
*/

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	if (*alst)
		new->next = *alst;
	*alst = new;
}
