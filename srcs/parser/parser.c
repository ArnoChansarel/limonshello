/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:55:06 by achansar          #+#    #+#             */
/*   Updated: 2023/04/11 16:24:40 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_cmd	*get_cmd_elem(t_lexlst **lex, t_env *env, int index, int i)
{
	int			c;
	t_lexlst	*head;
	t_cmd		*ele;

	ele = NULL;
	c = count_word_lex(lex);
	head = *lex;
	elem_parser_init(&ele, c, index);
	ele->head = env;
	while (head && ft_strncmp(head->word, "|", 2) != 0)
	{
		if (is_token(head->word))
		{
			add_rdrctn(ele, head);
			head = head->next->next;
		}
		else
		{
			ele->cmd[i++] = ft_strdup(head->word);
			head = head->next;
		}
	}
	ele->cmd[i] = NULL;
	return (ele);
}

int	get_cmd_list(t_lexlst **lex, t_cmd **parser_lst, int p, t_env *env)
{
	int			i;
	t_cmd		*temp;
	t_lexlst	*head;

	i = 0;
	*parser_lst = NULL;
	head = *lex;
	while (i <= p)
	{
		temp = get_cmd_elem(&head, env, i, 0);
		get_builtin_func(temp->cmd[0], env, &temp->builtin);
		if (!temp)
			return (1);
		parserlst_addback(parser_lst, temp);
		goto_next(&head);
		i++;
	}
	return (0);
}

int	send_to_expander(t_cmd **cmd_lst)
{
	int		i;
	t_cmd	*head;

	head = *cmd_lst;
	while (head)
	{
		i = 0;
		expander(&head->cmd[i], &head->head);
		if (head->cmd[i] && ft_strncmp(head->cmd[i++], "export", 6))
		{
			while (head->cmd[i])
				expander(&head->cmd[i++], &head->head);
		}
		if (head->rd_in)
			expand_redirections(&head->rd_in, &head->head);
		if (head->rd_out)
			expand_redirections(&head->rd_out, &head->head);
		head = head->next;
	}
	return (0);
}

t_lexlst	*parser(char *cmd_line, t_cmd **lstp, int *pipes, t_env *env)
{
	t_lexlst	*lexer_lst;

	lexer_lst = NULL;
	if (checker_quotes(cmd_line, 0, 0))
		return (lexer_lst);
	if (check_token(cmd_line))
		return (lexer_lst);
	lexer_lst = lexer(cmd_line);
	if (!lexer_lst)
		exit(EXIT_FAILURE);
	*pipes = count_pipes(lexer_lst);
	get_cmd_list(&lexer_lst, lstp, *pipes, env);
	send_to_expander(lstp);
	return (lexer_lst);
}
