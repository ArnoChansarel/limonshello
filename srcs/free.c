/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:23:49 by achansar          #+#    #+#             */
/*   Updated: 2023/04/11 15:10:48 by achansar         ###   ########.fr       */
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

int	ft_free_all(t_data *data)
{
	ft_unlink(&data->lst);
	free_cmd_lst(data->lst);
	lexlst_clear(&data->lexer_lst);
	free(data->process);
	free(data->line);
	return (0);
}

int	ft_exit_failure(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}
