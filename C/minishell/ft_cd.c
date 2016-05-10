/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 16:33:45 by bciss             #+#    #+#             */
/*   Updated: 2015/04/10 01:24:10 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_cd_back(void)
{
	int		i;
	int		j;
	char	buf[2048];
	char	buff[2048];

	i = ft_getenvposition("OLDPWD=");
	j = ft_getenvposition("PWD=");
	if (i != -1)
	{
		ft_bzero(buf, 2048);
		ft_bzero(buff, 2048);
		ft_strcat(buf, "cd ");
		ft_strcat(buff, ft_getenv("OLDPWD="));
		ft_strcat(buf, &buff[7]);
		ft_strcat(buf, "\n");
		ft_cd(buf);
	}
}

void		ft_cd_racine(void)
{
	int		i;

	i = ft_getenvposition("HOME");
	if (i == -1)
		return ;
	ft_putendl(&g_env[i][5]);
	chdir(&g_env[i][5]);
}

void		ft_old_pwd(void)
{
	char	buff[2048];

	ft_bzero(buff, 2048);
	ft_strcat(buff, "setenv OLDPWD=");
	ft_strcat(buff, getcwd(buff + 15, 2033));
	ft_strcat(buff, "\n");
	ft_setenv(buff);
}

char		*getpath(char *str)
{
	int i;

	i = 2;
	if (str[i] && str[i] == ' ')
		return (ft_strdup(&str[3]));
	return (str);
}

int			ft_cd(char *str)
{
	int		ret;
	char	**s;
	char	*st;

	if (ft_cd_spe(str))
		return (1);
	else
	{
		ft_old_pwd();
		s = ft_strsplit(str, ' ');
		if (!s[1])
			return (0);
		st = s[1];
		while (*st)
			st++;
		st[-1] = 0;
		ret = chdir(s[1]);
		if (ret == -1)
		{
			ft_putstr_fd("not a valide directory : ", 2);
			ft_putendl_fd(s[1], 2);
		}
		ft_cd_setenv();
	}
	return (1);
}
