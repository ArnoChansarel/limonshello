/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:55:06 by achansar          #+#    #+#             */
/*   Updated: 2023/02/28 13:32:59 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd    *get_cmd_elem(t_lexlst **lex)
{
	int         c;
	int         i;
	t_lexlst    *head;
	t_cmd	*ele = NULL;

	i = 0;
	c = count_word_lex(lex);
	head = *lex;
	if(elem_parser_init(&ele, c))
		return (ele);
	// if (is_builtin(head->word))
	// {
		// buitin_exec(get_cmd(head->word));
		// ele->builtin = get_cmd(head->word);
	// }
	while (head && ft_strncmp(head->word, "|", 2) != 0)
	{
		if (is_token(head->word))
		{
		    add_rdrctn(ele, head);
			head = head->next->next;
		}
		// else if (heredoc)
		//     check that
		else
		{
			ele->cmd[i++] = head->word;
			head = head->next;
		}
	}
	ele->cmd[i] = NULL;
	return (ele);
}

int get_cmd_list(t_lexlst **lex, t_cmd **parser_lst, int p)
{
	int i;
	t_cmd    *temp;

	i = 0;
	*parser_lst = NULL;
	while (i <= p)
	{
		temp = get_cmd_elem(lex);		
		if (!temp)
		    return (1);//                            => return error
		parserlst_addback(parser_lst, temp);
		goto_next(lex);
		i++;
	}
	return (0);
}

int parser(char *cmd_line, t_cmd **lstp, int *pipes)
{
	t_lexlst *lexer_lst;

	if(check_token(cmd_line))
		return (1);
	lexer_lst = lexer(cmd_line);
	if (!lexer_lst)
		return (1);
	expander(&lexer_lst, NULL);
	ft_printlist(lexer_lst);
	*pipes = count_pipes(lexer_lst);
	get_cmd_list(&lexer_lst, lstp, *pipes);
	lexlst_clear(&lexer_lst);
	return (0);
}
