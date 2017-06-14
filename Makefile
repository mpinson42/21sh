NAME = 21sh

SRC = srcs/ft_dev.c srcs/main.c srcs/ft_setenv.c srcs/ft_unsetenv.c srcs/ft_env.c srcs/ft_echo.c srcs/ft_cd.c srcs/ft_check.c srcs/ft_outils.c srcs/ft_setup.c srcs/ft_cd_tild.c srcs/redirec.c

FLAGS = -Wall -Wextra -Werror

SRC2 = ft_dev.o main.o ft_setenv.o ft_unsetenv.o ft_env.o ft_echo.o ft_cd.o ft_check.o ft_outils.o ft_setup.o ft_cd_tild.o

all: $(NAME)

%.o : %.c
	gcc -c -o $@ $^

$(NAME): $(SRC)
	@echo "mpinson" > auteur
	@make -C ./libft all
	@cp ./libft/libft.a ./lib
	gcc  -I ./include/ -L ./lib -lft -o $(NAME) $(SRC)


clean:
	/bin/rm -f $(SRC2)
	@make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all
