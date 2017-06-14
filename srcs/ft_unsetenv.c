/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:29:58 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/31 18:30:00 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_unsetenv(char **test, char **tab, t_glob *g)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (test[i])
	{
		if (ft_strncmp(test[i], tab[1], ft_strlen(tab[1])) != 0)
		{
			tmp = ft_strdup(test[i]);
			g->env[j] = tmp;
			j++;
		}
		i++;
	}
	g->env[j] = NULL;
	ft_libre(tab);
	ft_libre(test);
}

void	ft_unset_env(char *str, t_glob *g)
{
	char	**tab;
	int		i;
	char	**test;

	tab = ft_strsplit(str, ' ');
	i = 0;
	while (g->env[i] != NULL && ft_strncmp(g->env[i],
		tab[1], ft_strlen(tab[1])) != 0)
		i++;
	if (tab[1] == NULL || g->env[i] == NULL)
	{
		ft_libre(tab);
		return ;
	}
	i = -1;
	if (!(test = (char**)malloc(sizeof(char*) * (ft_strlen_tab(g->env) + 2))))
		return ;
	while (g->env[++i])
		test[i] = ft_strdup(g->env[i]);
	test[i] = NULL;
	ft_libre(g->env);
	if (!(g->env = (char **)malloc(sizeof(char *) * (ft_strlen_tab(test)))))
		return ;
	ft_unsetenv(test, tab, g);
}
