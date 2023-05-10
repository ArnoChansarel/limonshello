/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:53:00 by achansar          #+#    #+#             */
/*   Updated: 2023/05/10 19:32:20 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	write_here_doc(t_process *pro, char **line, char *eof)
{
	if (ft_strncmp(*line, eof, ft_strlen(eof) + 1) == 0)
		return (0);
	while (*line)
	{
		write(pro->fd1, *line, ft_strlen(*line));
		write(pro->fd1, "\n", 1);
		if (*line)
			free(*line);
		*line = readline("> ");
		if (!*line)
		{
			close(pro->fd1);
			return (0);
		}
		if (ft_strncmp(*line, eof, ft_strlen(eof) + 1) == 0)
			break ;
	}
	return (0);
}

static int	get_here_doc(t_process *process, char *eof, int index)
{
	char	*line;
	char	*name;
	char	*id;

	id = ft_itoa(index);
	name = ft_strjoin("here_doc", id);
	free(id);
	process->here_doc = 1;
	process->fd1 = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (process->fd1 < 0)
		open_error(name, 1);
	free(name);
	line = readline("> ");
	if (!line)
	{
		close(process->fd1);
		return (0);
	}
	write_here_doc(process, &line, eof);
	free(line);
	close(process->fd1);
	return (0);
}

int	create_here_doc(t_process *process, t_cmd **cmd_lst)
{
	t_cmd	*head;

	head = *cmd_lst;
	while (head)
	{
		if (head->rd_in)
		{
			if (ft_strncmp(head->rd_in, "<<", 2) == 0)
				get_here_doc(process, head->rd_in + 2, head->index);
		}
		head = head->next;
	}
	return (0);
}

int	open_outfile(t_process *process, t_cmd *ele, int i)
{
	if (ft_strncmp(ele->rd_out, ">>", 2) == 0)
	{
		i += 2;
		process->fd2 = open(&ele->rd_out[i],
				O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (process->fd2 < 0)
			return (open_error(&ele->rd_in[i], 0));
	}
	else
	{
		i++;
		process->fd2 = open(&ele->rd_out[i],
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (process->fd2 < 0)
			return (open_error(&ele->rd_out[i], 0));
	}
	return (0);
}

int	open_infile(t_process *process, t_cmd *ele, int i)
{
	char	*name;
	char	*index;

	name = NULL;
	if (process->here_doc)
	{
		index = ft_itoa(ele->index);
		name = ft_strjoin("here_doc", index);
		free(index);
		process->fd1 = open(name, O_CREAT, O_RDONLY);
		if (process->fd1 < 0)
			open_error(name, 1);
		free(name);
	}
	else
	{
		while (ele->rd_in[i] && ele->rd_in[i] == '<')
			i++;
		process->fd1 = open(&ele->rd_in[i], O_RDONLY);
		if (process->fd1 < 0)
			open_error(&ele->rd_in[i], 1);
	}
	if (process->fd1 < 0)
		ft_exit_failure(&ele->rd_in[i]);
	return (0);
}
