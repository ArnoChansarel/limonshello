/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:56:17 by achansar          #+#    #+#             */
/*   Updated: 2023/02/16 14:13:36 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_lexlst	*ft_lstlast(t_lexlst *lst, int stop)
{
	int	s;
	int	i;

	if (!lst)
		return (0);
	i = 0;
	s = ft_lstsize(lst);
	while (lst && i < s - 1 - stop)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
