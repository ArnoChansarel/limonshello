/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:52:21 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/11 13:43:37 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	ft_putstr_fd(": numeric argument required\n", 2);
}

int	notalphanum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	delete_list(t_env *tmp2, t_env *tmp)
{
	while (tmp)
	{
		free(tmp->key);
		free(tmp->value);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

void	array_creator(char **array, t_env *tmp)
{
	int		i;
	char	*tmp_join;

	i = 0;
	while (tmp)
	{
		tmp_join = ft_strjoin(tmp->key, "=");
		if (!tmp_join)
			exit(EXIT_FAILURE);
		array[i] = ft_strjoin(tmp_join, tmp->value);
		free(tmp_join);
		if (!array[i])
			exit(EXIT_FAILURE);
		tmp = tmp->next;
		i++;
	}
	array[i] = NULL;
}
