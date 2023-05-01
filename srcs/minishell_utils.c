/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:40:04 by achansar          #+#    #+#             */
/*   Updated: 2023/04/28 16:41:22 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	init_process(t_data *data)
{
	data->process = malloc(sizeof(t_process));
	if (!data->process)
		ft_exit_failure("malloc");
	data->process->cmd_paths = NULL;
	data->process->env_path = NULL;
	data->process->pipes_array = NULL;
	data->process->fd1 = -1;
	data->process->fd2 = -1;
	data->process->here_doc = 0;
	data->process->pid = -1;
	return (0);
}

int	error_msg(char c)
{
	printf("LimonShello: syntax error near unexpected token `%c'\n", c);
	return (1);
}

int	init_data(t_data *data, char **envp)
{
	char	*cwd;

	cwd = malloc(sizeof(char) * (PATH_MAX + 1));
	data->process = NULL;
	data->lst = NULL;
	data->line = NULL;
	data->pipes = 0;
	data->env = build_env_list(envp);
	data->cwd = getcwd(cwd, PATH_MAX);
	return (0);
}
