/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:57:01 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/28 16:48:24 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_cmd *cmd)
{
	// char	buf[PATH_MAX + 1];

	// (void) *cmd;//            getcwd une fois puis
	// if (getcwd(buf, PATH_MAX))//   devrait etre dans la boucle
		printf("%s\n", cmd->cwd);//     et appeler depuis la main struct
// 	else
// 		printf("cd: error retrieving current directory: getcwd:\
// cannot access parent directories: No such file or directory\n");
	return (0);
}
/*
Et creer dans cette meme boucle un OLDPWD, a "" si !PWD
*/