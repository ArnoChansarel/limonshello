/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:25:07 by achansar          #+#    #+#             */
/*   Updated: 2023/04/11 14:49:43 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57)
		|| (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	ft_isalnum_(int c)
{
	if ((c >= 48 && c <= 57)
		|| (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122)
		|| (c == '_'))
		return (1);
	return (0);
}

int	ft_isalnum_plus(int c)
{
	if ((c >= 48 && c <= 57)
		|| (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122)
		|| (c == '_')
		|| (c == '+'))
		return (1);
	return (0);
}

int	notalphanum_(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum_(str[i]))
			return (0);
		i++;
	}
	return (1);
}
