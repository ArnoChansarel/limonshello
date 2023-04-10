/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:36:18 by achansar          #+#    #+#             */
/*   Updated: 2023/04/09 17:38:22 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_var_size(char *str)
{
	int	s;

	s = 0;
	while (str[s] && ft_isalnum(str[s + 1]) && str[s] != '\"')
		s++;
	return (s + 1);
}

int	ft_strncmp2(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && i < n - 1)
		i++;
	if ((s1[i] == '\"' || ft_isalnum(s1[i]) == 0 || !s1[i]) && !s2[i])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	get_full_size(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '\'' && str[i] != '\"')
		{
			size++;
			i++;
		}
		if (str[i] && (str[i] == '\'' || str[i] == '\"'))
		{
			i += size_quotes(&str[i]);
			size = i - 2;
		}
	}
	return (size);
}

int	copy_clean(char **cmd, char **str, int i, int j)
{
	while (cmd[0][i])
	{
		while (cmd[0][i] && cmd[0][i] != '\"' && cmd[0][i] != '\'')
			str[0][j++] = cmd[0][i++];
		if (cmd[0][i] && cmd[0][i] == '\"')
		{
			i++;
			while (cmd[0][i] && cmd[0][i] != '\"')
				str[0][j++] = cmd[0][i++];
			i++;
		}
		if (cmd[0][i] && cmd[0][i] == '\'')
		{
			i++;
			while (cmd[0][i] && cmd[0][i] != '\'')
				str[0][j++] = cmd[0][i++];
			i++;
		}
	}
	str[0][j] = '\0';
	return (0);
}

int	expand_quotes(char **cmd)
{
	char	*str;
	int		len;

	len = get_full_size(*cmd);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		ft_exit_failure("malloc");
	copy_clean(cmd, &str, 0, 0);
	free(*cmd);
	*cmd = str;
	return (0);
}
