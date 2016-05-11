/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaviot <vdaviot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 17:18:54 by vdaviot           #+#    #+#             */
/*   Updated: 2016/05/11 02:26:22 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		ft_strlen_term(char *cmd, int width)
{
	int len;
	int i;

	len = PROMPT_LEN;
	i = 0;
	while (cmd && cmd[i])
	{
		if (ft_isprint(cmd[i]))
			++len;
		else if (cmd[i] == '\n')
			len += (width - (len % width));
		i++;
	}
	return (len);
}

int		ft_strlen_cur(char *cmd, int x, int cursor)
{
	int	len;
	int	i;

	len = PROMPT_LEN;
	i = 0;
	while (cmd && cmd[i] && i < cursor)
	{
		if (ft_isprint(cmd[i]))
			++len;
		else if (cmd[i] == '\n')
			len += (x - (len % x));
		i++;
	}
	return (len);
}

void	ft_putstr_cursor(char *str, int cursor)
{
	int			len;
	int			x;
	int			y;
	int			width;

	minimal_prompt();
	ft_putstr(str);
	width = get_col_term();
	len = ft_strlen(str);
	if (cursor > len)
		cursor = len;
	len = ft_strlen_term(str, width);
	len -= ft_strlen_cur(str, width, cursor);
	x = len % width;
	y = len / width;
	while (y-- > 0)
		tputs(tgetstr("up", NULL), 1, t_puts);
	while (x-- > 0)
		tputs(tgetstr("le", NULL), 1, t_puts);
	while (++x < 0)
		tputs(tgetstr("nd", NULL), 1, t_puts);
	tputs(tgetstr("ve", NULL), 1, t_puts);
}

void	remove_excess_line(char *file)
{
	int				fd;
	int				i;
	int				ret;
	char			tmp[0xf0000];
	char			buf[0xf0000];

	i = 0;
	if ((fd = open(file, O_RDONLY | O_CREAT, 0666)) == -1)
		ft_exit("Open error1");
	if ((ret = read(fd, buf, 0xf0000)) < 0)
		ft_exit("Read error");
	buf[ret] = '\0';
	while (buf[++i] != '[')
		;
	ft_strcpy(tmp, buf);
	ft_strcatf(buf, tmp, i - 1);
	close(fd);
	if (!(fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0666)))
		ft_exit("Open error2");
	write(fd, buf, ft_strlen(buf));
	close(fd);
}

int		count_lines_file(char *file)
{
	int				fd;
	int				i;
	int				ret;
	char			tmp[0xf0000];

	i = -1;
	if ((fd = open(file, O_RDONLY | O_CREAT, 0666)) == -1)
		ft_exit("Open error1");
	if ((ret = read(fd, tmp, 0xf0000)) < 0)
		ft_exit("Read error");
	tmp[ret] = '\0';
	ret = 0;
	while (tmp[++i])
		if (tmp[i] == '[')
			ret++;
	close(fd);
	return (ret);
}
