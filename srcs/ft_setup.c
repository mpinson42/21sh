/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:36:20 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/01 13:36:21 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int		ft_slah(char *str, char **env)
{
	char **tab;

	if (str[0] == '/')
	{
		tab = ft_strsplit(str, ' ');
		execve(tab[0], tab, env);
		ft_libre(tab);
		return (-1);
	}
	return (0);
}

int		ft_no(char *str, t_glob *g)
{
	if (ft_env(str, g) == 1)
		return (1);
	if (ft_echo(str, g) == 1)
		return (1);
	if (ft_cd(str, g) == 1)
		return (1);
	if (ft_strncmp("setenv", str, 5) == 0)
	{
		ft_set_env(str, g);
		return (1);
	}
	if (ft_strncmp("unsetenv", str, 7) == 0)
	{
		ft_unset_env(str, g);
		return (1);
	}
	return (0);
}

void	titel(void)
{
	write(1, "\e[0;32m", 8);
	ft_putstr(" _____ ______   ________  ___  ___");
	ft_putstr("_____   ________  ________  ________      \n");
	ft_putstr("\\   _ \\  _   \\|\\   __  \\|\\  \\|\\   ___ ");
	ft_putstr(" \\|\\   ____\\|\\   __  \\|\\   ___  \\    \n");
	ft_putstr("\\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\ \\  \\\\ ");
	ft_putstr("\\  \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\ \\  \\   \n");
	ft_putstr(" \\ \\  \\\\|__| \\  \\ \\   ____\\ \\  \\ \\  \\\\ \\  ");
	ft_putstr("\\ \\_____  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\  \n");
	ft_putstr("  \\ \\  \\    \\ \\  \\ \\  \\___|\\ \\  \\ \\  \\\\ \\  ");
	ft_putstr("\\|____|\\  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \n");
	ft_putstr("   \\ \\__\\    \\ \\__\\ \\__\\    \\ \\__\\ \\__\\\\ \\__");
	ft_putstr("\\____\\_\\  \\ \\_______\\ \\__\\\\ \\__\\\n");
	ft_putstr("    \\|__|     \\|__|\\|__|     \\|__|\\|__| \\|__|");
	ft_putstr("\\_________\\|_______|\\|__| \\|__|\n");
	ft_putstr("                                            ");
	ft_putstr("\\|_________|                    \n");
	write(1, "\e[0;m", 6);
}

int		setup_env(char ***env, t_glob *g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	titel();
	if (!(g->env = (char **)malloc(sizeof(char *) *
		(ft_strlen_tab(env[0]) + 1))))
		return (-1);
	while (env[0][i])
	{
		g->env[j] = ft_strdup(env[0][i]);
		i++;
		j++;
	}
	g->env[j] = NULL;
	env = &g->env;
	return (0);
}
