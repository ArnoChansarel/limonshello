/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:55 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/23 14:41:16 by ade-bast         ###   ########.fr       */
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
		i++;
		sign++;
	}
	while (cmd->cmd[1][i])
	{			
		if (!ft_isdigit(cmd->cmd[1][i]))
			return (1);
		i++;
	}
	if (sign > 1)
		return (0);
	else
		return (sign);
}

int	ft_exit(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->cmd[1])
	{
		if (check_arg(cmd) == 1)
			err_(cmd->cmd[1]);
		else if (check_arg(cmd) > 1)
			cmd->exit_status = 255;
		else
			cmd->exit_status = ft_atoi(cmd->cmd[1]);
	}
	if (cmd->exit_status >= 255 && cmd->cmd[1])
	{
		ft_putstr_fd("exit\n", 2);
		cmd->exit_status = 255;
	}
	if (cmd->cmd[1] && cmd->cmd[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		cmd->exit_status = 1;
	}
	exit(cmd->exit_status);
}
//! GESTION NEGATIF
//! ft_putstr pour les erreurs en 3 coups