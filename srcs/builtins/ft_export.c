/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:58 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/06 15:00:51 by ade-bast         ###   ########.fr       */
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
		if (ft_strncmp(str1, tmp->key, ft_strlen(tmp->key)) == 0)
		{
			free(tmp->value);
			tmp->value = ft_strdup(str2);
			tmp = cmd->head;
			return (1);
		}
		tmp = tmp->next;
	}
		tmp = cmd->head;
	return (0);
}

int	notalphanum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_export(t_cmd *cmd)
{
	char	**res;
	t_env	*tmp;
	int		i;
	
	i = 0;
	tmp = cmd->head;
	if (!cmd->cmd)
		return (0);
	if (!cmd->cmd[1])
	{
		ft_print_in_order(cmd);
		return (0);
	}
	while (cmd->cmd[i])
	{
	if (ft_strchr(cmd->cmd[i], '=') != 0)
	{
		res = ft_split(cmd->cmd[i], '=');
		if (!res[0] || !res[1])
			return (0);
		if (!list_cmp_key(cmd, res[0], res[1]))
		{
			if (ft_isalpha(res[0][0]))
				push(cmd->head, 0, res[0], res[1]);
			else
				printf("LimonShello: export: '%s': not a valid identifier\n", res[0]);
		}
		ft_free_array(res);
	}
	else
	{
		if (!notalphanum(cmd->cmd[i]))
			{
				printf("LimonShello: export: '%s': not a valid identifier\n", cmd->cmd[i]);
				g_exit_value = 1;
			}
	}
		i++;
	}
	return (0);
}
