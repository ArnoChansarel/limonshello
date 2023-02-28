/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:48:54 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/23 13:36:04 by ade-bast         ###   ########.fr       */
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

void	build_env_list(char **envp, t_cmd *cmd)
{
	int		i;
	char	**tab;
	t_env	*head;

	i = 1;
	head = (t_env *) malloc(sizeof(t_env));
	if (!head)
		return ;
	cmd->head = head;
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
}
