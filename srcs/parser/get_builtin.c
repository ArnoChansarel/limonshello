/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:11:56 by achansar          #+#    #+#             */
/*   Updated: 2023/04/09 17:36:27 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_builtin_func(char *s, t_env *ev, int (**builtin)(struct s_cmd *))
{
	char	*temp;

	if (s)
	{
		temp = ft_strdup(s);
		expander(&temp, &ev);
		if (ft_strncmp(temp, "echo", ft_strlen(temp) + 1) == 0)
			*builtin = ft_echo;
		else if (ft_strncmp(temp, "cd", ft_strlen(temp) + 1) == 0)
			*builtin = ft_cd;
		else if (ft_strncmp(temp, "pwd", ft_strlen(temp) + 1) == 0)
			*builtin = ft_pwd;
		else if (ft_strncmp(temp, "export", ft_strlen(temp) + 1) == 0)
			*builtin = ft_export;
		else if (ft_strncmp(temp, "unset", ft_strlen(temp) + 1) == 0)
			*builtin = ft_unset;
		else if (ft_strncmp(temp, "env", ft_strlen(temp) + 1) == 0)
			*builtin = ft_env;
		else if (ft_strncmp(temp, "exit", ft_strlen(temp) + 1) == 0)
			*builtin = ft_exit;
		free(temp);
	}
}
