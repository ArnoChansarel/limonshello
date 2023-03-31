/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:49:11 by achansar          #+#    #+#             */
/*   Updated: 2023/03/31 14:34:08 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int get_new_i(int i, char *cmd_line)
{
	while (cmd_line[i] && cmd_line[i] != ' ')
	{
		if (is_token(&cmd_line[i]))
		{
			i += is_token(&cmd_line[i]);
			break ;
		}
		else if (cmd_line[i] == '\'' || cmd_line[i] == '\"')
		{
			i += size_quotes(&cmd_line[i]);
			break ;
		}
		else
		{
			while (cmd_line[i] && cmd_line[i] != ' '
				&& is_token(&cmd_line[i]) == 0
				&& cmd_line[i] != '\'' && cmd_line[i] != '\"')
				i++;
			break ;
		}
	}
	return (i);
}

t_lexlst	*ft_split_lexer(char *cmd_line, t_lexlst *lexer_lst)
{
	int 	i;
	int 	old_i;
	char	*buff;

	i = 0;
	old_i = 0;
	while(cmd_line[i])
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
			if (!*buff)
				lexlst_clear(&lexer_lst);//                    => doit return error
			ft_lstadd_back(&lexer_lst, lexlst_new(buff));
		}
	}
	return (lexer_lst);
}

t_lexlst	*lexer(char *cmd_line)//                        => envoyer double pointeur
{//															=> plutot que simple
	t_lexlst	*lexer_lst = NULL;

	lexer_lst = ft_split_lexer(cmd_line, lexer_lst);
	return (lexer_lst);
}
