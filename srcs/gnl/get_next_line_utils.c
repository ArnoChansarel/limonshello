/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:12:20 by achansar          #+#    #+#             */
/*   Updated: 2023/03/14 17:42:23 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free_all_gnl(char *s1, char **s2)
{
	if (s1)
		free(s1);
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}

int	ft_isin(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (0);
	}
	return (1);
}

int	ft_strlen_gnl(char *s)
{
	int	l;

	l = 0;
	if (!s)
		return (0);
	while (s[l])
		l++;
	return (l);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*concat;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	if (!i)
		return (ft_free_all_gnl(0, &s1));
	concat = malloc((i + 1) * sizeof(char));
	if (!concat)
		return (ft_free_all_gnl(0, &s1));
	i = -1;
	while (s1[++i])
		concat[i] = s1[i];
	j = 0;
	while (s2[j])
		concat[i++] = s2[j++];
	concat[i] = '\0';
	ft_free_all_gnl(0, &s1);
	return (concat);
}

char	*ft_strdup_nl(char *s1)
{
	int		i;
	char	*s2;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		i++;
	s2 = malloc((i + 1) * sizeof(char));
	if (!s2)
		return (ft_free_all_gnl(0, &s1));
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		if (s2[i++] == '\n')
			break ;
	}
	s2[i] = '\0';
	return (s2);
}
