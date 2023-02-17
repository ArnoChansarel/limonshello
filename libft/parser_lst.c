/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:29:33 by achansar          #+#    #+#             */
/*   Updated: 2023/02/17 15:32:57 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	parserlst_size(t_parser *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_parser	*parserlst_last(t_parser *lst, int stop)
{
	int	s;
	int	i;

	if (!lst)
		return (0);
	i = 0;
	s = parserlst_size(lst);
	while (lst && i < s - 1 - stop)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

void	parserlst_addback(t_parser **lst, t_parser *new)
{
	t_parser	*last;

	if (!lst || !new)
		return ;
	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
	}
	last = parserlst_last(*lst, 0);
	last->next = new;
}

// t_parser	*parser_new(char **cmd, int (*builtin)(struct s_parser *),
// 			t_lexlst *rdrctn)
// {
// 	t_parser	*ele;

// 	ele = NULL;
// 	if (!cmd)
// 		return (ele);
// 	ele = malloc(sizeof(t_parser));
// 	if (!ele)
// 		return (NULL);
// 	ele->cmd = cmd;
// 	if (builtin)
// 		ele->builtin = builtin;
// 	else
// 		ele->builtin = NULL;
// 	if (rdrctn)
// 		ele->rdrctn;
	
// 	else
// 		ele->rdrctn = NULL;
// 	ele->next = NULL;
// 	return (ele);
// }
