/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:43:51 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/28 17:11:48 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd_home(char *home, char *pwd, t_cmd *cmd)
{
	DIR	*dir;

	if (!home[0])
	{
		ft_putstr_fd("LimonShello: cd: HOME not set\n", 2);
		return ;
	}
	dir = opendir(home);
	if (!dir)
	{
		ft_putstr_fd("LimonShello: cd: ", 2);
		ft_putstr_fd(home, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return ;
	}
	else
	{
		chdir(home);
		if (!is_pwd_set(cmd))
			push(&cmd->head, 1, "OLDPWD", pwd);
		else
			update_old_pwd(cmd, pwd);
	}
	closedir(dir);
}

void	cd_point(t_cmd *cmd, char *pwd)
{
	if (!is_pwd_set(cmd))
		push(&cmd->head, 1, "OLDPWD", pwd);
	else
		update_old_pwd(cmd, pwd);
}

void	cd_minus(t_cmd *cmd)
{
	t_env	*tmp;

	tmp = is_pwd_set(cmd);
	if (tmp)
	{
		chdir(tmp->value);
		printf("%s\n", tmp->value);
	}
	else
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
}

void	cd_go_to_directory(char *directory, char *pwd, t_cmd *cmd)
{
	char	*tmp_join;
	char	*tmp_join_bis;
	DIR		*dir;

	tmp_join = ft_strjoin("/", cmd->cmd[1]);
	tmp_join_bis = ft_strjoin(pwd, tmp_join);
	ft_memcpy(directory, tmp_join_bis, ft_strlen(tmp_join_bis) + 1);
	dir = opendir(directory);
	if (!dir)
	{
		ft_putstr_fd("LimonShello: cd: ", 2);
		ft_putstr_fd(cmd->cmd[1], 2);
		ft_putstr_fd(": Not a directory\n", 2);
		return ;
	}
	else
	{
		chdir(directory);
		if (!update_old_pwd(cmd, pwd))//               ou est update_pwd() ?
			push(&cmd->head, 1, "OLDPWD", pwd);
	}
	closedir(dir);
	free(tmp_join);
	free(tmp_join_bis);
}

void	cd_slash(t_cmd *cmd, char *pwd)
{
	DIR	*dir;

	dir = opendir(cmd->cmd[1]);
	if ((!dir))
	{
		ft_putstr_fd("LimonShello: cd: ", 2);
		ft_putstr_fd(cmd->cmd[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return ;
	}
	else
	{
		chdir(cmd->cmd[1]);
		if (!update_old_pwd(cmd, pwd))
			push(&cmd->head, 1, "OLDPWD", pwd);
	}
	closedir(dir);
}
