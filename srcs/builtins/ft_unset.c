/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:59:12 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/23 14:44:03 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(t_cmd *cmd)
{
	t_env	*tmp;

	if (!cmd->cmd || !cmd->cmd[1])
		return (0);
	tmp = cmd->head;
	while (tmp->next != 0)
	{
		if (strcmp(cmd->cmd[1],tmp->next->key) == 0)
		{
			delete_node(tmp);
			break ;
		}
		tmp = tmp->next;
	}
	tmp = cmd->head;
	return (0);
}
