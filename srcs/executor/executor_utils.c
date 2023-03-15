/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:53:00 by achansar          #+#    #+#             */
/*   Updated: 2023/03/15 12:46:28 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_here_doc(t_process *process, char *eof, int index)
{
	char	*line;
	char	*name;

	name = ft_strjoin("here_doc", ft_itoa(index));
    process->here_doc = 1;
	process->fd1 = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (process->fd1 < 0)
		return (1);
	line = get_next_line(0);
	while (line)
	{
		write(process->fd1, line, ft_strlen(line));
		if (line)
			free(line);
		line = get_next_line(0);
		if (ft_strncmp(line, eof, ft_strlen(eof)) == 0)//        /!\ warning check +1
			break ;
	}
	free(line);
	free(name);
	close(process->fd1);
	return (0);
}

int	create_here_doc(t_process *process, t_cmd **cmd_lst)
{
	t_cmd	*head;

	head = *cmd_lst;
	while (head)
	{
		if (ft_strncmp(head->rd_in, "<<", 2) == 0)
	    	get_here_doc(process, head->rd_in + 2, head->index);
		head = head->next;
	}
	return (0);
}

int open_outfile(t_process *process, t_cmd *ele)
{
	if (ft_strncmp(ele->rd_out, ">>", 2) == 0)
	{
		ele->rd_out += 2;
        process->fd2 = open(ele->rd_out, O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	else
    {
		ele->rd_out++;
		process->fd2 = open(ele->rd_out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	if (process->fd2 < 0)
	{
		perror(ele->rd_out);
		return (1);
	}
	return (0);
}

int	open_infile(t_process *process, t_cmd *ele)
{
	char	*name;

	name = NULL;
	if (process->here_doc)
	{
		name = ft_strjoin("here_doc", ft_itoa(ele->index));
		process->fd1 = open(name, O_CREAT, O_RDONLY);
		free(name);
	}
	else
	{
		while (*ele->rd_in && *ele->rd_in == '<')
			ele->rd_in++;
		process->fd1 = open(ele->rd_in, O_RDONLY);
	}
	if (process->fd1 < 0)
	{
		perror(ele->rd_in);
		return (1);
	}
	return (0);
}

int	create_pipes(t_process *process, int pipes)
{
	int	i;

	i = 0;
	process->pipes_array = malloc((pipes * 2 + 1) * sizeof(int *));
	if (!process->pipes_array)
		exit(EXIT_FAILURE);
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
	int i = 0;
	while (array[i] != -1)
	{
		close(array[i++]);
	}
	// printf("Pipes fd : ");
	// i = 0;
	// while (array[i] != -1)
	// 	printf("%d ", array[i++]);
	// printf("\n");
	return (0);
}
