/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:53:00 by achansar          #+#    #+#             */
/*   Updated: 2023/03/01 17:23:59 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	get_here_doc(t_process *process, char *eof)
// {
// 	char	*line;

//     process->here_doc = 1;
// 	process->fd1 = open("here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0444);
// 	if (process->fd1 < 0)
// 		return (1);
// 	line = get_next_line(0);
// 	while (line)
// 	{
// 		write(process->fd1, line, ft_strlen(line));
// 		if (line)
// 			free(line);
// 		line = get_next_line(0);
// 		if (ft_strncmp(line, eof, ft_strlen(eof) + 1) == 0)
// 			break ;
// 	}
// 	free(line);
// 	close(process->fd1);
// 	return (0);
// }

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
	if (process->here_doc)
		process->fd1 = open("here_doc", O_CREAT, O_RDONLY);
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