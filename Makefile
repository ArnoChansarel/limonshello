# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achansar <achansar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:37:56 by achansar          #+#    #+#              #
#    Updated: 2023/05/09 16:52:07 by achansar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TARGET
NAME = minishell

#ARGUMENTS
CC = gcc
FLAGS = -Wall -Werror -Wextra
SEG = #-fsanitize=address -g
READLINE = -lreadline
LDFLAGS		= -L$(HOME)/.brew/opt/readline/lib
CPPFLAGS	= -I$(HOME)/.brew/opt/readline/include

# MAIN FILE
MAIN_PATH = ./srcs/
MAIN_SRC = 	minishell \
			minishell_utils \
			display \
			signal \
			free
MAIN_CFILE = $(addprefix $(MAIN_PATH), $(MAIN_SRC:=.c))
MAIN_OBJ = $(addprefix $(MAIN_PATH), $(MAIN_SRC:=.o))

#BUILTINS FILES
B_SRC_PATH = ./srcs/builtins/
B_SRC = builtins_linked_list \
		ft_pwd \
		ft_cd \
		ft_cd_utils \
		ft_cd_utils_linked_list \
		utils \
		ft_echo \
		ft_env \
		ft_exit \
		ft_export \
		ft_unset \
		ft_export_utils_linked_list
B_C_FILES = $(addprefix $(B_SRC_PATH), $(B_SRC:=.c))
B_OBJ = $(addprefix $(B_SRC_PATH), $(B_SRC:=.o))

#PARSER FILES
P_SRC_PATH = ./srcs/parser/
P_SRC = 	lexer \
			lexer_utils \
			parser \
			parser_utils \
			redirections \
			expander \
			expander_var \
			expander_utils \
			get_builtin
P_C_FILES = $(addprefix $(P_SRC_PATH), $(P_SRC:=.c))
P_OBJ = $(addprefix $(P_SRC_PATH), $(P_SRC:=.o))

#EXECUTER FILES
E_SRC_PATH = ./srcs/executor/
E_SRC = 	executor \
			executor_utils \
			executor_utils2 \
			get_command \
			processes
E_C_FILES = $(addprefix $(E_SRC_PATH), $(E_SRC:=.c))
E_OBJ = $(addprefix $(E_SRC_PATH), $(E_SRC:=.o))

#LIBFT
LBFT_PATH = ./libft/
LBFT = 	ft_split \
		ft_strlcpy \
		ft_strjoin \
		ft_strlen \
		ft_substr \
		ft_strncmp \
		ft_strnstr \
		ft_lstadd_back \
		ft_lstadd_front \
		ft_lstclear \
		ft_lstlast \
		ft_lstsize \
		lex_lst \
		parser_lst \
		ft_putstr_fd \
		ft_isalpha \
		ft_strchr \
		ft_atoi \
		ft_strdup \
		ft_memcpy \
		ft_itoa \
		ft_isalnum
LBFT_FILES = $(addprefix $(LBFT_PATH), $(LBFT:=.c))
LBFT_OBJ = $(addprefix $(LBFT_PATH), $(LBFT:=.o))

#RULES
all: $(NAME)

$(NAME): $(MAIN_OBJ) $(P_OBJ) $(B_OBJ) $(LBFT_OBJ) $(E_OBJ)
	@ $(CC) $(FLAGS) $(LDFLAGS) $(CPPFLAGS) $(READLINE) $(MAIN_OBJ) $(P_OBJ) $(B_OBJ) $(E_OBJ) $(LBFT_OBJ) -o $(NAME) $(SEG)

.c.o:
	@ $(CC) $(FLAGS) $(CPPFLAGS) -c $< -o $@ $(SEG)

clean:
	@rm -f $(MAIN_OBJ) $(P_OBJ) $(B_OBJ) $(E_OBJ) $(LBFT_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all clean

.PHONY: all bonus clean fclean re

