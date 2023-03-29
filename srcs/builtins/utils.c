/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:52:21 by ade-bast          #+#    #+#             */
/*   Updated: 2023/03/03 15:54:54 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	ft_free_array(char **tobefreed)
{
	int	i;

	i = 0;
	while (tobefreed[i])
	{
		free(tobefreed[i]);
		i++;
	}
	free(tobefreed);
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