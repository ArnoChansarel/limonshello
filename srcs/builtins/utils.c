/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:52:21 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/04 10:21:26 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	buitins_exec(int i, t_cmd *cmd)
{
	if (i == ECHO)
		ft_echo(cmd);
	if (i == CD)
		ft_cd(cmd);
	if (i == PWD)
		ft_pwd(cmd);
	if (i == EXPORT)
		ft_export(cmd);
	if (i == UNSET)
		ft_unset(cmd);
	if (i == ENV)
		ft_env(cmd);
	if (i == EXIT)
		ft_exit(cmd);
	else
		return ;
}

void	ft_free_array(char **tobefreed)
{
	int	i;

	i = 0;
	while (tobefreed[i])
	{
		free(tobefreed[i]);
		i++;
	}
	free(tobefreed);
}

void	err_(char *str)
{
	ft_putstr_fd("exit\n", 1);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argment required\n", 2);
}