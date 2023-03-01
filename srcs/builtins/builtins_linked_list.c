/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:48:54 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/28 18:42:25 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_node(t_env *head)
{
	t_env	*current;
	t_env	*tmp;

	current = head;
	tmp = current->next;
	current->next = current->next->next;
	free(tmp->key);
	free(tmp->value);
	free(tmp);
}

void	push(t_env *head, int export, char *key, char *value)
{
	t_env	*current;

	current = head;
	while (current->next != NULL) 
	{
		current = current->next;
	}
	current->next = (t_env *) malloc(sizeof(t_env));
	current->next->key = key;
	current->next->value = value;
	current->next->export = export;
	current->next->next = NULL;
}

t_env	*build_env_list(char **envp)
{
	int		i;
	char	**tab;
	t_env	*head;
	t_env	*rtr;

	i = 1;
	head = (t_env *) malloc(sizeof(t_env));
	if (!head)
		return (head);
	rtr = head;
	head->export = 1;
	head->next = NULL;
	tab = ft_split(envp[0], '=');
	head->key = tab[0];
	head->value = tab[1];
	while (envp[i])
	{
		tab = ft_split(envp[i], '=');
		push(head, 1, tab[0], tab[1]);
		i++;
	}
	return (rtr);
}
