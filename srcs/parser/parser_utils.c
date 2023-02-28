/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:59:43 by achansar          #+#    #+#             */
/*   Updated: 2023/02/28 14:14:47 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int count_pipes(t_lexlst *lex)
{
    int c;

    c = 0;
    while (lex)
    {
        if (ft_strncmp(lex->word, "|", 2) == 0)
            c++;
        lex = lex->next;
    }
    printf("On compte %d pipes.\n\n", c);
    return (c);
}

void    goto_next(t_lexlst **lex)
{
    t_lexlst    *head;

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

int is_builtin(char *str)
{
    if (ft_strncmp(str, "echo", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "cd", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "pwd", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "export", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "unset", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "env", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "exit", ft_strlen(str) + 1) == 0)
        return (1);
    return (0);
}

int	elem_parser_init(t_cmd **ele, int c)
{
	t_cmd	*temp;

	temp = malloc(sizeof(t_cmd));
	if (!temp)
		return (1);
	temp->builtin = NULL;
	temp->cmd = NULL;
	temp->next = NULL;
	temp->rd_in = NULL;
    temp->rd_out = NULL;
	temp->cmd = malloc(sizeof(char *) * (c + 1));
	if(!temp->cmd)
	{
		free(temp);
		return(1);
	}
	*ele = temp;
	return (0);
}

int count_word_lex(t_lexlst  **lex)
{
	int         c;
	t_lexlst    *head;
	
	head = *lex;
	c = 0;
	while (head && ft_strncmp(head->word, "|", 2) != 0)
	{
		if(ft_strncmp(head->word, "|", 2) != 0
			&& is_token(head->word))
			head = head->next->next;
		else
		{
			c++;
			head = head->next;
		}
	}
	// printf("on compte %d mots\n", c);
	return (c);
}

int add_rdrctn(t_cmd *p, t_lexlst *lex)
{
    if (lex->word[0] == '<')
    {
        if (p->rd_in)
        {
            free(p->rd_in);
            p->rd_in = NULL;
        }
        p->rd_in = ft_strjoin(lex->word, lex->next->word);
    }
    else
    {
        if (p->rd_out)
        {
            free(p->rd_out);
            p->rd_out = NULL;
        }
        p->rd_out = ft_strjoin(lex->word, lex->next->word);
    }
    return (0);
}