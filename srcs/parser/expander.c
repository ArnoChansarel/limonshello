/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:24:39 by achansar          #+#    #+#             */
/*   Updated: 2023/04/04 14:36:29 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *replace_var(char *str, char *env, int size, int j)
{
   	char 	*rtr;
	char	*temp;
   	int 	i;

	temp = str;
	i = ft_strlen(str) - size - 1 + ft_strlen(env);
	if (i <= 0)
		i = 1;
   	rtr = malloc(sizeof(char *) * i + 1);
	if (!rtr)
		return (rtr);
	i = 0;
   	while (*str && i < j)
		rtr[i++] = *str++;
	while (*env)
		rtr[i++] = *env++;
	str += size;
	while (*str)
		rtr[i++] = *str++;
	rtr[i] = '\0';
	free(temp);
	return (rtr);
}

int	find_var_and_replace(t_lexlst *lex, t_env **env, int i)
{
	int		size;
	t_env  *head;
	
	size = 0;
	head = *env;
	while (head)
	{
		size = get_var_size(&lex->word[i]);
		if (ft_strncmp2(&lex->word[i + 1], head->key, size) == 0)
		{
			lex->word = replace_var(lex->word, head->value, size, i);
			return (1);
		}
		head = head->next;
	}
	lex->word = replace_var(lex->word, "", size, i);
	return (0);
}

int lookfor_var(t_lexlst *lex, t_env **env, int i, int size)
{
	while(lex->word[i])
	{
		if (lex->word[i] == '$')
		{
			if (lex->word[i + 1] == '?')
			{
				size = get_var_size(&lex->word[i]);
				lex->word = replace_var(lex->word, ft_itoa(g_exit_value), size + 1, i);
				continue ;
			}
			if (ft_isalnum(lex->word[i + 1]) == 0)
			{
				i++;
				continue ;
			}
			if (find_var_and_replace(lex, env, i) == 0)
				continue ;
		}
		i++;
	}
	return (0);
}

int expander(t_lexlst **lex, t_env **env)
{
	t_lexlst *head;

	head = *lex;
	while (head)
	{
		if (head->word[0] == '\'' || head->word[0] == '\"')
			expand_quotes(head, env);
		else
			lookfor_var(head, env, 0, 0);
		head = head->next;
	}
	return (0);
}
