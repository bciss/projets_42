/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfta.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/17 22:10:38 by bciss             #+#    #+#             */
/*   Updated: 2015/06/11 01:07:42 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTA_H
# define LIBFTA_H

int		ft_puts(char *str);
int		ft_strlen(char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalnum(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
char	*ft_strdup(char *str);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memcpy(void *str, const void *str2, size_t n);
char	*ft_strcat(char *str, char *str2);
void	ft_cat(int fd);
char	*ft_strncat(char *s, char *s2, size_t n);
char	*ft_memalloc(size_t n);

#endif
