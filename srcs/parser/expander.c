/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:24:39 by achansar          #+#    #+#             */
/*   Updated: 2023/04/11 15:53:36 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	expand_error_var(char **cmd, int i)
{
	int		size;
	char	*index;

	index = ft_itoa(g_exit_value);
	size = get_var_size(&cmd[0][i]);
	*cmd = replace_var(*cmd, index, size + 1, i);
	free(index);
	return (0);
}

int	expander(char **cmd, t_env **env)
{
	int	i;

	i = 0;
	if (*cmd)
	{
		lookfor_var(cmd, env, -1);
		while (cmd[0][i])
		{
			if (cmd[0][i] == '\"' || cmd[0][i] == '\'')
			{
				expand_quotes(cmd);
				break ;
			}
			i++;
		}
	}
	return (0);
}

int	expand_redirections(char **rd, t_env **env)
{
	int		i;
	char	**rtr;

	rtr = ft_split(*rd, ' ');
	if (ft_strncmp(*rd, "<<", 2))
		expander(&rtr[1], env);
	free(*rd);
	*rd = ft_strjoin(rtr[0], rtr[1]);
	i = 0;
	while (rtr[i])
		free(rtr[i++]);
	free(rtr);
	return (0);
}
