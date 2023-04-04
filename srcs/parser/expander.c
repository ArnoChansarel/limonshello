/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:24:39 by achansar          #+#    #+#             */
/*   Updated: 2023/04/04 12:56:17 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"



char    *replace_var(char *str, char *env, int size, int j)
{
   	char 	*rtr;
	char	*temp;
   	int 	i;

	// printf("IN REPLACE VAR\n");
	// printf("size = %d\n", size);
	temp = str;
   	// printf("str = %s\nenv = %s\nsize = %d\n", str, env, size);
	// printf("len str = %zu | size = %d - 1 + len env = %zu\n", ft_strlen(str), size, ft_strlen(env));
	// printf("Result = %zu\n", (ft_strlen(str) - size - 1 + ft_strlen(env)));
	i = ft_strlen(str) - size - 1 + ft_strlen(env);
	if (i == -1)
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

















int lookfor_var(t_lexlst *lex, t_env **env, int i, int size)
{
	t_env  *head;

	while(lex->word[i])
	{
		if (lex->word[i] == '$')
		{
			if (lex->word[i + 1] == '?')
			{
				size = get_var_size(&lex->word[i]);
				lex->word = replace_var(lex->word, ft_itoa(g_exit_value), size, i);
				continue ;
			}
			// printf("char = %c value = %d\n", lex->word[i + 1], lex->word[i + 1]);
			if (ft_isalnum(lex->word[i + 1]) == 0)
			{
				i++;
				continue ;
			}
			head = *env;
			while (head)
			{
				size = get_var_size(&lex->word[i]);
				// printf("word = %s | key = %s | size = %d - 1\n", lex->word, head->key, size);
				// printf("BEFORE STRCMP, char = %c%c\n", lex->word[i], lex->word[i+1]);
				// printf("and str = %s\n", lex->word);
				if (ft_strncmp2(&lex->word[i + 1], head->key, size) == 0)
				{
					lex->word = replace_var(lex->word, head->value, size, i);
					break ;
				}
				head = head->next;
			}
			if (!head)
			{
				// printf("EMPTY\n");
				lex->word = replace_var(lex->word, "", size, i);
				continue ;
			}
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
		// printf("word = %sispace\n", head->word);
		head = head->next;
	}
	return (0);
}
