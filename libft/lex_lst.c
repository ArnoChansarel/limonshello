/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexlst_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:56:25 by achansar          #+#    #+#             */
/*   Updated: 2023/02/16 14:13:36 by achansar         ###   ########.fr       */
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
		return (NULL);
	ele->word = content;
	ele->next = NULL;
	return (ele);
}

void	lexlst_clear(t_lexlst **lst)
{
	t_lexlst	*tmp;

	if (!lst)
		return ;
	tmp = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->word);
		free(tmp);
	}
}
