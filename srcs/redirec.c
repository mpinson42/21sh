#include "mini.h"

int ft_pipe(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '|')
			return(0);
		i++;
	}
	return(-1);
}

int ft_gopipe(t_main *m, t_glob *g, char **env)
{
	char **tab = ft_strsplit(m->tab[m->j], '|');
	int pfd[2];
	int i = 0;
	int pid;

	while(tab[1][i] == ' ' || tab[1][i] == '\t')
		i++;
	tab[1] += i;
	i = 0;
	while(tab[1][i] == ' ' || tab[1][i] == '\t')
		i++;
	tab[1] += i;



	pipe(pfd);
	pid = fork();
	if (pid == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
		ft_dev(tab[1], m->id, g, env);
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		ft_dev(tab[0], m->id, g, env);
	}
	return 0;
}

void	doobul_raigth(t_main *m, t_glob *g, char **env)
{
	int fd;
	char **tab = ft_strsplit(m->tab[m->j], '>');
	char **file = ft_strsplit(tab[1], ' ');
	int i;

	i = 0;
	while(file[0][i] == ' ' || file[0][i] == '\t')
		i++;
	file[0] += i;
	fd = open(file[0], O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(fd, 1);
	ft_dev(tab[0], m->id, g, env);
}

void	simple_raigth(t_main *m, t_glob *g, char **env)
{
	int fd;
	char **tab = ft_strsplit(m->tab[m->j], '>');
	char **file = ft_strsplit(tab[1], ' ');
	int i;
	char *str;

	i = 0;
	if(access(file[0], F_OK) == 0)
	{
		m->id = fork();
		if(m->id == 0)
		{
			str = ft_strjoin("rm -rf ",file[0]);
			ft_dev(str, m->id, g, env);
		}
		if(m->id > 0)
		{
			wait(&m->id);
		}
	}
	while(file[0][i] == ' ' || file[0][i] == '\t')
		i++;
	file[0] += i;
	fd = open(file[0], O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(fd, 1);
	ft_dev(tab[0], m->id, g, env);

}

void	doobul_left(t_main *m, t_glob *g, char **env)
{
	int fd;
	char **tab = ft_strsplit(m->tab[m->j], '<');
	char **file = ft_strsplit(tab[1], ' ');
	int i;
	char *str;
	char buffer[5000];

	i = 0;
	if(access(".sys", F_OK) == 0)
	{
		m->id = fork();
		if(m->id == 0)
		{
			str = ft_strjoin("rm -rf ",".sys");
			ft_dev(str, m->id, g, env);
		}
		if(m->id > 0)
		{
			wait(&m->id);
		}
	}
	while(file[0][i] == ' ' || file[0][i] == '\t')
		i++;
	file[0] += i;

	ft_bzero(buffer, 5000);
	file[0] = ft_strjoin(file[0], "\n");
	str = ft_strdup("");
	while(ft_strcmp(buffer, file[0]) != 0)
	{
		ft_putstr(">");
		ft_bzero(buffer, 5000);
		read(1, buffer, 5000);
		if(ft_strcmp(buffer, file[0]) != 0)
			str = ft_strjoin(str, buffer);
	}
	fd = open(".sys", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	write(fd, str, ft_strlen(str));
	close(fd);
	fd = open(".sys", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(fd, 0);
	ft_dev(tab[0], m->id, g, env);
}

void	simple_left(t_main *m, t_glob *g, char **env)
{
	int fd;
	char **tab = ft_strsplit(m->tab[m->j], '<');
	char **file = ft_strsplit(tab[1], ' ');

	fd = open(file[0], O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(fd, 0);
	ft_dev(tab[0], m->id, g, env);
	exit(0);
}

int agre(t_main *m)
{
	char *str;
	int i;
	int y;

	if((str = ft_strstr(m->tab[m->j], ">&")) != NULL)
	{
		str--;
		if(ft_isdigit(str[0]))
			i = str[0] - 48;
		else
			i = 1;
		str = str + 3;

		if(str[0] == '~')
			close(i);
		else if(ft_isdigit(str[0]))
			dup2(y, i);
		return(-1);
	}
	return(0);
}

int ft_redirect(t_main *m, t_glob *g, char **env)
{
	if(ft_pipe(m->tab[m->j]) == 0)
	{
		m->id = fork();
		if(m->id == 0)
			ft_gopipe(m, g, env);
		if(m->id > 0)
		{
			wait(&m->id);
		}
		return(-1);
	}
	if(ft_strstr(m->tab[m->j], ">>") != NULL)
	{
		m->id = fork();
		if(m->id == 0)
			doobul_raigth(m, g, env);
		if(m->id > 0)
		{
			wait(&m->id);
		}
		return(-1);
	}
	if(ft_strstr(m->tab[m->j], ">") != NULL)
	{
		m->id = fork();
		if(m->id == 0)
			simple_raigth(m, g, env);
		if(m->id > 0)
		{
			wait(&m->id);
		}
		return(-1);
	}
	if(ft_strstr(m->tab[m->j], "<<") != NULL)
	{
		m->id = fork();
		if(m->id == 0)
			doobul_left(m, g, env);
		if(m->id > 0)
		{
			wait(&m->id);
		}
		return(-1);
	}
	if(ft_strstr(m->tab[m->j], "<") != NULL)
	{
		m->id = fork();
		if(m->id == 0)
			simple_left(m, g, env);
		if(m->id > 0)
		{
			wait(&m->id);
		}
		return(-1);
	}
	return(0);
}


