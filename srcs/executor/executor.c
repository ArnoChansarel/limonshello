/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:25:59 by achansar          #+#    #+#             */
/*   Updated: 2023/03/15 12:48:14 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int open_redirections(t_process *process, t_cmd *ele)
{
	if (ele->rd_in)
	{
		if (open_infile(process, ele))
			return (1);//                             exit ?
	}
	if (ele->rd_out)
	{
		if (open_outfile(process, ele))
		{
			if (process->fd1)
				close(process->fd1);
			return (1);//                             exit ?
		}
	}
	printf("fd1 = %d | fd2 = %d\n", process->fd1, process->fd2);
	return (0);
}

int	child(t_process *process, t_cmd *ele, char **env, int pi)
{
	if (ele->rd_in || ele->rd_out)
		open_redirections(process, ele);

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
	{
		if (process->fd1 >= 0)
			dup2(process->fd1, STDIN_FILENO);
		if (process->fd2 >= 0)
			dup2(process->fd2, STDOUT_FILENO);
	}
	if (process->pipes_array)
		close_pipes(process->pipes_array);
	execute_process(ele, process, env);
	return (0);
}

int executor(t_process *process, t_cmd **cmd_lst, int pipes, char **env)
{
	int i;
	int j = 0;
	int	fork_id;
	t_cmd	*head;

	i = 0;
	head = *cmd_lst;
	if (pipes)
		create_pipes(process, pipes);
	create_here_doc(process, cmd_lst);
	while (i++ <= pipes)
	{
		fork_id = fork();
		if (fork_id < 0)
			exit(EXIT_FAILURE);
		if (!fork_id)
			child(process, head, env, j);
		// close(process->pipes_array[j + 1]);
		if (j > 0)
			close(process->pipes_array[j - 2]);
		j += 2;
		head = head->next;
	}
	if (process->pipes_array)
	{
		close_pipes(process->pipes_array);
		free(process->pipes_array);
	}
	i = 0;
	while (i <= pipes)
	{
		waitpid(-1, NULL, 0);//         EXIT : check si erreur = 255 alors exit aussi
		i++;
	}
	//ici pere doit fermer les fd fichiers + pipes
	// mais fichiers ouverts dans fils, il faut pas les fermer alors ?
	return (0);
}
