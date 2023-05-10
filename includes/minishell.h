/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:28:41 by achansar          #+#    #+#             */
/*   Updated: 2023/05/10 19:35:15 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef PATH_MAX
#  define PATH_MAX 1024
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <limits.h>
# include <dirent.h>
# include <string.h>
# include "structs.h"
# include "libft.h"
# include "lexer.h"
# include "parser.h"
# include "expander.h"
# include "builtins.h"
# include "executor.h"

int	g_exit_value;

// MAIN FUNCTIONS
int			init_data(t_data *data, char **envp);
int			init_process(t_data *data);

// FREE FUNCTIONS
void		free_cmd_lst(t_cmd *lst);
int			ft_unlink(t_cmd **cmd);
int			ft_free_all(t_data *data);
t_cmd		*free_cmd_elem(t_cmd *lst);

// DISPLAY
void		ft_printlist(t_lexlst *head_a);
void		ft_printparse(t_cmd *head);
int			error_msg(char c);
int			ft_exit_failure(char *str);
void		print_head(void);
void		print_error(char **res);
int			open_error(char *name, int flag);

// SIGNAL
void		sig_handler(int status);

#endif