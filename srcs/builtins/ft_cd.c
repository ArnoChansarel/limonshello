/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:34 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/10 18:12:56 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	static	cd_exec(t_cmd *cmd, char *home, char *directory,
	char *pwd)
{
	if (!cmd->cmd[1])
		cd_home(home, pwd, cmd);
	else if (cmd->cmd[1][0] == '.' && !cmd->cmd[1][1])
		cd_point(cmd, pwd);
	else if (cmd->cmd[1][0] == '-' && !cmd->cmd[1][1])
		cd_minus(cmd);
	else if (ft_strncmp(cmd->cmd[1], "/", 1))
		cd_go_to_directory(directory, pwd, cmd);
	else
		cd_slash(cmd, pwd);
}

int	ft_cd(t_cmd *cmd)
{
	char	home[PATH_MAX + 1];
	char	directory[PATH_MAX + 1];
	char	pwd[PATH_MAX + 1];

	getcwd(pwd, PATH_MAX);
	ft_memcpy(home, list_return_value_from_key(cmd, "HOME"),
		ft_strlen(list_return_value_from_key(cmd, "HOME")) + 1);
	cd_exec(cmd, home, directory, pwd);
	return (0);
}
