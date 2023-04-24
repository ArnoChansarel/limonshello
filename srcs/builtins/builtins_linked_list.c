/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_linked_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:48:54 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/22 17:57:30 by achansar         ###   ########.fr       */
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
		current = current->next;
	current->next = (t_env *) malloc(sizeof(t_env));
	if (!current->next)
		ft_exit_failure("malloc");
	current->next->key = ft_strdup(key);
	if (!current->next->key)
		ft_exit_failure("malloc");
	expand_quotes(&current->next->key);//           rajout d'arno
	current->next->value = ft_strdup(value);
	if (!current->next->value)
		ft_exit_failure("malloc");
	expand_quotes(&current->next->value);//          aussi
	current->next->export = export;
	current->next->next = NULL;
}

void	shlvl_handler(char **lvl)
{
	int	num;

	num = ft_atoi(*lvl);
	if (num == 999)
		num = 0;
	else if (num > 999)
		num = 1;
	else
		num++;
	free(*lvl);
	*lvl = ft_itoa(num);
}

void	push_list(char **envp, char **tab, t_env *head)
{
	int	i;

	i = 1;
	while (envp[i])
	{
		tab = ft_split(envp[i], '=');
		if (ft_strncmp(tab[0], "SHLVL", 6) == 0)
			shlvl_handler(&tab[1]);
		push(head, 1, tab[0], tab[1]);
		i++;
		ft_free_array(tab);
	}
}

t_env	*build_env_list(char **envp)
{
	int		i;
	char	**tab;
	t_env	*head;
	t_env	*rtr;

	if (!envp || !envp[0])
		return (0);
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
	push_list(envp, tab, head);
	return (rtr);
}
