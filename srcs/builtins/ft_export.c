/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:58 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/23 15:26:07 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	list_cmp_key(t_cmd *cmd, char *str1, char *str2)
{
	t_env	*tmp;

	tmp = cmd->head;
	while (tmp != 0)
	{
		if (strcmp(str1, tmp->key) == 0)
		{
			tmp->value = str2;
			tmp = cmd->head;
			return (1);
		}
		tmp = tmp->next;
	}
		tmp = cmd->head;
	return (0);
}

int	ft_export(t_cmd *cmd)
{
	char	**res;
	t_env	*tmp;

	tmp = cmd->head;
	if (!cmd->cmd || !cmd->cmd[1])
		return (0);
	if (ft_strchr(cmd->cmd[1], '=') != 0)
	{
		res = ft_split(cmd->cmd[1], '=');
		if (!list_cmp_key(cmd, res[0], res[1]))
		{
			if (ft_isalpha(res[0][0]))
				push(cmd->head, 0, res[0], res[1]);
			else
				printf("bash: export: '%s': not a valid identifier\n", res[0]);
		}
	}
	return (0);
}
