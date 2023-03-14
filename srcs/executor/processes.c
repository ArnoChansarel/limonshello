/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:25:31 by achansar          #+#    #+#             */
/*   Updated: 2023/03/14 13:24:58 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int first_process(t_process *process, int pi)
{
    printf("First Process\n");
	if (process->fd1 >= 0)
		dup2(process->fd1, STDIN_FILENO);
	if (process->fd2 >= 0)
		dup2(process->fd2, STDOUT_FILENO);
	else
    	dup2(process->pipes_array[pi + 1], STDOUT_FILENO);

    return (0);
}

int next_process(t_process *process, int pi)
{
    printf("next Process\n");
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

int last_process(t_process *process, int pi)
{
    printf("last Process\n");
	if (process->fd1 >= 0)
		dup2(process->fd1, STDIN_FILENO);
	else
    	dup2(process->pipes_array[pi - 2], STDIN_FILENO);
	if (process->fd2 >= 0)
		dup2(process->fd2, STDOUT_FILENO);
    return (0);
}

int execute_process(t_cmd *ele, t_process *process, char **env)
{
    char *cmd;

	if (*ele->builtin)
	{
		ele->builtin(ele);
		exit(EXIT_SUCCESS);
	}
	else
	{
		cmd = get_cmd(process, ele->cmd);
		dprintf(2, "command found = %s\n", cmd);
		if (!cmd)
		{
			// cmd_not_found(process, ele->cmd[0]);
			exit(127);
		}
		if (execve(cmd, ele->cmd, env) == -1)
			perror("execve ");
	}
    return (0);
}
