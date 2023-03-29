/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:55 by ade-bast          #+#    #+#             */
/*   Updated: 2023/03/29 15:42:01 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	err_(char *str)
{
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argment required\n", 2);
}

int	static	check_arg(t_cmd *cmd)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (cmd->cmd[1][i] == '-' || cmd->cmd[1][i] == '+')
	{
		++i;
		++sign;
	}
	while (cmd->cmd[1][i])
	{			
		if ((cmd->cmd[1][i] < '0' || cmd->cmd[1][i] > '9'))
			return (1);
		++i;
	}
	if (sign > 1)
		return (sign);
	else
		return (0);
}

int	ft_exit(t_cmd *cmd)
{
	if (!cmd->cmd[0])
		exit(EXIT_FAILURE);
	if (!cmd->cmd[1])
		exit(EXIT_SUCCESS);
	if (cmd->cmd[1])
	{
		if (check_arg(cmd) == 1)
			{
				cmd->exit_status = 255;
				err_(cmd->cmd[1]);
				exit(cmd->exit_status);
			}
		else
			cmd->exit_status = ft_atoi(cmd->cmd[1]);
	}
	if (cmd->cmd[1] && cmd->cmd[2])
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		if (ft_isdigit(cmd->cmd[2][0]))
		{
			cmd->exit_status = 1;
			return (0);
		}
		cmd->exit_status = 1;
		exit(cmd->exit_status);
	}

	if ((cmd->exit_status >= 255) && cmd->cmd[1])
	{
		ft_putstr_fd("exit\n", 2);
		cmd->exit_status = ft_atoi(cmd->cmd[1]) - ((ft_atoi(cmd->cmd[1]) % 256) * 256);
		exit(cmd->exit_status);
	}
	if ((cmd->exit_status <= 255) && cmd->cmd[1])
	{
		ft_putstr_fd("exit\n", 2);
		cmd->exit_status = ft_atoi(cmd->cmd[1]) + ((ft_atoi(cmd->cmd[1]) % 256) * 256);
		exit(cmd->exit_status);
	}
	printf("exit\n");
	if (cmd->exit_status < 0)
		cmd->exit_status = cmd->exit_status + 256;
	if (cmd->exit_status < 0)
		cmd->exit_status = 256 - (cmd->exit_status * -1);
	exit(cmd->exit_status);
}
