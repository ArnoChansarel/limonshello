/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:36:18 by achansar          #+#    #+#             */
/*   Updated: 2023/04/06 14:47:19 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_var_size(char *str)
{
	int	s;
	
	s = 0;
	while (str[s] && ft_isalnum(str[s + 1]) && str[s] != '\"')
		s++;
	return (s + 1);
}

int	ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && i < n - 1)
		i++;
	if ((s1[i] == '\"' || ft_isalnum(s1[i]) == 0 || !s1[i]) && !s2[i])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int expand_quotes(t_cmd *cmd, t_env **env, int idx)
{
	int i;
	char *str;
	int len;

	i = 0;
	if (cmd->cmd[idx][0] == '\"')
	    lookfor_var(cmd, env, idx, 0);
	len = ft_strlen(cmd->cmd[idx]);
	str = malloc(sizeof(char *) * len - 2);
	while (i <= len - 3)
	{
		str[i] = cmd->cmd[idx][i + 1];
		i++;
	}
	str[i] = '\0';
	free(cmd->cmd[idx]);
	cmd->cmd[idx] = str;
	return (0);
}

