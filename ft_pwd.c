/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:57:01 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/21 16:45:48 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_cmd *cmd)
{
	if (getcwd(cmd->buf, PATH_MAX))
		printf("%s\n", cmd->buf);
	else
		printf("ERROR\n");
	return (0);
}
