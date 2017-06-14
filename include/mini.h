/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:35:00 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/01 13:47:02 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "libft.h"
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <sys/xattr.h>
# include <signal.h>

typedef struct	s_glob
{
	char		**env;
	char		**tab;
	char		*tmp;
}				t_glob;

typedef struct	s_main
{
	char		str[5000];
	pid_t		id;
	int			i;
	int			j;
	char		*tmp;
	char		**tab;
}				t_main;

pid_t			g_id;
int				agre(t_main *m);
int				ft_redirect(t_main *m, t_glob *g, char **env);
int				ft_null(char *str);
int				main3(t_main *m, t_glob *g);
int				ft_do_it(t_main *m, t_glob *g);
int				ft_slah(char *str, char **env);
char			**ft_strsplit_tab(char const *s, char c);
void			ft_dev(char *str, pid_t id, t_glob *g, char **env);
void			ft_libre(char **tab);
char			**ft_strsplit2(char*s, char c);
void			ft_set_env(char *str, t_glob *g);
int				ft_strlen_tab(char **tab);
void			ft_unset_env(char *str, t_glob *g);
int				ft_env(char *str, t_glob *g);
int				ft_echo(char *str, t_glob *g);
int				ft_cd(char *str, t_glob *g);
int				ft_check(t_glob *g, char *str);
int				isex(char *str);
void			ft_pronpt(void);
int				ft_isdir(char *str);
int				ft_strlen_tab(char **tab);
void			ft_libre(char **tab);
int				isex(char *str);
int				ft_no(char *str, t_glob *g);
int				setup_env(char ***env, t_glob *g);
void			ft_cd_tild(char ***tab);

#endif
