/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bciss <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 20:27:53 by bciss             #+#    #+#             */
/*   Updated: 2015/04/10 00:25:51 by bciss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "libft/libft.h"

# define K && ft_strcmp(d->d_name, "..")
# define CHECK !ft_strcmp(d->d_name, av2[0]) && ft_strcmp(d->d_name, ".") K

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

extern char		**g_env;

t_env				*ft_init_env(char **envp);
void				ft_print_data(t_env *elem);
t_env				*ft_push_back(t_env **begin_list, char *name);
char				**ft_strsplit(char const *s, char c);
int					ft_cd(char *str);
void				ft_setenv(char *str);
char				*ft_getenv(char *str);
void				ft_cd_setenv(void);
int					ft_getenvposition(char *str);
char				*ft_strcat(char *s1, const char *s2);
void				ft_reading(char *str);
void				ft_unsetenv(char *str);
void				ft_print_tab();
int					ft_check_env(char **env);
void				ft_shlvl(void);
void				ft_old_pwd(void);
char				*ft_tild(char *str);
int					ft_cd_spe(char *str);
void				ft_cd_racine(void);
void				ft_cd_back(void);
void				ft_exec(char *path, char *d_name, char **av2);
void				ft_execution(char *com, char **tab);
char				**ft_n_out_access(char *str, int *o);

#endif
