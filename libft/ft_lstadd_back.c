/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:55:08 by achansar          #+#    #+#             */
/*   Updated: 2023/02/16 14:13:36 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lstadd_back(t_lexlst **lst, t_lexlst *new)
{
	t_lexlst	*last;

	if (!lst || !new)
		return ;
	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			// printf("creating first element = %s\n", new->word);
			return ;
		}
	}
	last = ft_lstlast(*lst, 0);
	// printf("last = %s\n", last->word);
	last->next = new;
}
