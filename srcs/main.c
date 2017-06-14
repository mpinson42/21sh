/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 18:30:06 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/14 13:05:41 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	gestion2(int signial);
void	gestion(int signial);

int		main2(char (*str)[5000], char ***tab)
{
	int i;

	ft_bzero(str[0], 5000);
	ft_pronpt();
	if (read(0, str, 5000) == -1)
		return (-1);
	if (str[0][0] == '\0')
		exit(0);
	i = -1;
	while (str[0][++i])
	{
		str[0][i] == '\t' ? str[0][i] = ' ' : 0;
		str[0][i] == '\n' ? str[0][i] = '\0' : 0;
		if ((str[0][i] == ' ') && i == (int)ft_strlen(str[0]) - 1)
			return (-1);
	}
	i = ft_strlen(str[0]) - 1;
	while (i >= 0 && (str[0][i] == ' ' || str[0][i] == '\t'
				|| str[0][i] == '\n' || str[0][i] == 0))
		str[0][i--] = 0;
	if (!(tab[0] = ft_strsplit(str[0], ';')))
		return (-1);
	return (0);
}

int		main3(t_main *m, t_glob *g)
{
	m->i = 0;
	while (m->tab[m->j][m->i] == ' ')
		m->i++;
	if (m->i)
	{
		if (!(m->tmp = ft_strsub(m->tab[m->j], m->i, ft_strlen(m->tab[m->j]))))
			return (-1);
		free(m->tab[m->j]);
		m->tab[m->j] = m->tmp;
	}
	if ((m->tab[m->j][0] == '/' ||
				ft_strncmp(m->tab[m->j], "./", 2) == 0) && ft_isdir(m->tab[m->j]))
	{
		free(m->tmp);
		m->tmp = ft_strjoin("cd ", m->tab[m->j]);
		ft_cd(m->tmp, g);
		free(m->tmp);
		return (-1);
	}
	return (0);
}



int		main4(t_main *m, t_glob *g, char **env)
{
	if (ft_check(g, m->tab[m->j]) == 1)
	{
		ft_putendl("error : commande not found");
		return (-1);
	}
	if(ft_redirect(m, g, env) == -1)
		return (-1);
	m->id = fork();
	if (ft_strncmp("echo", m->tab[m->j], 4) &&
			ft_strncmp("cd", m->tab[m->j], 2))
		ft_dev(m->tab[m->j], m->id, g, env);
	g_id = m->id;
	if (m->id > 0)
	{
		wait(&m->id);
		m->id == 11 ? ft_putstr("segmentation fault\n") : 0;
	}
	return (0);
}

void	gestion(int signial)
{
	if (signial == SIGINT)
	{
		ft_putstr("\n");
		if (g_id == 0)
			ft_pronpt();
	}
	else
		exit(0);
}

void	gestion2(int signial)
{
	if (signial == SIGINT)
	{
		exit(0);
	}
	else
		exit(0);
}

int		main(void)
{
	t_main		m;
	t_glob		g;
	extern char **environ;

	if (setup_env(&environ, &g) == -1)
		return (-1);
	signal(SIGINT, gestion);
	while (1)
	{
		g_id = 0;
		if (main2(&m.str, &m.tab) == -1)
			continue ;
		m.j = -1;
		while (m.tab[++m.j] != NULL)
		{
			if (ft_do_it(&m, &g) == -1)
				continue ;
			if(agre(&m) == -1)
				continue ;
			if (ft_strncmp(m.tab[m.j], "exit", 4) == 0)
				return (0);
			if (main4(&m, &g, g.env) == -1)
				continue ;
		}
		ft_libre(m.tab);
	}
}
