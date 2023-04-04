/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:25:31 by achansar          #+#    #+#             */
/*   Updated: 2023/04/04 11:25:15 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	cmd_not_found(char *cmd)
{
	char *rtr;

	rtr = ft_strjoin("Limonshello: ", cmd);
	perror(rtr);
	exit (127);
}

int first_process(t_process *process, int pi)
{
    printf("============\nFirst Process\n============\n");
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
    printf("============\nNext Process\n============\n");
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
    printf("============\nLast Process\n============\n");
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
		exit(EXIT_SUCCESS);//          renvoyer signal ? ou ligne pas necessaire ?
	}
	else
	{
		cmd = get_cmd(process, ele->cmd, ele->head);
		dprintf(2, "command found = %s\n", cmd);
		if (!cmd)
			cmd_not_found(ele->cmd[0]);
		if (execve(cmd, ele->cmd, env) == -1)
			perror("execve ");
	}
    return (0);
}
