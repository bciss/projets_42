/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tildhome.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 02:11:46 by bciss             #+#    #+#             */
/*   Updated: 2015/04/10 01:54:27 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_tild(char *str)
{
	int		i;
	int		j;
	char	*dup;
	char	**tab;

	i = ft_getenvposition("HOME=");
	if (ft_strchr(str, '~') && (i != -1))
	{
		j = 0;
		tab = ft_strsplit(str, '~');
		dup = ft_strdup(tab[j]);
		while (tab[j + 1])
		{
			dup = ft_strjoin(dup, &g_env[i][5]);
			j++;
		}
		dup = ft_strjoin(dup, tab[j]);
		return (dup);
	}
	return (str);
}

int		ft_cd_spe(char *str)
{
	if ((ft_strlen(str) == 3))
	{
		ft_cd_racine();
		ft_cd_setenv();
		return (1);
	}
	else if ((ft_strcmp(str, "cd -\n") == 0))
	{
		ft_cd_back();
		ft_cd_setenv();
		return (1);
	}
	else
		return (0);
}

void	ft_exec(char *path, char *d_name, char **av2)
{
	char	buff[2048];

	ft_bzero(buff, 2048);
	ft_strcpy(buff, path);
	ft_strcat(buff, "/");
	ft_strcat(buff, d_name);
	ft_execution(buff, av2);
}

char	**ft_n_out_access(char *str, int *o)
{
	int		j;
	int		i;
	char	**av2;

	i = 0;
	j = 0;
	av2 = ft_strsplit(str, ' ');
	while (av2[j + 1])
		j++;
	if (av2[j])
		while (av2[j][i])
		{
			if (av2[j][i] == '\n')
				av2[j][i] = '\0';
			i++;
		}
	*o = 0;
	if (access(av2[0], X_OK) != -1)
	{
		ft_execution(av2[0], av2);
		*o = 1;
	}
	return (av2);
}
