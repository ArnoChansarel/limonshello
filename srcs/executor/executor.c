/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnalove <arnalove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:25:59 by achansar          #+#    #+#             */
/*   Updated: 2023/06/13 10:43:39 by arnalove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	open_redirections(t_process *process, t_cmd *ele)
{
	if (ele->rd_in)
	{
		if (open_infile(process, ele, 0))
			return (1);
	}
	if (ele->rd_out)
	{
		if (open_outfile(process, ele, 0))
		{
			if (process->fd1 && process->fd1 >= 0)
				close(process->fd1);
			return (1);
		}
	}
	return (0);
}

int	child(t_process *process, t_cmd *ele, char **env, int pi)
{
	if (ele->rd_in || ele->rd_out)
		if (open_redirections(process, ele))
			return (0);
	if (process->pipes_array)
	{
		if (pi == 0)
			first_process(process, pi);
		else if (process->pipes_array[pi] < 0)
			last_process(process, pi);
		else
			next_process(process, pi);
	}
	else
		dup_single_process(process);
	if (process->pipes_array)
		close_pipes(process->pipes_array);
	execute_process(ele, process, env);
	return (0);
}

int	fork_n_wait(t_process *process, t_cmd *cmd_lst, int pipes, char **env)
{
	int		i;
	int		j;
	int		fork_id;
	t_cmd	*head;

	i = 0;
	j = 0;
	head = cmd_lst;
	sig_handler(1);
	while (i++ <= pipes)
	{
		fork_id = fork();
		if (fork_id < 0)
			ft_exit_failure("fork");
		if (!fork_id)
			child(process, head, env, j);
		if (j > 0)
			close(process->pipes_array[j - 2]);
		j += 2;
		head = head->next;
	}
	closepipes_and_freeprocess(process);
	father_waits(pipes);
	sig_handler(0);
	return (0);
}

int	single_cmd(t_process *process, t_cmd *cmd, int saved_fd1, int saved_fd2)
{
	if (cmd->rd_in || cmd->rd_out)
		if (open_redirections(process, cmd))
			return (1);
	if (process->fd1 >= 0)
	{
		saved_fd1 = dup(STDIN_FILENO);
		dup2(process->fd1, STDIN_FILENO);
		close(process->fd1);
	}
	if (process->fd2 >= 0)
	{
		saved_fd2 = dup(STDOUT_FILENO);
		dup2(process->fd2, STDOUT_FILENO);
		close(process->fd2);
	}
	cmd->builtin(cmd);
	dup2(saved_fd1, STDIN_FILENO);
	if (saved_fd1 >= 0)
		close(saved_fd1);
	dup2(saved_fd2, STDOUT_FILENO);
	if (saved_fd2 >= 0)
		close(saved_fd2);
	return (0);
}

int	executor(t_process *process, t_cmd *cmd_lst, int pipes, char **env)
{
	create_here_doc(process, &cmd_lst);
	if (pipes)
	{
		create_pipes(process, pipes);
		fork_n_wait(process, cmd_lst, pipes, env);
	}
	else
	{
		if (cmd_lst->builtin)
			single_cmd(process, cmd_lst, -1, -1);
		else
			fork_n_wait(process, cmd_lst, 0, env);
	}
	return (0);
}
