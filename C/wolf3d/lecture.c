/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 16:10:42 by bciss             #+#    #+#             */
/*   Updated: 2015/01/20 18:29:15 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init(t_var **var)
{
	*var = malloc(sizeof(t_var));
	(*var)->tmp = NULL;
	(*var)->lol = NULL;
}

t_point	*ft_scan(char *str, int *nbr)
{
	char	buf[BUF_SIZE + 1];
	t_point	*p;
	t_var	*var;

	ft_init(&var);
	var->x = 0;
	var->y = 0;
	var->i = 0;
	var->fd = open(str, O_RDONLY);
	if (var->fd == -1)
		return (NULL);
	var->tmp = ft_strnew(1);
	p = ft_create_elem(0, 0, 0);
	while ((var->ret = read(var->fd, buf, BUF_SIZE)))
	{
		var->i += var->ret + 1;
		buf[var->ret + 1] = '\0';
		var->tmp = ft_strjoin(var->tmp, buf);
	}
	var->fd = 0;
	return (ft_scan2(var, nbr, &p));
}

t_point	*ft_scan2(t_var *var, int *nbr, t_point **p)
{
	t_point	*begin;

	begin = *p;
	while (var->tmp[var->fd] != '\0')
	{
		if (var->tmp[var->fd] != ' ')
		{
			if (ft_scan3(var, p) == 0)
				break ;
		}
		*nbr = var->x;
		if (var->tmp[var->fd] == '\n')
		{
			var->y++;
			var->x = 0;
		}
		var->fd++;
	}
	return (begin);
}

int		ft_scan3(t_var *var, t_point **p)
{
	var->j = var->fd;
	while (var->tmp[var->j] != ' ' && var->tmp[var->j] != '\n')
	{
		if (var->j == var->i)
			return (0);
		var->j++;
	}
	if (var->j == var->i)
		return (0);
	var->lol = ft_strsub(var->tmp, var->fd, var->j);
	*p = ft_p_push_back(p, var->x, var->y, (ft_atoi(var->lol)));
	var->x++;
	var->fd = var->j;
	return (1);
}
