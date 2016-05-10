/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 23:11:32 by bciss             #+#    #+#             */
/*   Updated: 2014/12/31 16:09:49 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	if (lst && f)
	{
		if (!(tmp = malloc(sizeof(t_list))))
			return (NULL);
		tmp = (*f)(lst);
		tmp->next = (NULL);
		lst = lst->next;
		while (lst)
		{
			if (!(tmp = malloc(sizeof(t_list))))
				return (NULL);
			tmp = (*f)(lst);
			tmp->next = NULL;
			lst = lst->next;
		}
		return (tmp);
	}
	return (lst);
}
