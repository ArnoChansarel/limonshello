/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:30:28 by arnalove          #+#    #+#             */
/*   Updated: 2023/02/22 16:25:39 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0')
		{
			if (s[i] != c)
				break ;
			i++;
		}
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != '\0')
		{
			if (s[i] == c)
				break ;
			i++;
		}
	}
	return (count);
}

static char	**ft_free_split(char **tab, int w)
{
	while (w > 0)
	{
		w--;
		free (tab[w]);
	}
	free (tab);
	tab = NULL;
	return (tab);
}

static char	**ft_intab(char **tab, const char *s, char c, int w)
{
	int				j;
	unsigned int	i;
	unsigned int	old_i;

	i = 0;
	j = 0;
	while (w > j)
	{
		while (s[i] != '\0')
		{
			if (s[i] != c)
				break ;
			i++;
		}
		old_i = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		tab[j] = ft_substr(s, old_i, i - old_i);
		if (!tab[j])
			ft_free_split(tab, j);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**tab;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = ft_intab(tab, s, c, words);
	return (tab);
}
