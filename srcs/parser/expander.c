/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:24:39 by achansar          #+#    #+#             */
/*   Updated: 2023/03/01 16:34:36 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_var_size(char *str)
{
	int	size;
	
	size = 0;
	while (*str && *str != ' ' && *str != '\"')
	{
		str++;
		size++;
	}
	return (size);
}

char    *replace_var(char *str, char *env, int size)
{
   	char 	*rtr;
	char	*temp;
   	int 	i;

   	i = 0;
	temp = str;
   	// printf("str = %s\nenv = %s\nsize = %d\n", str, env, size);
   	rtr = malloc(sizeof(char *) * (ft_strlen(str) - size - 1 + ft_strlen(env)));
	if (!rtr)
		return (rtr);
   	while (*str && *str != '$')
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

int lookfor_var(t_lexlst *lex, t_env **env, int i)
{
	int     size;
	t_env  *head;

	size = 0;
	head = *env;
	while(lex->word[i])
	{
		if(lex->word[i] == '$')
		{
			while (head)
			{
				size = get_var_size(&lex->word[i]);
				if(ft_strncmp(&lex->word[i + 1], head->key, size - 1) == 0)
				{
					lex->word = replace_var(lex->word, head->value, size);
					break ;
				}
				head = head->next;
			}
			if (!head)
				lex->word = replace_var(lex->word, "", size);
		}
		i++;
	}
	return (0);
}

static int expand_quotes(t_lexlst *lex, t_env **env)
{
	int i;
	char *str;
	int len;

	i = 0;
	if (lex->word[0] == '\"')
	    lookfor_var(lex, env, 0);
	len = ft_strlen(lex->word);
	str = malloc(sizeof(char *) * len - 2);
	while (i <= len - 3)
	{
		str[i] = lex->word[i + 1];
		i++;
	}
	str[i] = '\0';
	free(lex->word);
	lex->word = str;
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
			lookfor_var(head, env, 0);
		head = head->next;
	}
	return (0);
}
