/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:25:31 by achansar          #+#    #+#             */
/*   Updated: 2023/04/10 17:59:20 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	cmd_not_found(char *cmd)
{
	char	*rtr1;
	char	*rtr2;

	rtr1 = ft_strjoin("Limonshello: ", cmd);
	rtr2 = ft_strjoin(rtr1, ": command not found\n");
	write(2, rtr2, ft_strlen(rtr2));
	free(rtr1);
	free(rtr2);
	exit (127);
}

int	first_process(t_process *process, int pi)
{
	if (process->fd1 >= 0)
		dup2(process->fd1, STDIN_FILENO);
	if (process->fd2 >= 0)
		dup2(process->fd2, STDOUT_FILENO);
	else
		dup2(process->pipes_array[pi + 1], STDOUT_FILENO);
	return (0);
}

int	next_process(t_process *process, int pi)
{
	if (process->fd1 >= 0)
		dup2(process->fd1, STDIN_FILENO);
	else
		dup2(process->pipes_array[pi - 2], STDIN_FILENO);
	if (process->fd2 >= 0)
		dup2(process->fd2, STDOUT_FILENO);
	else
		dup2(process->pipes_array[pi + 1], STDOUT_FILENO);
	return (0);
}

int	last_process(t_process *process, int pi)
{
	if (process->fd1 >= 0)
		dup2(process->fd1, STDIN_FILENO);
	else
		dup2(process->pipes_array[pi - 2], STDIN_FILENO);
	if (process->fd2 >= 0)
		dup2(process->fd2, STDOUT_FILENO);
	return (0);
}

int	execute_process(t_cmd *ele, t_process *process, char **env)
{
	char	*cmd;

	if (!ele->cmd[0])
		exit(EXIT_SUCCESS);
	cmd = get_cmd(process, ele->cmd, ele->head);
	if (!cmd)
		cmd_not_found(ele->cmd[0]);
	if (strncmp(ele->cmd[0], "/usr/bin/env", ft_strlen(ele->cmd[0])) == 0)
	{
		ft_env(ele);
		exit(EXIT_SUCCESS);
	}
	if (execve(cmd, ele->cmd, env) == -1)
		ft_exit_failure("execve ");
	return (0);
}
