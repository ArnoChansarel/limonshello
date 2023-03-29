/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:48:54 by ade-bast          #+#    #+#             */
/*   Updated: 2023/03/27 12:15:56 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//! boucle delete_node => free quand le prog quitte

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
	if (!current->next)
		exit(EXIT_FAILURE);
	current->next->key = ft_strdup(key);
	if (!current->next->key)
		exit(EXIT_FAILURE);
	current->next->value = ft_strdup(value);
	if (!current->next->value)
		exit(EXIT_FAILURE);
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
	free(tab);
	while (envp[i])
	{
		tab = ft_split(envp[i], '=');
		push(head, 1, tab[0], tab[1]);
		i++;
		ft_free_array(tab);
	}
}
