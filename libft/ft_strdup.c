/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:38:18 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/09 13:18:38 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		ft_exit_failure("malloc");
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}