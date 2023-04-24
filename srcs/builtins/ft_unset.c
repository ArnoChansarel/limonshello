/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:59:12 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/24 16:34:43 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(t_cmd *cmd)
{
	t_env	*tmp;
	int		i;

	i = 1;
	if (!cmd->cmd || !cmd->cmd[1])
		return (0);
	tmp = cmd->head;
	while (cmd->cmd[i])
	{
		while (tmp && tmp->next != 0)
		{
			if (ft_strncmp(cmd->cmd[i], tmp->next->key,
					ft_strlen(tmp->next->key)) == 0)
			{
				delete_node(tmp);
				tmp = cmd->head;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}
