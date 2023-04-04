/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:36:18 by achansar          #+#    #+#             */
/*   Updated: 2023/04/04 12:53:17 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_var_size(char *str)
{
	int	s;
	
	s = 0;
	// printf("str in get_s = %s\n", str);
	// printf("str[s] = %c\n", str[s]);
	// printf("rtr isalnum = %d avec %c\n", ft_isalnum(str[s + 1]), str[s+1]);
	while (str[s] && ft_isalnum(str[s + 1]) && str[s] != '\"')
	{
		// printf("current char = %c\n", *str);
		// str++;
		s++;
	}
	// printf("s = %d\n", s);
	// exit(1);
	return (s + 1);
}

int	ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	// printf("strcmp IN : %s\n", s1);
	// printf("size should equal to 5 : %zu\n", n);
	while ((s1[i] == s2[i]) && s1[i] && i < n - 1)
	{
		// printf("char compared = %c to %c\n", s1[i], s2[i]);
		// if (!s1[i] || !s2[i])
		// 	return (1);
		i++;
	}
	if ((s1[i] == '\"' || ft_isalnum(s1[i]) == 0 || !s1[i]) && !s2[i])
		return (0);
	// printf("last char = %c\n", s1[i]);
	// if ((unsigned char)s1[i] - (unsigned char)s2[i] == 0 && ft_isalnum(s1[i]) == 0)
	// 	return (0);
	// printf(" before return %c - %c = %d\n", s1[i], s2[i], (unsigned char)s1[i] - (unsigned char)s2[i]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	// return (1);
}

int expand_quotes(t_lexlst *lex, t_env **env)
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
