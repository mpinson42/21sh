/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_tild.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:44:31 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/08 15:45:00 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_cd_tild(char ***tab)
{
	char *tmp;

	tab[0][1]++;
	tmp = ft_strjoin("/Users/mpinson/", tab[0][1]);
	free(tab[0][1] - 1);
	tab[0][1] = tmp;
}

int		ft_null(char *str)
{
	int i;

	i = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
			return (0);
	}
	return (-1);
}

int		ft_do_it(t_main *m, t_glob *g)
{
	if (ft_null(m->tab[m->j]) == -1)
		return (-1);
	if (main3(m, g) == -1)
		return (-1);
	if (ft_no(m->tab[m->j], g) == 1)
		return (-1);
	return (0);
}
