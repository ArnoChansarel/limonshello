/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:11:56 by achansar          #+#    #+#             */
/*   Updated: 2023/04/09 13:22:19 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    get_builtin_function(char *str, t_env *env, int (**builtin)(struct s_cmd *))
{
	char *temp;

	temp = ft_strdup(str);
	expander(&temp, &env);
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
