/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 20:35:19 by bciss             #+#    #+#             */
/*   Updated: 2015/10/05 22:24:10 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*later;

	tmp = *alst;
	while (tmp)
	{
		later = (tmp)->next;
		(*del)((tmp)->content, (tmp)->content_size);
		tmp = later;
	}
	free(*alst);
}
