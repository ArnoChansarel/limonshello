/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:53:00 by achansar          #+#    #+#             */
/*   Updated: 2023/02/22 17:32:23 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_here_doc(t_pipex *pipex, char *eof)
{
	char	*line;

    pipex->here_doc = 1;
	pipex->fd1 = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0444);
	if (pipex->fd1 < 0)
		return (1);
	line = get_next_line(0);
	while (line)
	{
		write(pipex->fd1, line, ft_strlen(line));
		if (line)
			free(line);
		line = get_next_line(0);
		if (ft_strncmp(line, eof, ft_strlen(eof)) == 0)
			break ;
	}
	free(line);
	close(pipex->fd1);
	return (0);
}

int open_outfile(t_pipex *pipex, int argc, char **argv, char **env)
{
	if (pipex->here_doc)
		pipex->fd2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		pipex->fd2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->fd2 < 0)
	{
		perror(argv[argc - 1]);
		return (1);
	}
	if (pipex->args.here_doc == 1)
		get_here_doc(pipex, argv);
	pipex->fd1 = open(argv[1], O_RDONLY);
	if (pipex->fd1 < 0)
	{
		close (pipex->fd2);
		perror(argv[1 + pipex->args.here_doc]);
		return (1);
	}
	return (0);
}

int	open_infile(t_pipex *pipex, char **argv, char **env)
{
	pipex->fd1 = open(argv[1], O_RDONLY);
	if (pipex->fd1 < 0)
	{
		close (pipex->fd2);
		perror(argv[1 + pipex->here_doc]);
		return (1);
	}
	return (0);
}