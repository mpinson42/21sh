/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:29:06 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/31 18:29:07 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int		ft_check2(t_glob *g, char ***tab, char ***commande, char *str)
{
	int i;

	i = 0;
	while (g->env[i] && ft_strncmp(g->env[i], "PATH=", 5) != 0)
		i++;
	if (g->env[i] == NULL)
		return (1);
	tab[0] = ft_strsplit(g->env[i] + 5, ':');
	commande[0] = ft_strsplit(str, ' ');
	return (0);
}

int		ft_check3(char **commande, char **tab, int i)
{
	int				j;
	DIR				*rep;
	struct dirent	*fichierlu[5000];

	while (tab[++i])
	{
		if (!(rep = opendir(tab[i])))
			continue ;
		j = -1;
		while ((fichierlu[++j] = readdir(rep)) != NULL)
		{
			if (ft_strcmp(fichierlu[j]->d_name, commande[0]) == 0)
			{
				ft_libre(tab);
				ft_libre(commande);
				closedir(rep);
				return (0);
			}
		}
		closedir(rep);
	}
	ft_libre(tab);
	ft_libre(commande);
	return (-1);
}

int		ft_check4(char **commande, char *str)
{
	int				j;
	DIR				*rep;
	struct dirent	*fichierlu[5000];

	commande = ft_strsplit(str + 2, ' ');
	if (!(rep = opendir("./")))
		return (1);
	j = -1;
	while ((fichierlu[++j] = readdir(rep)) != NULL)
	{
		if (ft_strcmp(fichierlu[j]->d_name, commande[0]) == 0)
		{
			ft_libre(commande);
			closedir(rep);
			return (0);
		}
	}
	ft_libre(commande);
	closedir(rep);
	return (0);
}

int		ft_check(t_glob *g, char *str)
{
	char			**tab;
	char			**commande;
	int				i;

	i = ft_check2(g, &tab, &commande, str);
	if (i != 1 && ft_check3(commande, tab, -1) == 0)
		return (0);
	commande = ft_strsplit(str, ' ');
	if (isex(commande[0]) == 1)
	{
		ft_libre(commande);
		return (ft_check4(commande, str));
	}
	ft_libre(commande);
	return (1);
}
