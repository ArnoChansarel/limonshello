/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:59:43 by achansar          #+#    #+#             */
/*   Updated: 2023/02/17 15:05:32 by achansar         ###   ########.fr       */
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
    printf("On compte %d pipes.\n", c);
    return (c);
}

void    goto_next(t_lexlst **lex)
{
    t_lexlst    *head;

    head = *lex;
    while(head)
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

int	elem_parser_init(t_parser **ele, int c)
{
	t_parser	*temp;
	
	temp = malloc(sizeof(t_parser));
	if (!temp)
		return (1);
	temp->builtin = NULL;
	temp->cmd = NULL;
	temp->next = NULL;
	temp->rdrctn = NULL;
	temp->cmd = malloc(sizeof(char *) * c + 1);
	if(!temp->cmd)
	{
		free(temp);
		return(1);
	}
	*ele = temp;
	return (0);
}
