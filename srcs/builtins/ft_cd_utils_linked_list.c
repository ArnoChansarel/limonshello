/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils_linked_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:38:51 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/04 10:24:39 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*list_return_value_from_key(t_cmd *cmd, char *str1)
{
	t_env	*tmp;

	tmp = cmd->head;
	while (tmp != 0)
	{
		if (!ft_strncmp(str1, tmp->key, ft_strlen(tmp->key)))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (0);
}

t_env	*is_pwd_set(t_cmd *cmd)
{
	t_env	*tmp;

	tmp = cmd->head;
	while (tmp != 0)
	{
		if (!ft_strncmp(tmp->key, "OLDPWD", ft_strlen(tmp->key)))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	update_old_pwd(t_cmd *cmd, char *str)
{
	t_env	*tmp;

	tmp = cmd->head;
	while (tmp != 0)
	{
		if (!ft_strncmp(tmp->key, "OLDPWD", ft_strlen(tmp->key)))
		{
			free(tmp->value);
			tmp->value = ft_strdup(str);
			if (!tmp->value)
				exit(EXIT_FAILURE);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}