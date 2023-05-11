/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:52:21 by ade-bast          #+#    #+#             */
/*   Updated: 2023/05/11 13:10:05 by achansar         ###   ########.fr       */
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

void	clean_newvar_plus(char *str)
{
	while (*str)
	{
		if (*str == '+')
			*str = '\0';
		str++;
	}
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
