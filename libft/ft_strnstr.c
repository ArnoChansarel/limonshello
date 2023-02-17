/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:45:57 by arnalove          #+#    #+#             */
/*   Updated: 2023/02/08 16:48:59 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;

	i = 0;
	if (!haystack && len == 0)
		return (0);
	else if (needle[i] == '\0')
		return ((char *)haystack);
	hay = (char *) haystack;
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] != '\0'
			&& hay[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[++j] == '\0')
				return (hay + i);
		}
		i++;
	}
	return (0);
}
