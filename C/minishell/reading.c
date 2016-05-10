/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 15:53:01 by bciss             #+#    #+#             */
/*   Updated: 2015/04/10 00:22:18 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"
#include <dirent.h>

void	ft_execution(char *com, char **tab)
{
	pid_t	father;

	if ((father = fork() > 0))
		wait(NULL);
	if (father == 0)
		execve(com, tab, g_env);
}

void	ft_print_tab(void)
{
	int		i;

	i = 0;
	while (g_env[i])
		ft_putendl(g_env[i++]);
}

int		ft_check_path(char *str)
{
	char			**path;
	struct dirent	*d;
	DIR				*dir;
	char			**av2;
	int				o;

	av2 = ft_n_out_access(str, &o);
	if (o == 1)
		return (1);
	o = ft_getenvposition("PATH");
	if (o == -1)
		return (0);
	path = ft_strsplit(g_env[o] + 5, ':');
	while (*path && path++)
		if ((dir = opendir(*path)))
		{
			while ((d = readdir(dir)))
				if (CHECK)
				{
					ft_exec(*path, d->d_name, av2);
					return (1);
				}
			closedir(dir);
		}
	return (0);
}

void	ft_reading(char *str)
{
	str = ft_tild(str);
	if ((ft_strchr(str, '\n') != NULL) && (str[0] != '\n'))
	{
		if ((ft_strcmp("exit\n", str) == 0))
			exit(1);
		else if ((ft_strncmp("setenv\n", str, 6) == 0))
			ft_setenv(str);
		else if ((ft_strncmp("unsetenv\n", str, 8) == 0))
			ft_unsetenv(str);
		else if ((ft_strcmp("env\n", str) == 0))
			ft_print_tab();
		else if ((ft_strncmp("cd\n", str, 2)) == 0 && (ft_cd(str)))
			(void)str;
		else if (ft_check_path(str))
			(void)str;
		else
		{
			ft_putstr_fd("command not found : ", 2);
			ft_putendl_fd(str, 2);
		}
	}
}
