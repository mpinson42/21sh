/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:36:06 by mpinson           #+#    #+#             */
/*   Updated: 2017/06/01 13:36:07 by mpinson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int		isex(char *str)
{
	struct stat s;

	if (lstat(str, &s) == -1)
		return (0);
	if (s.st_mode & S_IXUSR && s.st_mode & S_IXGRP && s.st_mode & S_IXOTH)
	{
		return (1);
	}
	return (0);
}

void	ft_libre(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int		ft_strlen_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int		ft_isdir(char *str)
{
	DIR *rep;

	if (!(rep = opendir(str)))
		return (0);
	closedir(rep);
	return (1);
}

void	ft_pronpt(void)
{
	int		i;
	char	test[1000];

	getcwd(test, 4999);
	i = ft_strlen(test);
	while (i > 0 && test[i] != '/')
		i--;
	write(1, "\e[1;32m", 8);
	ft_putchar(0xe2);
	ft_putchar(0x9e);
	ft_putchar(0x9c);
	ft_putstr("  ");
	write(1, "\e[1;36m", 8);
	ft_putstr(test + i + 1);
	write(1, "\e[0;m", 6);
	ft_putchar(0xf0);
	ft_putchar(0x9f);
	ft_putchar(0xa6);
	ft_putchar(0x84);
	ft_putstr("  > ");
}
