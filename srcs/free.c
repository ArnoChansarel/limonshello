/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:23:49 by achansar          #+#    #+#             */
/*   Updated: 2023/05/01 13:10:47 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_cmd_lst(t_cmd *lst)
{
	int		i;
	t_cmd	*head;

	head = NULL;
	while (lst)
	{
		i = 0;
		head = lst;
		while (head->cmd[i])
			free(head->cmd[i++]);
		free(head->cmd);
		if (head->rd_in)
			free(head->rd_in);
		if (head->rd_out)
			free(head->rd_out);
		lst = lst->next;
		free(head);
	}
}

int	ft_unlink(t_cmd **cmd)
{
	char	*index;
	char	*name;
	t_cmd	*head;

	head = *cmd;
	while (head)
	{
		index = ft_itoa(head->index);
		name = ft_strjoin("here_doc", index);
		unlink(name);
		free(name);
		free(index);
		head = head->next;
	}
	return (0);
}

void	update_pwd(t_data *data, char *cwd)
{
	t_env	*tmp;

	free(data->cwd);
	data->cwd = ft_strdup(cwd);
	tmp = data->env;
	while (tmp && tmp->next != 0)
	{
		if (ft_strncmp(tmp->key, "PWD", ft_strlen(tmp->key)) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(cwd);
			break ;
		}
		tmp = tmp->next;
	}
	free(cwd);
}

int	ft_free_all(t_data *data)
{
	char	*temp;

	temp = malloc(sizeof(char) * (PATH_MAX + 1));
	getcwd(temp, PATH_MAX);
	if (temp)
		update_pwd(data, temp);
	ft_unlink(&data->lst);
	free_cmd_lst(data->lst);
	lexlst_clear(&data->lexer_lst);
	free(data->process);
	return (0);
}

int	ft_exit_failure(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
