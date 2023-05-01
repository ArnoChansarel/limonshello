/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:38:30 by achansar          #+#    #+#             */
/*   Updated: 2023/04/28 16:47:22 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_env {
	int				export;
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_lexlst {
	char			*word;
	struct s_lexlst	*next;
}	t_lexlst;

typedef struct s_cmd {
	char			**cmd;
	int				(*builtin)(struct s_cmd *);
	char			*rd_in;
	char			*rd_out;
	t_env			*head;
	struct s_cmd	*next;
	int				exit_status;
	int				index;
	char			*cwd;
}	t_cmd;

typedef struct s_process {
	pid_t	pid;
	int		*pipes_array;
	char	*env_path;
	char	**cmd_paths;
	int		fd1;
	int		fd2;
	int		here_doc;
}	t_process;

typedef struct s_data {
	t_process	*process;
	t_cmd		*lst;
	char		*line;
	int			pipes;
	t_lexlst	*lexer_lst;
	t_env		*env;
	char		*cwd;
}	t_data;

#endif