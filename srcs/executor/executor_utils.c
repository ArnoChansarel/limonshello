/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:53:00 by achansar          #+#    #+#             */
/*   Updated: 2023/04/10 15:01:31 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	write_here_doc(t_process *pro, char **line, char **name, char *eof)
{
	while (*line)
	{
		write(pro->fd1, *line, ft_strlen(*line));
		write(pro->fd1, "\n", 1);
		if (*line)
			free(*line);
		*line = readline("> ");
		if (!*line)
		{
			free(*name);
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

	name = ft_strjoin("here_doc", ft_itoa(index));
	process->here_doc = 1;
	process->fd1 = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (process->fd1 < 0)
		ft_exit_failure("open");
	line = readline("> ");
	if (!line)
	{
		free(name);
		close(process->fd1);
		return (0);
	}
	if (ft_strncmp(line, eof, ft_strlen(eof) + 1) == 0)
		return (0);
	write_here_doc(process, &line, &name, eof);
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
		if (head->rd_in)
		{
			if (ft_strncmp(head->rd_in, "<<", 2) == 0)
				get_here_doc(process, head->rd_in + 2, head->index);
		}
		head = head->next;
	}
	return (0);
}

int	open_outfile(t_process *process, t_cmd *ele)
{
	if (ft_strncmp(ele->rd_out, ">>", 2) == 0)
	{
		ele->rd_out += 2;
		process->fd2 = open(ele->rd_out, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (process->fd2 < 0)
			ft_exit_failure("open");
	}
	else
	{
		ele->rd_out++;
		process->fd2 = open(ele->rd_out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (process->fd2 < 0)
			ft_exit_failure("open");
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
		if (process->fd1 < 0)
			ft_exit_failure("open");
		free(name);
	}
	else
	{
		while (*ele->rd_in && *ele->rd_in == '<')
			ele->rd_in++;
		process->fd1 = open(ele->rd_in, O_RDONLY);
		if (process->fd1 < 0)
			ft_exit_failure("open");
	}
	if (process->fd1 < 0)
	{
		perror(ele->rd_in);
		return (1);
	}
	return (0);
}
