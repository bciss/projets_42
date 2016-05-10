/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 17:34:18 by bciss             #+#    #+#             */
/*   Updated: 2014/11/20 13:55:27 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*yo;

	tmp = ft_memalloc((sizeof(*lst)));
	tmp = lst;
	if (lst && f)
	{
		while (lst->next)
		{
			yo = (*f)(lst);
			yo = (yo)->next;
		}
	}
	return (tmp);
}
