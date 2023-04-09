/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:34:33 by achansar          #+#    #+#             */
/*   Updated: 2023/04/09 13:17:44 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_intlen(long n)
{
	int	l;

	l = 0;
	if (n == 0)
		l = 1;
	else if (n < 0)
	{
		n = -n;
		l++;
	}
	while (n > 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*tab;
	long	nb;

	nb = (long) n;
	size = ft_intlen(nb);
	tab = malloc((size + 1) * sizeof(char));
	if (!tab)
		ft_exit_failure("malloc");
	tab[size--] = '\0';
	if (nb < 0)
		nb = -nb;
	while (size >= 0)
	{
		tab[size] = nb % 10 + 48;
		nb = nb / 10;
		size--;
	}
	if (n < 0)
		tab[0] = '-';
	return (tab);
}
