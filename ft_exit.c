/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:55 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/21 16:42:10 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	static	check_arg(t_cmd *cmd)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (cmd->tab[1][i] == '-' || cmd->tab[1][i] == '+')
	{
		i++;
		sign++;
	}
	while (cmd->tab[1][i])
	{			
		if (!ft_isdigit(cmd->tab[1][i]))
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
	if (cmd->tab[1])
	{
		if (check_arg(cmd))
			cmd->exit_status = 255;
		else
			cmd->exit_status = ft_atoi(cmd->tab[1]);
	}
	if (cmd->exit_status >= 255 && cmd->tab[1])
	{
		ft_putstr_fd("exit", 2);
		cmd->exit_status = 255;
	}
	if (cmd->tab[1] && cmd->tab[2])
	{
		ft_putstr_fd("Too many arguments", 2);
		cmd->exit_status = 1;
	}
	exit(cmd->exit_status);
}
//! GESTION NEGATIF
//! ft_putstr pour les erreurs en 3 coups