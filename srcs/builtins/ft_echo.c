/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:47 by ade-bast          #+#    #+#             */
/*   Updated: 2023/03/31 15:49:28 by achansar         ###   ########.fr       */
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
		if (i && cmd->cmd[i + 1])
			ft_putchar_fd(' ', fd);
		i++;
	}
	if (flag == 0)
		ft_putchar_fd('\n', fd);
	cmd->exit_status = 0;
	return (0);
}
