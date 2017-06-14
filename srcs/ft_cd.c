/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:28:55 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/08 15:45:22 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_cd_moin(t_glob *g, int i)
{
	char *old_pwd;
	char *tmp;
	char test[5000];

	if (g->env[i] == NULL)
	{
		ft_set_env("setenv OLDPWD /", g);
		ft_set_env("setenv PWD /", g);
		chdir("/");
	}
	else
	{
		free(g->env[i]);
		old_pwd = ft_strsub(g->env[i], 7, ft_strlen(g->env[i]));
		g->env[i] = ft_strjoin("OLDPWD=", getcwd(test, 4999));
		chdir(old_pwd);
		tmp = ft_strjoin("setenv PWD ", old_pwd);
		ft_set_env(tmp, g);
		free(tmp);
		free(old_pwd);
	}
}

void	ft_cd_ok(t_glob *g, int i, char **tab)
{
	char *tmp;
	char test[5000];

	if (g->env[i] == NULL)
	{
		ft_set_env("setenv OLDPWD /", g);
		chdir(tab[1]);
		tmp = ft_strjoin("setenv PWD ", getcwd(test, 4999));
		ft_set_env(tmp, g);
		free(tmp);
	}
	else
	{
		free(g->env[i]);
		g->env[i] = ft_strjoin("OLDPWD=", getcwd(test, 4999));
		chdir(tab[1]);
		tmp = ft_strjoin("setenv PWD ", getcwd(test, 4999));
		ft_set_env(tmp, g);
		free(tmp);
	}
}

void	ft_cd_null(t_glob *g, int i)
{
	char test[5000];

	if (g->env[i] == NULL)
	{
		ft_set_env("setenv OLDPWD /", g);
		chdir("/Users/mpinson");
		ft_set_env("setenv PWD /Users/mpinson", g);
	}
	else
	{
		free(g->env[i]);
		g->env[i] = ft_strjoin("OLDPWD=", getcwd(test, 4999));
		chdir("/Users/mpinson");
		ft_set_env("setenv PWD /Users/mpinson", g);
	}
}

int		ft_chr(char **tab)
{
	DIR *rep;

	if (tab[1] && ft_strncmp(tab[1], "-", 1) != 0 && !(rep = opendir(tab[1])))
	{
		ft_putendl("cd: no such file or directory");
		ft_libre(tab);
		return (1);
	}
	if (tab[1] && ft_strncmp(tab[1], "-", 1) != 0)
		closedir(rep);
	return (0);
}

int		ft_cd(char *str, t_glob *g)
{
	int		i;
	char	**tab;

	i = 0;
	if (ft_strncmp("cd", str, 2) == 0)
	{
		tab = ft_strsplit(str, ' ');
		if (tab[1] && tab[1][0] == '~')
			ft_cd_tild(&tab);
		if (ft_chr(tab) == 1)
			return (1);
		ft_set_env("setenv HOME /Users/mpinson", g);
		while (g->env[i] != NULL && ft_strncmp(g->env[i], "OLDPWD=", 7) != 0)
			i++;
		if (tab[1] == NULL)
			ft_cd_null(g, i);
		else if (ft_strncmp(tab[1], "-", 1) == 0)
			ft_cd_moin(g, i);
		else
			ft_cd_ok(g, i, tab);
		ft_libre(tab);
		return (1);
	}
	return (0);
}
