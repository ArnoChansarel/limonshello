/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:55 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/05 14:37:10 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	static	exit_no_args(t_cmd *cmd)
{
	if (!cmd->cmd[1])
	{
		ft_putstr_fd("exit\n", 1);
		exit(g_exit_value);
	}
}

int static	exit_part(t_cmd *cmd)
{
	if (cmd->cmd[1])
	{
		if (check_arg(cmd) == 1)
		{
			g_exit_value = 255;
			err_(cmd->cmd[1]);
			exit(g_exit_value);
		}
		else
			g_exit_value = ft_atoi(cmd->cmd[1]);
	}
	if (cmd->cmd[1] && cmd->cmd[2])
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		if (ft_isdigit(cmd->cmd[2][0]))
		{
			g_exit_value = 1;
			return (0);
		}
		g_exit_value = 1;
		exit(g_exit_value);
	}
	return (0);
}

void	exit_high_values(t_cmd *cmd)
{
	if ((g_exit_value >= 255) && cmd->cmd[1])
	{
		ft_putstr_fd("exit\n", 1);
		g_exit_value = ft_atoi(cmd->cmd[1])
			- ((ft_atoi(cmd->cmd[1]) % 256) * 256);
		exit(g_exit_value);
	}
	if ((g_exit_value <= 255) && cmd->cmd[1])
	{
		ft_putstr_fd("exit\n", 1);
		g_exit_value = ft_atoi(cmd->cmd[1])
			+ ((ft_atoi(cmd->cmd[1]) % 256) * 256);
		exit(g_exit_value);
	}
}

int	ft_exit(t_cmd *cmd)
{
	exit_no_args(cmd);
	exit_part(cmd);
	exit_high_values(cmd);
	printf("exit\n");
	if (g_exit_value < 0)
		g_exit_value = g_exit_value + 256;
	if (g_exit_value < 0)
		g_exit_value = 256 - (g_exit_value * -1);
	exit(g_exit_value);
}
