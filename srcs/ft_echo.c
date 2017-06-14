/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:29:24 by mpinson           #+#    #+#             */
/*   Updated: 2017/05/31 18:29:26 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_echo2(char *str, char *tmp, t_glob *g, int i)
{
	int j;

	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			j = i;
			while (str[j] && str[j] != ' ')
				j++;
			tmp = ft_strsub(str, i, ft_absolut(i - j));
			i = i + ft_strlen(tmp) - 1;
			j = 0;
			while (g->env[j] && ft_strncmp(g->env[j], tmp, ft_strlen(tmp)) != 0)
				j++;
			if (g->env[j] != NULL)
				ft_putstr(g->env[j] + ft_strlen(tmp) + 1);
			free(tmp);
		}
		else if (str[i] != '"')
			ft_putchar(str[i]);
		i++;
	}
}

int		ft_echo(char *str, t_glob *g)
{
	char **tab;
	char *tmp;

	tmp = NULL;
	tab = ft_strsplit(str, ' ');
	if (ft_strcmp("echo", tab[0]) == 0)
	{
		ft_echo2(str, tmp, g, 5);
		if (tab[1])
			ft_putchar('\n');
		ft_libre(tab);
		return (1);
	}
	ft_libre(tab);
	return (0);
}
