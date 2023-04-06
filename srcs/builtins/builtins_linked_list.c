/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:48:54 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/04 09:52:32 by ade-bast         ###   ########.fr       */
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
	int		tmp;

	tmp = 0;
	current = head;
	while (current->next != NULL) 
	{
		current = current->next;
	}
	if ((ft_strncmp("SHLVL", key, 5)) == 0)
	{
		tmp = ft_atoi(value) + 1;
		value = ft_itoa(tmp);
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
	free(tab);
	while (envp[i])
	{
		tab = ft_split(envp[i], '=');
		push(head, 1, tab[0], tab[1]);
		i++;
		ft_free_array(tab);
	}
	return (rtr);
}
