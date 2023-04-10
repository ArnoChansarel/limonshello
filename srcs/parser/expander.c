/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:24:39 by achansar          #+#    #+#             */
/*   Updated: 2023/04/07 11:59:28 by ade-bast         ###   ########.fr       */
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

int	find_var_and_replace(t_cmd *cmd, t_env **env, int idx, int i)
{
	int		size;
	t_env	*head;

	size = 0;
	head = *env;
	size = get_var_size(&cmd->cmd[idx][i]);
	while (head)
	{
		if (ft_strncmp2(&cmd->cmd[idx][i + 1], head->key, size) == 0)
		{
			cmd->cmd[idx] = replace_var(cmd->cmd[idx], head->value, size, i);
			return (1);
		}
		head = head->next;
	}
	cmd->cmd[idx] = replace_var(cmd->cmd[idx], "", size, i);
	return (0);
}

int	lookfor_var(t_cmd *cmd, t_env **env, int idx, int size)
{
	int	i;

	(void)size;
	i = 0;
	while (cmd->cmd[idx][i])
	{
		if (cmd->cmd[idx][i] == '$')
		{
			if (cmd->cmd[idx][i + 1] == '?')
			{
				size = get_var_size(&cmd->cmd[idx][i]);
				cmd->cmd[idx] = replace_var(cmd->cmd[idx], ft_itoa(g_exit_value), size + 1, i);
				continue ;
			}
			if (ft_isalnum(cmd->cmd[idx][i + 1]) == 0)
			{
				i++;
				continue ;
			}
			if (find_var_and_replace(cmd, env, idx, i) == 0)
				continue ;
		}
		i++;
	}
	return (0);
}




// char *quotes_rd(char *rd)
// {
// 	char *rd;
	
// }












// char	*expand_redirection(char *rd)
// {
// 	int i;
// 	char *rtr;

// 	i = 0;
// 	while(rd[i])
// 	{
// 		if (rd[i] == '\"' || rd[i] == '\'')
// 		{
// 			rtr = quotes_rd();
// 			free(rd);
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (rd);
// }

int expander(t_cmd **cmd_lst, t_env **env)
{
	int		i;
	t_cmd 	*head;

	head = *cmd_lst;
	while (head)
	{
		i = 0;
		while (head->cmd[i])
		{			
			if (head->cmd[i][0] == '\'' || head->cmd[i][0] == '\"')
				expand_quotes(head, env, i);
			else
				lookfor_var(head, env, i, 0);
			i++;
		}
		// if (head->rd_in)
		// {
		// 	i = is_token(head->rd_in);
		// 	if (head->rd_in[i] == '\"' || head->rd_in[i] == '\'')
				
		// }
		head = head->next;
	}
	return (0);
}
