/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:58 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/08 13:23:20 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	list_cmp_key(t_cmd *cmd, char *str1, char *str2)
{
	t_env	*tmp;

	(void) str2;
	tmp = cmd->head;
	while (tmp != 0)
	{
		// printf("yo\n\n\n");
		if (ft_strncmp(str1, tmp->key, ft_strlen(tmp->key)) == 0)
		{
			printf("Attention\n\n\n");
			free(tmp->value);
			printf("el1 = %sispace - el2 = %sispace\n", str1, str2);
			tmp->value = ft_strdup(str2);
			printf("DIN\n\n\n");//" "; //
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
	if (!cmd->cmd)
		return (0);
	if (!cmd->cmd[1])
	{
		ft_print_in_order(cmd);
		return (0);		
	}
	if (ft_strchr(cmd->cmd[1], '=') != 0)
	{
		// printf("cdm = %sispace\n", cmd->cmd[1]);
		res = ft_split(cmd->cmd[1], '=');
		// printf("el1 = %sispace - el2 = %sispace\n", res[0], res[1]);
		if (!res[0] || !res[1])
			return (0);
		if (!list_cmp_key(cmd, res[0], res[1]))
		{
			if (ft_isalpha(res[0][0]))
				push(cmd->head, 0, res[0], res[1]);
			else
				printf("bash: export: '%s': not a valid identifier\n", res[0]);
		}
		ft_free_array(res);
	}
	return (0);
}
