/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:55:06 by achansar          #+#    #+#             */
/*   Updated: 2023/02/17 15:41:35 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int count_word(t_lexlst  **lex)
{
	int         c;
	t_lexlst    *head;
	
	head = *lex;
	c = 0;
	while (head && ft_strncmp(head->word, "|", 2) != 0)
	{
		c++;
		head = head->next;
	}
	// printf("count = %d\n", c);
	return (c);
}

t_parser    *get_parser_elem(t_lexlst **lex)
{
	int         c;
	int         i;
	t_lexlst    *head;
	t_parser   *ele = NULL;

	i = 0;
	c = count_word(lex);
	head = *lex;
	if(elem_parser_init(&ele, c))
		return (ele);
	// if (is_builtin(head->word))
	// 	ele->builtin = get_cmd(head->word);

	while (head && ft_strncmp(head->word, "|", 2) != 0)
	{
		// if (istoken)
		//     take next to rdrctn
		// else if (heredoc)
		//     check that
		ele->cmd[i++] = head->word;
		head = head->next;
	}
	ele->cmd[i] = NULL;
	// check if builtin -> go to builtin and add it to struct value
	return (ele);
}

int get_parser_list(t_lexlst **lex, int p)
{
	int i;
	t_parser    *parser_lst;
	t_parser    *temp;

	i = 0;
	parser_lst = NULL;
	while (i <= p)
	{
		temp = get_parser_elem(lex);		
		if (!temp)
		    return (1);//                            => return error
		printf("temp = %s\n", temp->cmd[0]);
		parserlst_addback(&parser_lst, temp);
		goto_next(lex);
		i++;
	}
	ft_printparse(parser_lst);
	return (0);
}

int parser(char *cmd_line)
{
	// int i = 0;
	int pipes;
	t_lexlst *lexer_lst;

	lexer_lst = lexer(cmd_line);
	if (!lexer_lst)
		return (1);
	ft_printlist(lexer_lst);
	pipes = count_pipes(lexer_lst);
	get_parser_list(&lexer_lst, pipes);
	//create_list_parsing()
	//clear_list(list_lexer)
	return (0);
}
