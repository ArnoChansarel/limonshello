/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:25:34 by achansar          #+#    #+#             */
/*   Updated: 2023/04/08 14:26:35 by achansar         ###   ########.fr       */
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

int	check_token_ends(char *line)
{
	while (*line == ' ')
		line++;
	if (!*line)
		return (1);
	if (*line == '|')
		return (error_msg("Unexpected Token.\n"));
	line += ft_strlen(line) - 1;
	while (*line == ' ')
		line--;
	if (is_token(line))
		return (1);
	return (0);
}

int	skip_quotes(char *line, int *dq)
{
	int	i;
	
	i = 0;
	if (line[i] == '\"')
		*dq = -*dq;
	if (*dq == -1)
	{
		if (line[i] == '\'')
		{
			i++;
			while (line[i] != '\'')
				i++;
		}
	}
	return (i);
}
