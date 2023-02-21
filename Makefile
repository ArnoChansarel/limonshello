# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 11:49:05 by ade-bast          #+#    #+#              #
#    Updated: 2023/02/21 09:43:42 by ade-bast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS		= 	main.c\
				ft_split.c\
				ft_atoi.c\
				ft_strncmp.c\
				ft_strjoin.c\
				builtins_linked_list.c\
				utils.c\
				ft_cd.c\
				ft_exit.c\
				ft_env.c\
				ft_unset.c\
				ft_pwd.c\
				ft_export.c\
				ft_echo.c\
				ft_cd_utils_linked_list.c\
				ft_cd_utils.c\
				debug.c
				
					
OBJS		= $(SRCS:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 