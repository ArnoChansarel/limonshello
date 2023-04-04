/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:25:34 by achansar          #+#    #+#             */
/*   Updated: 2023/04/04 15:00:18 by achansar         ###   ########.fr       */
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

static int	check_token_ends(char *line)
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

int	check_token(char *line)
{
	if (check_token_ends(line))
		return (1);
	// if (*line == '\"' || *line == '\'')
	// {
	// 	while ()
	// }
	while (*line)
	{
		if (is_token(line) && *line == '|')
		{
			line += is_token(line);
			while (*line == ' ')
				line++;
			if (is_token(line) && *line == '|')
				return (error_msg("Unexpected Token.\n"));
		}
		else if (is_token(line) && (*line == '<' || *line == '>')) 
		{
			line += is_token(line);
			while (*line == ' ')
				line++;
			if (is_token(line))
				return (error_msg("Unexpected Token.\n"));
		}
		line++;
	}
	return (0);
}
