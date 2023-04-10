/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils_linked_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:34:47 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/10 13:49:49 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_lstsize2(t_cmd *cmd)
{
	t_env	*tmp;
	size_t	i;

	tmp = cmd->head;
	i = 0;
	while (tmp)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}

void	swap_2_elements(t_env *tmp, t_env *tmp2)
{
	char	*tmp_key;
	char	*tmp_value;

	tmp_key = tmp->key ;
	tmp->key = tmp2->key;
	tmp2->key = tmp_key;
	tmp_value = tmp->value;
	tmp->value = tmp2->value;
	tmp2->value = tmp_value;
}

t_env	*copylist(t_env *head)
{
	t_env	*newnode;

	if (head == NULL)
		return (NULL);
	else
	{
        newnode = (t_env *)malloc(sizeof(t_env));
		if (!newnode)
			ft_exit_failure("malloc");
        newnode->key = ft_strdup(head->key);
		newnode->export = head->export;
		newnode->value = ft_strdup(head->value);
		newnode->next = 0;
		return (newnode);
	}
}

void	comparison_2_elements(t_env *tmp, t_env *tmp2)
{
	int	min;

	while (tmp2)
	{
		if (ft_strlen(tmp->key) > ft_strlen(tmp2->key))
			min = ft_strlen(tmp2->key);
		else
			min = ft_strlen(tmp->key);
		if (ft_strncmp(tmp->key, tmp2->key, min + 1) > 0)
			swap_2_elements(tmp, tmp2);
		tmp2 = tmp2->next;
	}
}

int	ft_print_in_order(t_cmd *cmd)
{
	t_env	*tmp;
	t_env	*tmp2;
	t_env	*head2;

	head2 = copylist(cmd->head);
	tmp = cmd->head->next;
	while (tmp)
	{
		push(head2, tmp->export, tmp->key, tmp->value);
		tmp = tmp->next;		
	}
	tmp = head2;
	while (tmp)
	{
		tmp2 = tmp->next;
		comparison_2_elements(tmp, tmp2);
		printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
