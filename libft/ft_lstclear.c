/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:56:08 by achansar          #+#    #+#             */
/*   Updated: 2023/02/16 14:13:36 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lstclear(t_lexlst **lst)
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
