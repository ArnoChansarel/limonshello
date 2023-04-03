/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:24:39 by achansar          #+#    #+#             */
/*   Updated: 2023/04/03 17:42:34 by achansar         ###   ########.fr       */
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

	// printf("IN REPLACE VAR\n");
	// printf("size = %d\n", size);
	temp = str;
   	// printf("str = %s\nenv = %s\nsize = %d\n", str, env, size);
	// printf("len str = %zu | size = %d - 1 + len env = %zu\n", ft_strlen(str), size, ft_strlen(env));
	// printf("Result = %zu\n", (ft_strlen(str) - size - 1 + ft_strlen(env)));
	i = ft_strlen(str) - size - 1 + ft_strlen(env);
	if (i == -1)
		i = 1;
   	rtr = malloc(sizeof(char *) * i);
	if (!rtr)
		return (rtr);
	i = 0;
   	while (*str && *str != '$')//         problem ici, refaire en envoyant i
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







static int	ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && i < n - 1)
	{
		// printf("char compared = %c to %c\n", s1[i], s2[i]);
		// if (!s1[i] || !s2[i])
		// 	return (1);
		i++;
	}
	if ((s1[i] == '\"' || s1[i] == ' ' || !s1[i]) && !s2[i])
		return (0);
	// printf(" before return %c - %c = %d\n", s1[i], s2[i], (unsigned char)s1[i] - (unsigned char)s2[i]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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
				//replace by value
				//lex->word = replace_var(lex->word, "?", size);
				//continue
				
				//un truc comme ca...
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
					lex->word = replace_var(lex->word, head->value, size);
					break ;
				}
				head = head->next;
			}
			if (!head)
			{
				// printf("EMPTY\n");
				lex->word = replace_var(lex->word, "", size);
				continue ;
			}
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
	    lookfor_var(lex, env, 0, 0);
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
			lookfor_var(head, env, 0, 0);
		// printf("word = %sispace\n", head->word);
		head = head->next;
	}
	return (0);
}

/*
si $VAR do not exist, trim
check in our env. in get_cmd();

*/
