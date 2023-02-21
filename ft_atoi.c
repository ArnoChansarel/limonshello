/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:25:54 by ade-bast          #+#    #+#             */
/*   Updated: 2023/02/21 16:08:48 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isdigit(int c)
{
	if ((c < '0') || (c > '9'))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long long	nb;
	long		sign;
	int			i;
	long		save;


	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] == '0')
		i++;
	while (ft_isdigit(str[i]))
	{
		save = nb;
		nb = nb * 10 + str[i++] - '0';
		if (nb - (sign == -1) < save)
			return (256);
	}
	return ((int)(nb * sign));
}
