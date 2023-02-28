/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:47 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/27 15:07:29 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(t_cmd *cmd)
{
	int	i;
	int	j;
	int	flag;
	int	fd;

	fd = 1;
	i = 1;
	flag = 0;
	j = 0;
	while (cmd->cmd[i] && cmd->cmd[i][0] == '-' && cmd->cmd[i][1] == 'n')
	{
		i++;
		flag++;
	}
	while (cmd->cmd[i])
	{
		ft_putstr_fd(cmd->cmd[i], fd);
		if (i++)
			ft_putchar_fd(' ', fd);
	}
	if (flag == 0)
		ft_putchar_fd('\n', fd);
	cmd->exit_status = 0;
	return (0);
}
