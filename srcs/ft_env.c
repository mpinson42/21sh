/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:29:38 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/31 18:29:40 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_env(char *str, t_glob *g)
{
	int		i;
	char	**tab;

	tab = ft_strsplit(str, ' ');
	i = 0;
	if (ft_strcmp("env", tab[0]) == 0)
	{
		while (g->env[i] != NULL)
		{
			ft_putendl(g->env[i]);
			i++;
		}
		ft_libre(tab);
		return (1);
	}
	ft_libre(tab);
	return (0);
}
