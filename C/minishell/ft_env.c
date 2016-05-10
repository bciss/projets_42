/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 21:00:38 by bciss             #+#    #+#             */
/*   Updated: 2015/04/10 01:54:01 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_getenvposition(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	while (g_env[i])
	{
		if (ft_strncmp(str, g_env[i], j) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_getenv(char *str)
{
	int		i;
	int		j;

	j = ft_strlen(str);
	i = 0;
	while (g_env[i])
	{
		if ((ft_strncmp(str, g_env[i], j) == 0))
			return (g_env[i]);
		i++;
	}
	return (NULL);
}

void	ft_unsetenv(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(&str[9]);
	while ((ft_strncmp(&str[9], g_env[i], (j - 1)) != 0) && g_env[i] != NULL)
		i++;
	j = 0;
	if (g_env[i] != NULL)
	{
		while (g_env[i + 1])
		{
			g_env[i] = g_env[i + 1];
			i++;
		}
		g_env[i] = NULL;
	}
}

void	ft_setenv(char *str)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	str[j - 1] = '\0';
	tab = ft_strsplit(str, '=');
	j = ft_strlen(&tab[0][7]);
	while ((ft_strncmp(&tab[0][7], g_env[i], (j)) != 0))
		i++;
	if (i > 2046)
	{
		ft_putendl_fd("environement with too many items", 2);
		return ;
	}
	if (g_env[i] && (ft_strncmp(&tab[0][7], g_env[i], j) == 0))
		ft_strcpy(g_env[i], &str[7]);
	else
	{
		g_env[i] = ft_strdup(&str[7]);
		g_env[i + 1] = NULL;
	}
}

void	ft_cd_setenv(void)
{
	char	buff[2048];

	ft_bzero(buff, 2048);
	ft_strcat(buff, "setenv PWD=");
	ft_strcat(buff, getcwd(buff + 12, 2036));
	ft_strcat(buff, "\n");
	ft_setenv(buff);
}
