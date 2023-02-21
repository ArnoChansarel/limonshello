/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:59:12 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/21 14:25:14 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_cmd *cmd)
{
	if (!cmd->tab || !cmd->tab[1])
		return 0;
	t_env *tmp;
	tmp = cmd->head;
	while (tmp->next != 0)
	{
		if (strcmp(cmd->tab[1],tmp->next->key) == 0)
		{
			delete_node(tmp);
			break;
		}
		tmp = tmp->next;
	}
	tmp = cmd->head;
	return 0;
}