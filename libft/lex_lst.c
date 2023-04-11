/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:58:32 by achansar          #+#    #+#             */
/*   Updated: 2023/04/11 15:09:21 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_lexlst	*lexlst_new(void *content)
{
	t_lexlst	*ele;

	ele = NULL;
	if (!content)
		return (ele);
	ele = malloc(sizeof(t_lexlst));
	if (!ele)
		ft_exit_failure("malloc");
	ele->word = content;
	ele->next = NULL;
	return (ele);
}

void	lexlst_clear(t_lexlst **lst)
{
	t_lexlst	*tmp;

	tmp = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->word);
		free(tmp);
	}
}
