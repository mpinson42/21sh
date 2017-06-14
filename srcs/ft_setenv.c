/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:29:50 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/31 18:29:52 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int		ft_setenv3(char **var, char ***tab, t_glob *g)
{
	int i;

	i = 0;
	while (g->env[i] && ft_strncmp(g->env[i], tab[0][1],
		ft_strlen(tab[0][1])) != 0)
		i++;
	if (g->env[i] != NULL)
	{
		ft_libre(tab[0]);
		free(g->env[i]);
		g->env[i] = var[0];
		return (-1);
	}
	return (0);
}

int		ft_setenv2(char **var, char ***tab, char *str, t_glob *g)
{
	int		i;
	char	*tmp;

	i = 0;
	tab[0] = ft_strsplit(str, ' ');
	if (tab[0][1] == NULL)
	{
		ft_libre(tab[0]);
		return (-1);
	}
	tmp = ft_strjoin(tab[0][1], "=");
	if (tab[0][2])
		var[0] = ft_strjoin(tmp, tab[0][2]);
	else
		var[0] = ft_strjoin(tab[0][1], "=");
	free(tmp);
	return (ft_setenv3(var, tab, g));
}

int		ft_setenv4(char **var, char ***tab, t_glob *g)
{
	int i;

	i = 0;
	while (g->env[i] && ft_strncmp(g->env[i],
		tab[0][1], ft_strlen(tab[0][1])) != 0)
		i++;
	if (g->env[i] != NULL)
	{
		ft_libre(tab[0]);
		free(g->env[i]);
		g->env[i] = var[0];
		return (-1);
	}
	return (0);
}

void	ft_set_env(char *str, t_glob *g)
{
	char	**tab;
	char	*var;
	char	**test;
	int		i;

	if (ft_setenv2(&var, &tab, str, g) == -1 ||
		ft_setenv4(&var, &tab, g) == -1)
		return ;
	i = -1;
	test = (char**)malloc(sizeof(char*) *
		(ft_strlen_tab(g->env) + 2));
	while (g->env[++i])
		test[i] = ft_strdup(g->env[i]);
	test[i] = NULL;
	i = -1;
	ft_libre(g->env);
	if (!(g->env = (char **)malloc(sizeof(char *) *
		(ft_strlen_tab(test) + 2))))
		return ;
	while (test[++i] != NULL)
		g->env[i] = ft_strdup(test[i]);
	g->env[i] = var;
	g->env[i + 1] = NULL;
	ft_libre(tab);
	ft_libre(test);
}
