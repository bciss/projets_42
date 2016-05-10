/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 21:02:15 by bciss             #+#    #+#             */
/*   Updated: 2015/01/21 19:23:13 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "libft/libft.h"

void	ft_print_data(t_point *elem)
{
	if (elem)
	{
		while (elem->next)
		{
			ft_putstr("x = ");
			ft_putnbr(elem->x);
			ft_putstr("\ty = ");
			ft_putnbr(elem->y);
			ft_putstr("\tz = ");
			ft_putnbr(elem->z);
			ft_putchar('\n');
			elem = elem->next;
		}
		ft_putstr("x = ");
		ft_putnbr(elem->x);
		ft_putstr("\ty = ");
		ft_putnbr(elem->y);
		ft_putstr("\tz = ");
		ft_putnbr(elem->z);
		ft_putchar('\n');
	}
}

t_point	*ft_create_elem(int x, int y, int z)
{
	t_point	*tmp;

	if (!(tmp = malloc(sizeof(t_point))))
		return (NULL);
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	tmp->next = (NULL);
	return (tmp);
}

t_point	*ft_p_push_back(t_point **begin_list, int x, int y, int z)
{
	t_point	*tmp;

	tmp = *begin_list;
	if (begin_list && *begin_list && tmp)
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (tmp)
			tmp->next = ft_create_elem(x, y, z);
		return (tmp);
	}
	return (ft_create_elem(x, y, z));
}

t_point	*ft_point_at(t_point *l, unsigned int n)
{
	t_point	*tmp;

	if (l)
	{
		tmp = l;
		n += 1;
		while ((n > 1) && tmp->next)
		{
			tmp = tmp->next;
			n--;
		}
		return (tmp);
	}
	return (NULL);
}
