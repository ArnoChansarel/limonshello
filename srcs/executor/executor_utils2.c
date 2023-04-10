/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:41:36 by achansar          #+#    #+#             */
/*   Updated: 2023/04/09 17:49:21 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	create_pipes(t_process *process, int pipes)
{
	int	i;

	i = 0;
	process->pipes_array = malloc((pipes * 2 + 1) * sizeof(int *));
	if (!process->pipes_array)
		ft_exit_failure("malloc");
	while (pipes)
	{
		pipe(process->pipes_array + i);
		i += 2;
		pipes--;
	}
	process->pipes_array[i] = -1;
	return (0);
}

int	close_pipes(int *array)
{
	int	i;

	i = 0;
	while (array[i] != -1)
	{
		close(array[i++]);
	}
	return (0);
}

void	closepipes_and_freeprocess(t_process *process)
{
	if (process->pipes_array)
	{
		close_pipes(process->pipes_array);
		free(process->pipes_array);
	}
}

void	dup_single_process(t_process *process)
{
	if (process->fd1 >= 0)
	{
		dup2(process->fd1, STDIN_FILENO);
		close(process->fd1);
	}
	if (process->fd2 >= 0)
	{
		dup2(process->fd2, STDOUT_FILENO);
		close(process->fd2);
	}
}

int	father_waits(int pipes)
{
	int	status;
	int	var;
	int	i;

	i = 0;
	while (i <= pipes)
	{
		waitpid(-1, &status, 0);
		var = WEXITSTATUS(status);
		g_exit_value = var;
		i++;
	}
	return (0);
}