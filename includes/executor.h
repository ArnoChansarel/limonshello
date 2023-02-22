/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:00:50 by achansar          #+#    #+#             */
/*   Updated: 2023/02/22 17:29:33 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
#include "minishell.h"

typedef struct s_pipex {
	pid_t	pid;
	int		pipe[2];
	char	*env_path;
	char	**cmd_paths;
	char	**command;
	char	*cmd;
	int		fd1;
	int		fd2;
    int     here_doc;
}	t_pipex;

// EXECUTOR FUNCTIONS
int     executor(t_cmd **cmd_lst, int pipes);

// EXECUTOR UTILS
char	*get_cmd(t_pipex *pipex, char **cmd);

#endif