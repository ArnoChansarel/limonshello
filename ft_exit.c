/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:56:55 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/21 14:26:17 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	static	check_arg(t_cmd *cmd)
// {
// 	int	i;
// 	int	sign;

// 	i = 0;
// 	while (cmd->tab[1][i] == '-' || cmd->tab[1][i] == '+')
// 	{
// 		i++;
// 		sign++;
// 	}
// 	while (cmd->tab[1][i])
// 	{			
// 		if (!ft_isdigit(cmd->tab[1][i]))
// 			return (1);
// 		i++;
// 	}
// 	if (sign > 1)
// 		return (0);
// 	else
// 		return (sign);
// }

int	ft_exit(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd->tab || !cmd->tab[1])
		return (0);
	while (cmd->tab[i++])
		i++;
	if (i > 2)
	{
		ft_putstr_fd("Too many arguments", 2);
		cmd->exit_status = 1;
	}
	cmd->exit_status = ft_atoi(cmd->tab[1]); 
	return 0;
}














// void	exec_exit(char **lex, t_ms *ms, char *rl, int piping)
// {
// 	if (lex[1])
// 	{
// 		if (check_exit_args(lex[1]))
// 			g_ret_cmd = 255;
// 		else
// 			g_ret_cmd = ft_atoi_64bits(lex[1]);
// 	}
// 	if (g_ret_cmd >= 255 && lex[1])
// 	{
// 		ft_stderr("-minishell: exit: ", lex[1], NUM_ERR);
// 		g_ret_cmd = 255;
// 		close_program(ms, rl, lex, piping);
// 	}
// 	if (lex[1] && lex[2])
// 	{
// 		write(2, "-minishell: exit: too many arguments\n", 37);
// 		g_ret_cmd = 1;
// 	}
// 	else
// 		close_program(ms, rl, lex, piping);
// }