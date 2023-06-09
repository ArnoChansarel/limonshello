/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:58 by ade-bast          #+#    #+#             */
/*   Updated: 2023/05/11 13:21:47 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	join_env_var(t_cmd *cmd, t_env *env, char *str1, char *str2)
{
	int		last;
	char	*temp;

	last = ft_strlen(str1) - 1;
	if (str1[last] == '+' && str1[last - 1] != '+')
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
	int		size;
	t_env	*tmp;

	tmp = cmd->head;
	while (tmp != 0)
	{
		size = ft_strlen(tmp->key);
		if ((ft_strncmp(str1, tmp->key, size + 1) == 0)
			|| (ft_strncmp(str1, tmp->key, size) == 0 && str1[size] == '+'))
		{
			if (join_env_var(cmd, tmp, str1, str2))
				return (1);
			free(tmp->value);
			tmp->value = ft_strdup(str2);
			expander(&tmp->value, &cmd->head);
			tmp = cmd->head;
			return (1);
		}
		tmp = tmp->next;
	}
	clean_newvar_plus(str1);
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
	int		k;
	int		j;

	k = 0;
	res = ft_split(cmd->cmd[i], '=');
	if (!res[0] || !res[1])
	{
		ft_free_array(res);
		return ;
	}
	j = ft_strlen(res[0]);
	while (k < j - 1)
	{
		if (!ft_isalnum_(res[0][k++]))
			return (print_error(res));
	}
	if (!list_cmp_key(cmd, res[0], res[1]))
	{
		if (!ft_isalpha_(res[0][0]))
			push(&cmd->head, 0, res[0], res[1]);
		else
			return (print_error(res));
	}
	ft_free_array(res);
}

int	ft_export(t_cmd *cmd)
{
	int		i;

	i = 0;
	if (!cmd->head)
		return (0);
	if (!export_no_args(cmd))
		return (0);
	while (cmd->cmd[i])
	{
		if ((ft_strchr(cmd->cmd[i], '=') != 0))
			split_on_egal(cmd, i);
		else
		{
			if (!notalphanum_(cmd->cmd[i]))
			{
				printf("numero 2\n");
				printf("LimonShello: export: '%s': not a valid identifier\n",
					cmd->cmd[i]);
				g_exit_value = 1;
			}
		}
		i++;
	}
	return (0);
}
