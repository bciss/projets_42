/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_handleinib.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjensen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:15:43 by gjensen           #+#    #+#             */
/*   Updated: 2016/05/08 22:21:09 by gjensen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

char		*sh_get_env_var(char *find)
{
	int		i;
	char	*var;

	i = 0;
	while (g_env[i])
	{
		var = ft_strdupc(g_env[i], '=');
		if (ft_strequ(find, var))
		{
			ft_strdel(&var);
			return (ft_strchr(g_env[i], '=') + 1);
		}
		ft_strdel(&var);
		i++;
	}
	return (NULL);
}

static int	sh_find_backslashsingle(char *str, char *ret, int *i, int *n)
{
	if (str[*i] == '\\' && str[*i + 1])
	{
		ret[*n] = str[*i + 1];
		(*n)++;
		*i = *i + 2;
		return (1);
	}
	if (str[*i] && str[*i + 1] && str[*i] == '\'')
	{
		(*i)++;
		while (str[*i] != '\'')
		{
			ret[*n] = str[*i];
			(*n)++;
			(*i)++;
		}
		(*i)++;
		return (1);
	}
	return (0);
}

static int	sh_find_double(char *str, char *ret, int *i, int *n)
{
	char	*val;
	char	var[0xFFF];

	val = NULL;
	ft_bzero(var, 0xFFF);
	if (str[*i] && str[*i + 1] && str[*i] == '\"')
	{
		(*i)++;
		while (str[*i] != '\"')
		{
			if (str[*i] == '\\' && str[*i + 1] == '\"')
				i++;
			{
				ret[*n] = str[*i];
				(*n)++;
				(*i)++;
			}
		}
		(*i)++;
		return (1);
	}
	return (0);
}

static void	sh_simple_copy(char *str, char *ret, int *i, int *n)
{
	if (str[*i])
	{
		ret[*n] = str[*i];
		(*i)++;
		(*n)++;
	}
}

char		*sh_treatinib(char *str)
{
	int		i;
	int		n;
	char	ret[0xFFF];
	char	*send;

	ft_bzero(ret, 0xFFF);
	i = 0;
	n = 0;
	while (str[i])
	{
		if (!sh_find_backslashsingle(str, ret, &i, &n))
		{
			if (!sh_find_double(str, ret, &i, &n))
				sh_simple_copy(str, ret, &i, &n);
		}
	}
	ret[n] = 0;
	ft_strdel(&str);
	send = ft_strdup(ret);
	return (send);
}