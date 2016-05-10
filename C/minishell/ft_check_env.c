/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 19:42:01 by bciss             #+#    #+#             */
/*   Updated: 2015/04/09 19:52:02 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_env(char **env)
{
	int		i;

	i = 0;
	if (!env[i])
	{
		ft_putendl_fd("environnement non valide\nnice try XD", 2);
		return (0);
	}
	return (1);
}

void	ft_shlvl(void)
{
	int		i;
	int		j;
	char	**tab;
	char	str[2048];

	i = ft_getenvposition("SHLVL");
	if (i >= 0)
	{
		ft_bzero(str, 2048);
		tab = ft_strsplit(g_env[i], '=');
		j = ft_atoi(tab[1]);
		j++;
		ft_strcpy(str, "setenv SHLVL=");
		ft_strcat(str, ft_itoa(j));
		ft_strcat(str, "\n");
		ft_setenv(str);
	}
}
