/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:49:11 by achansar          #+#    #+#             */
/*   Updated: 2023/04/27 17:59:50 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_token(char *line)
{
	if (check_token_ends(line))
		return (1);
	while (*line)
	{
		line += size_quotes(line) - 1;
		if (is_token(line) && *line == '|')
		{
			line += is_token(line);
			while (*line == ' ')
				line++;
			if (is_token(line) && *line == '|')
				return (error_msg(*line));
		}
		else if (is_token(line) && (*line == '<' || *line == '>'))
		{
			line += is_token(line);
			while (*line == ' ')
				line++;
			if (is_token(line))
				return (error_msg(*line));
			continue ;
		}
		line++;
	}
	return (0);
}

static int	get_new_i(int i, char *cmd_line)
{
	while (cmd_line[i] && cmd_line[i] != ' ')
	{
		if (is_token(&cmd_line[i]))
		{
			i += is_token(&cmd_line[i]);
			break ;
		}
		else
		{
			while (cmd_line[i] && cmd_line[i] != ' '
				&& is_token(&cmd_line[i]) == 0)
			{
				if (cmd_line[i] == '\'' || cmd_line[i] == '\"')
					i += size_quotes(&cmd_line[i]);
				else
					i++;
			}
			break ;
		}
	}
	return (i);
}

t_lexlst	*ft_split_lexer(char *cmd_line, t_lexlst *lexer_lst)
{
	int		i;
	int		old_i;
	char	*buff;

	i = 0;
	old_i = 0;
	while (cmd_line[i])
	{
		while (cmd_line[i])
		{
			if (cmd_line[i] != ' ')
				break ;
			i++;
		}
		if (cmd_line[i])
		{
			old_i = i;
			i = get_new_i(i, cmd_line);
			buff = ft_substr(cmd_line, old_i, i - old_i);
			ft_lstadd_back(&lexer_lst, lexlst_new(buff));
		}
	}
	return (lexer_lst);
}

t_lexlst	*lexer(char *cmd_line)
{
	t_lexlst	*lexer_lst;

	lexer_lst = NULL;
	lexer_lst = ft_split_lexer(cmd_line, lexer_lst);
	return (lexer_lst);
}
