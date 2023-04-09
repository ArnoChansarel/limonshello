/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:12:18 by achansar          #+#    #+#             */
/*   Updated: 2023/04/09 17:43:58 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (0);
}

static char	*check_cmd(t_process *process, char **cmd, char **cmd_paths)
{
	int		i;
	char	*cmd_path;
	char	*join;

	i = 0;
	(void)process;
	while (cmd_paths[i])
	{
		join = ft_strjoin(cmd_paths[i], "/");
		if (!join)
			return (NULL);
		cmd_path = ft_strjoin(join, cmd[0]);
		free(join);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*getourenv(char *key, t_env *list)
{
	t_env	*head;

	head = list;
	while (head)
	{
		if (ft_strncmp(key, head->key, 4) == 0)
			return (head->value);
		head = head->next;
	}
	return (NULL);
}

char	*get_cmd(t_process *process, char **cmd, t_env *ev)
{
	char	*cmd_rtr;
	char	**cmd_paths;

	cmd_rtr = NULL;
	if (access(cmd[0], F_OK) == 0)
		return (cmd[0]);
	process->env_path = getourenv("PATH", ev);
	if (!process->env_path)
		return (NULL);
	cmd_paths = ft_split(process->env_path, ':');
	if (!cmd_paths)
	{
		free_array(cmd_paths);
		// return (ft_close(process));//         a garder
	}
	cmd_rtr = check_cmd(process, cmd, cmd_paths);
	free_array(cmd_paths);
	if (!cmd_rtr)
		return (NULL);
	// printf("path found : %s\n", cmd_rtr);
	return (cmd_rtr);
}
