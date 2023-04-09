/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:59:43 by achansar          #+#    #+#             */
/*   Updated: 2023/04/09 17:29:13 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_pipes(t_lexlst *lex)
{
	int	c;

	c = 0;
	while (lex)
	{
		if (ft_strncmp(lex->word, "|", 2) == 0)
			c++;
		lex = lex->next;
	}
	// printf("On compte %d pipes.\n\n", c);
	return (c);
}

void	goto_next(t_lexlst **lex)
{
	t_lexlst	*head;

	head = *lex;
	while (head)
	{
		if (ft_strncmp(head->word, "|", 2) == 0)
		{
			*lex = head->next;
			return ;
		}
		head = head->next;
	}
}

int	elem_parser_init(t_cmd **ele, int c, int index)
{
	t_cmd	*temp;

	temp = malloc(sizeof(t_cmd));
	if (!temp)
		ft_exit_failure("malloc");
	temp->index = index;
	temp->builtin = NULL;
	temp->cmd = NULL;
	temp->next = NULL;
	temp->rd_in = NULL;
	temp->rd_out = NULL;
	temp->cmd = malloc(sizeof(char *) * (c + 1));
	if (!temp->cmd)
		ft_exit_failure("malloc");
	*ele = temp;
	return (0);
}

int	count_word_lex(t_lexlst **lex)
{
	int			c;
	t_lexlst	*head;

	head = *lex;
	c = 0;
	while (head && ft_strncmp(head->word, "|", 2) != 0)
	{
		if (ft_strncmp(head->word, "|", 2) != 0
			&& is_token(head->word))
			head = head->next->next;
		else
		{
			c++;
			head = head->next;
		}
	}
	return (c);
}

int	add_rdrctn(t_cmd *p, t_lexlst *lex)
{
	char	*temp;

	temp = NULL;
	if (lex->word[0] == '<')
	{
		if (p->rd_in)
			free(p->rd_in);
		temp = ft_strjoin(lex->word, " ");
		p->rd_in = ft_strjoin(temp, lex->next->word);
	}
	else
	{
		if (p->rd_out)
			free(p->rd_out);
		temp = ft_strjoin(lex->word, " ");
		p->rd_out = ft_strjoin(temp, lex->next->word);
	}
	free(temp);
	return (0);
}
