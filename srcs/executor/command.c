/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:12:18 by achansar          #+#    #+#             */
/*   Updated: 2023/02/22 16:31:07 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// /!\ CHECK AWK /!
// USE GETENV() !!

static char	*check_cmd(t_pipex *pipex, char **cmd)
{
	int		i;
	char	*cmd_path;
	char	*join;

	i = 0;
	if (access(cmd[0], F_OK) == 0)
		return (cmd[0]);
	else
	{
		while (pipex->cmd_paths[i])
		{
			join = ft_strjoin(pipex->cmd_paths[i], "/");
			if (!join)
				return (NULL);
			cmd_path = ft_strjoin(join, cmd[0]);
			free(join);
			if (!cmd_path)
				return (NULL);
			if (access(cmd_path, F_OK) == 0)
				return (cmd_path);
			free(cmd_path);
			i++;
		}
	}
	return (NULL);
}

char	*get_cmd(t_pipex *pipex, char **cmd)
{
	char	*cmd_rtr;

	if (*cmd == '\0')//             => voir si utile
		return (NULL);
	cmd_rtr = NULL;
    pipex->env_path = getenv("PATH");
	cmd_rtr = check_cmd(pipex, cmd);
	if (!cmd_rtr)
		return (NULL);
	return (cmd_rtr);
}