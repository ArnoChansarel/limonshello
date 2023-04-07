/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:24:39 by achansar          #+#    #+#             */
/*   Updated: 2023/04/07 13:12:21 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *replace_var(char *str, char *env, int size, int j)
{
   	char 	*rtr;
	char	*temp;
   	int 	i;

	temp = str;
	i = ft_strlen(str) - size - 1 + ft_strlen(env);
	if (i <= 0)
		i = 1;
   	rtr = malloc(sizeof(char *) * i + 1);
	if (!rtr)
		return (rtr);
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
	t_env  *head;

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

int lookfor_var(char **cmd, t_env **env, int size)
{
	int i;

	(void)size;
	i = 0;
	while(cmd[0][i])
	{
		if (cmd[0][i] == '$')
		{
			if (cmd[0][i + 1] == '?')
			{
				size = get_var_size(&cmd[0][i]);
				*cmd = replace_var(*cmd, ft_itoa(g_exit_value), size + 1, i);
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

int expander(char **cmd, t_env **env)
{		
	if (cmd[0][0] == '\'' || cmd[0][0] == '\"')
		expand_quotes(cmd, env);
	else
		lookfor_var(cmd, env, 0);
	return (0);
}

int send_to_expander(t_cmd **cmd_lst)
{
	int i;
	t_cmd *head;

	head = *cmd_lst;
	while (head)
	{
		i = 0;
		while (head->cmd[i])
			expander(&head->cmd[i++], &head->head);
		/*
		redirections
		*/
		head = head->next;
	}
	return (0);
}
