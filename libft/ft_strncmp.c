/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:40:40 by arnalove          #+#    #+#             */
/*   Updated: 2023/04/03 11:48:00 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && i < n - 1)
	{
		if (!s1[i] || !s2[i])
			return (1);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
