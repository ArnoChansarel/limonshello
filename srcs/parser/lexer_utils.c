/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:25:34 by achansar          #+#    #+#             */
/*   Updated: 2023/02/15 16:26:03 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int checker_quotes(char *line, int s, int d)
{
	while (*line)
	{
		if (*line == '\'' && s == 0 && d == 0)
			s++;
		else if (*line == '\'' && s == 1 && d == 0)
			s--;
		else if (*line == '\"' && d == 0 && s == 0)
			d++;
		else if (*line == '\"' && d == 1 && s == 0)
			d--;
		line++;
	}
	if (s != 0 || d != 0)
		return (1);
	return (0);
}

int	size_quotes(const char *str)
{
	int i;

	i = 0;
	if (str[i] == '\'')
	{
		i++;
		while(str[i] != '\'')
			i++;
	}
	else if (str[i] == '\"')
	{
		i++;
		while (str[i] != '\"')
			i++;
	}
	return (i + 1);
}

int is_token(char *str)
{
	if (*str == '|')
		return (1);
	else if (*str == '<' || *str == '>')
	{
		if (*str == '<' && *(str + 1) == '<')
			return (2);
		if (*str == '>' && *(str + 1) == '>')
			return (2);
		else
			return (1);
	}
	return (0);
}