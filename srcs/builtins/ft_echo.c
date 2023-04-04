/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:30:07 by achansar          #+#    #+#             */
/*   Updated: 2023/04/03 15:35:21 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_new_line(t_cmd *cmd)
{
	int		i;
	int		j;

	i = 0;
	while (cmd->cmd[++i])
	{
		j = 0;
		if (cmd->cmd[i][j++] == '-')
		{
			while (cmd->cmd[i][j] == 'n')
				j++;
			if (cmd->cmd[i][j] && cmd->cmd[i][j] != 'n')
				return (i);
		}
		else
			return (i);
	}
	return (i);
}

int	ft_echo(t_cmd *cmd)
{
	int	i;
	int	new_line;

	i = 1;
	new_line = 1;
	i = check_new_line(cmd);
	if (i > 1)
		new_line = 0;
	while (cmd->cmd[i])
	{
		ft_putstr_fd(cmd->cmd[i], 1);
		if (i && cmd->cmd[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (new_line == 1)
		ft_putstr_fd("\n", 1);
	g_exit_value = 0;
	return (0);
}
