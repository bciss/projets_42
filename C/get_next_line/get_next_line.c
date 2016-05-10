/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 14:35:50 by bciss             #+#    #+#             */
/*   Updated: 2015/02/10 01:00:35 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cton(char *str, char **line)
{
	int		i;
	char	*lol;

	if (*str && str)
	{
		i = 0;
		lol = ft_strdup(str);
		while (lol[i] != '\0' && lol[i] != '\n')
			i++;
		*line = ft_strsub(lol, 0, i);
		lol = &lol[i + 1];
		return (lol);
	}
	return (NULL);
}

int		ft_chrn(char **str, char **line)
{
	int		i;
	char	*lol;

	if (*str && str)
	{
		lol = ft_strdup(*str);
		i = 0;
		while (lol[i] != '\0')
		{
			if (lol[i] == '\n')
			{
				*str = ft_cton(lol, line);
				return (1);
			}
			i++;
		}
		return (0);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUF_SIZE + 1];
	static char		*str[256];

	if (!line || fd < 0)
		return (-1);
	if (ft_chrn(&str[fd], line) == 1)
		return (1);
	ret = 1;
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
		if (ft_chrn(&str[fd], line) == 1)
			return (1);
	}
	if (ret != -1 && strlen(str[fd]))
	{
		str[fd] = ft_cton(str[fd], line);
		return (1);
	}
	*line = NULL;
	return (ret);
}
