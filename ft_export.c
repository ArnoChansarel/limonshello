/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:58 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/21 14:25:14 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int list_cmp_key(t_cmd *cmd,char *str1, char *str2)
{
	t_env *tmp;
	
	tmp = cmd->head;
	while (tmp != 0)
		{
			if (strcmp(str1, tmp->key) == 0)
			{
				tmp->value = str2;
				tmp = cmd->head;
				return 1;
			}
			tmp = tmp->next;
		}
		tmp = cmd->head;
	return 0;
}

int	ft_export(t_cmd *cmd)
{
	char **tab;
	t_env *tmp;
	
	tmp = cmd->head;
	if (!cmd->tab || !cmd->tab[1])
		return 0;
	if (ft_strchr(cmd->tab[1],'=') != 0)
	{
		tab = ft_split(cmd->tab[1], '=');
		if (!list_cmp_key(cmd, tab[0], tab[1]))
			{
				if (ft_isalpha(tab[0][0]))
					push(cmd->head, 0, tab[0], tab[1]);
				else
					printf("bash: export: '%s': not a valid identifier\n",tab[0]);
			}
	}
	return 0;
}