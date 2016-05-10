/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 14:56:36 by bciss             #+#    #+#             */
/*   Updated: 2015/06/03 18:37:47 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

char	**g_env;

void	sig_handler(int sig)
{
	if (sig == SIGINT)
		ft_putendl_fd("enter 'exit' to quit\n", 2);
}

void	ft_signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGKILL, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

void	ft_do_env(char **envo)
{
	int		i;

	i = 0;
	g_env = (char **)malloc(sizeof(char *) * 2048);
	while (i < 2048)
		g_env[i++] = (char *)malloc(sizeof(char) * 2048);
	i = -1;
	while (envo[++i] && i < 2047)
		ft_strcpy(g_env[i], envo[i]);
	g_env[i] = NULL;
	ft_shlvl();
	ft_cd_setenv();
}

void	ft_main2(char *buf)
{
	char	**tab;
	int		j;

	tab = ft_strsplit(buf, ';');
	j = 0;
	while (tab[j])
	{
		if (tab[j + 1])
			tab[j] = ft_strjoin(tab[j], "\n");
		tab[j] = ft_strsupertrim(tab[j]);
		ft_reading(tab[j]);
		j++;
	}
}

int		main(int ac, char **av, char **envp)
{
	char	buf[1024];
	int		ret;
	char	*prompt;

	ft_signals();
	ft_do_env(envp);
	if (ac == 1 && av)
		while (42)
		{
			if ((prompt = ft_getenv("PWD=")))
			{
				ft_putstr("\033[31;1m");
				ft_putendl(&prompt[4]);
				ft_putendl("\033[0m");
			}
			ft_putstr("$>");
			ft_bzero(buf, sizeof(buf));
			ret = read(0, buf, 1024);
			if (!ret)
				exit(0);
			buf[ret] = '\0';
			ft_main2(buf);
		}
	return (1);
}
