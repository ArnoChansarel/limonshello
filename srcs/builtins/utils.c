/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:52:21 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/28 14:07:56 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (!dst && !src && n)
		return (0);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

void buitins_exec(int i, t_cmd *cmd)
{
	if (i == ECHO)
		ft_echo(cmd);
	if (i == CD)
		ft_cd(cmd);
	if (i == PWD)
		ft_pwd(cmd);
	if (i == EXPORT)
		ft_export(cmd);
	if (i == UNSET)
		ft_unset(cmd);
	if (i == ENV)
		ft_env(cmd);
	if (i == EXIT)
		ft_exit(cmd);
	else
		return ;
}

// int	get_cmd(char *str)
// {
//     if (ft_strncmp(str, "echo", ft_strlen(str) + 1) == 0)
//         return(ECHO);
//     else if (ft_strncmp(str, "cd", ft_strlen(str) + 1) == 0)
//         return(CD);
//     else if (ft_strncmp(str, "pwd", ft_strlen(str) + 1) == 0)
//         return(PWD);
//     else if (ft_strncmp(str, "export", ft_strlen(str) + 1) == 0)
//         return(EXPORT);
//     else if (ft_strncmp(str, "unset", ft_strlen(str) + 1) == 0)
//         return(UNSET);
//     else if (ft_strncmp(str, "env", ft_strlen(str) + 1) == 0)
//         return(ENV);
//     else if (ft_strncmp(str, "exit", ft_strlen(str) + 1) == 0)
//         return (EXIT);
//     return 0;
// }