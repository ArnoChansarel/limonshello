/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnalove <arnalove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:25:59 by achansar          #+#    #+#             */
/*   Updated: 2023/03/10 10:55:47 by arnalove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int open_redirections(t_process *process, t_cmd *ele)// Implique de remettre fd a 0 apres les avoir ferme
{
	if (ele->rd_in)
	{
		// if (ft_strncmp(ele->rd_in, "<<", 2) == 0)
		//     get_here_doc(process, ele->rd_in + 2);
		if (open_infile(process, ele))
			return (1);//                             exit ?
		//close pipe before
	}
	if (ele->rd_out)
	{
		if (open_outfile(process, ele))
		{
			if (process->fd1)
				close(process->fd1);
			return (1);//                             exit ?
		}
		// close pipe ?
	}
	printf("fd1 = %d | fd2 = %d\n", process->fd1, process->fd2);
	return (0);
}

int	child(t_process *process, t_cmd *ele, char **env, int p_index)
{
	char	*cmd;//                       check before if cmd IN ?

	(void)p_index;
	if (ele->rd_in || ele->rd_out)
		open_redirections(process, ele);
	if (process->fd1 >= 0)
		dup2(process->fd1, STDIN_FILENO);
	if (process->fd2 >= 0)
		dup2(process->fd2, STDOUT_FILENO);
		// close(process->pipe[0]);
		// dup2(process->fd1, STDIN_FILENO);
		// close(process->fd1);

		// dup2(process->pipe[1], STDOUT_FILENO);
		// close(process->pipe[1]);
	
	
	if (*ele->builtin != NULL)
	{
		ele->builtin(ele);
		exit(EXIT_SUCCESS);
	}
	else
	{
		cmd = get_cmd(process, ele->cmd);
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

int	create_pipes(t_process *process, int pipes)
{
	int	i;

	i = 0;
	process->pipes_array = malloc((pipes * 2) * sizeof(int *));
	if (!process->pipes_array)
		exit(EXIT_FAILURE);
	while (pipes)
	{
		pipe(process->pipes_array + i);
		i += 2;
		pipes--;
	}
	return (0);
}

int executor(t_process *process, t_cmd **cmd_lst, int pipes, char **env)
{
	int i;
	int j = 0;
	int	fork_id;
//                          Pipes va devenir le nb MAX de processus. Peut etre renommer 
//                          pour etre plus lisible.
	i = 0;
	if (pipes)
		create_pipes(process, pipes);
	while (i <= pipes)
	{
		fork_id = fork();
		if (fork_id < 0)
			exit(EXIT_FAILURE);
		if (!fork_id)
			child(process, *cmd_lst, env, j);
		i++;
		j += 2;
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

/*
Probleme avec cat > outfile 
     :(
*/