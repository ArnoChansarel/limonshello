/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:58 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/10 17:33:07 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	join_env_var(t_cmd *cmd, t_env *env, char *str1, char *str2)
{
	int		last;
	char	*temp;

	last = ft_strlen(str1) - 1;
	if (str1[last] == '+')
	{
		temp = strdup(env->value);
		free(env->value);
		env->value = ft_strjoin(temp, str2);
		free(temp);
		return (1);
	}
	else if (ft_isalnum(str1[last]))
		return (0);
	else
	{
		printf("LimonShello: export: '%s': not a valid identifier\n",
			cmd->cmd[1]);
		g_exit_value = 1;
		return (1);
	}
}

int	list_cmp_key(t_cmd *cmd, char *str1, char *str2)
{
	t_env	*tmp;

	(void) str2;
	tmp = cmd->head;
	while (tmp != 0)
	{
		if (ft_strncmp(str1, tmp->key, ft_strlen(tmp->key)) == 0)
		{
			if (join_env_var(cmd, tmp, str1, str2))
				return (1);
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

int	export_no_args(t_cmd *cmd)
{
	if (!cmd->cmd)
		return (0);
	if (!cmd->cmd[1])
	{
		ft_print_in_order(cmd);
		return (0);
	}
	return (1);
}

void	split_on_egal(t_cmd *cmd, int i)
{
	char	**res;

	res = ft_split(cmd->cmd[i], '=');
	if (!res[0] || !res[1])
		return ;
	if (!list_cmp_key(cmd, res[0], res[1]))
	{
		if (ft_isalpha(res[0][0]))
			push(cmd->head, 0, res[0], res[1]);
		else
			printf("LimonShello: export: '%s': not a valid identifier\n",
				res[0]);
	}
	ft_free_array(res);
}

int	ft_export(t_cmd *cmd)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = cmd->head;
	if (!export_no_args(cmd))
		return (0);
	while (cmd->cmd[i])
	{
		if (ft_strchr(cmd->cmd[i], '=') != 0)
			split_on_egal(cmd, i);
		else
		{
			printf("char = %s\n", cmd->cmd[i]);
			if (!notalphanum(cmd->cmd[i]))
			{
				printf("LimonShello: export: '%s': not a valid identifier\n",
					cmd->cmd[i]);
				g_exit_value = 1;
			}
		}
		i++;
	}
	return (0);
}
