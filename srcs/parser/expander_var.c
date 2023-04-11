/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:38:04 by achansar          #+#    #+#             */
/*   Updated: 2023/04/11 15:38:39 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*replace_var(char *str, char *env, int size, int j)
{
	char	*rtr;
	char	*temp;
	int		i;

	temp = str;
	i = ft_strlen(str) - size - 1 + ft_strlen(env);
	if (i <= 0)
		i = 1;
	rtr = malloc(sizeof(char *) * i + 1);
	if (!rtr)
		ft_exit_failure("malloc");
	i = 0;
	while (*str && i < j)
		rtr[i++] = *str++;
	while (*env)
		rtr[i++] = *env++;
	str += size;
	while (*str)
		rtr[i++] = *str++;
	rtr[i] = '\0';
	free(temp);
	return (rtr);
}

int	find_var_and_replace(char **cmd, t_env **env, int i)
{
	int		size;
	t_env	*head;

	size = 0;
	head = *env;
	size = get_var_size(&cmd[0][i]);
	while (head)
	{
		if (ft_strncmp2(&cmd[0][i + 1], head->key, size) == 0)
		{
			*cmd = replace_var(*cmd, head->value, size, i);
			return (1);
		}
		head = head->next;
	}
	*cmd = replace_var(*cmd, "", size, i);
	return (0);
}

int	lookfor_var(char **cmd, t_env **env, int dq)
{
	int		i;

	i = 0;
	while (cmd[0][i])
	{
		i += skip_quotes(&cmd[0][i], &dq);
		if (cmd[0][i] == '$')
		{
			if (cmd[0][i + 1] == '?')
			{
				expand_error_var(cmd, i);
				continue ;
			}
			if (ft_isalnum(cmd[0][i + 1]) == 0)
			{
				i++;
				continue ;
			}
			if (find_var_and_replace(cmd, env, i) == 0)
				continue ;
		}
		i++;
	}
	return (0);
}
