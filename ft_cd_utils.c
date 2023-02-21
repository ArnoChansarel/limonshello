/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:43:51 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/21 14:25:14 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_home(char *home, char *pwd, t_cmd *cmd)
{
	if(!opendir(home))
		ft_putstr_fd("minishell: cd: No such file or directory\n",2);
	else
	{
		chdir(home);
		if (!is_pwd_set(cmd))
			push(cmd->head, 1, "OLDPWD", pwd);
		else
			update_old_pwd(cmd, pwd);
	}
}

void	cd_point(t_cmd *cmd, char *pwd)
{
	if (!is_pwd_set(cmd))
		push(cmd->head, 1, "OLDPWD", pwd);
	else
		update_old_pwd(cmd, pwd);
}

void	cd_minus(t_cmd *cmd, t_env *tmp)
{
	tmp = is_pwd_set(cmd);
	if (tmp)
	{
		chdir(tmp->value);
		printf("%s\n", tmp->value);
	}
	else
		ft_putstr_fd("minishell: cd: OLDPWD not set\n",2);
}

void	cd_go_to_directory(char *directory, char *pwd, t_cmd *cmd)
{
	strcpy(directory, ft_strjoin(pwd, ft_strjoin("/", cmd->tab[1])));
	// ft_memcpy(directory, ft_strjoin(pwd, ft_strjoin("/", cmd->tab[1])),
	// ft_strlen(ft_strjoin(pwd, ft_strjoin("/", cmd->tab[1]))));
	if (!opendir(directory))
		ft_putstr_fd("No such file or directory\n",2);
	else
	{
		chdir(directory);
		if(!update_old_pwd(cmd, pwd))
			push(cmd->head, 1, "OLDPWD", pwd);	
	}
}

void	cd_slash(t_cmd *cmd, char *pwd)
{
	if ((!opendir(cmd->tab[1])))
		ft_putstr_fd("no such file or directory\n",2);
	else
	{
		chdir(cmd->tab[1]);
		if(!update_old_pwd(cmd, pwd))
			push(cmd->head, 1, "OLDPWD", pwd);
	}			
}