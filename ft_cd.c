/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:34 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/21 16:43:27 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	static	cd_exec(t_cmd *cmd, char *home, char *directory,
	char *pwd, t_env *tmp)
{
	if (!cmd->tab[1])
		cd_home(home, pwd, cmd);
	else
	{
		if (cmd->tab[1][0] == '.' && !cmd->tab[1][1])
			cd_point(cmd, pwd);
		else if (cmd->tab[1][0] == '-' && !cmd->tab[1][1])
			cd_minus(cmd, tmp);
		else if (ft_strncmp(cmd->tab[1], "/", 1))
			cd_go_to_directory(directory, pwd, cmd);
		else
			cd_slash(cmd, pwd);	
	}
}

int	ft_cd(t_cmd *cmd)
{
	char	*home;
	char	*directory;
	char	*pwd;
	char	*buf;
	t_env	*tmp;

	tmp = (t_env *) malloc(sizeof(t_env));
	home = malloc(sizeof(char) * PATH_MAX + 1);
	directory = malloc(sizeof(char) * PATH_MAX + 1);
	buf = malloc(sizeof(char) * PATH_MAX + 1);
	pwd = malloc(sizeof(char) * PATH_MAX + 1);

	if (!home || !buf || !directory || !pwd || !tmp)			
		return (0);
	pwd = getcwd(buf, PATH_MAX);
	home = list_return_value_from_key(cmd, "HOME");
	cd_exec(cmd, home, directory, pwd, tmp);
	return (0);
}
