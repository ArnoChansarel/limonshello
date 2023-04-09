/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:30:07 by achansar          #+#    #+#             */
/*   Updated: 2023/04/09 14:22:07 by achansar         ###   ########.fr       */
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
		if (cmd->cmd[i][0])
		{
			ft_putstr_fd(cmd->cmd[i], 1);
			if (i && cmd->cmd[i + 1])
				ft_putchar_fd(' ', 1);
		}
		i++;
	}
	if (new_line == 1)
		ft_putstr_fd("\n", 1);
	cmd->exit_status = 0;
	return (0);
}
