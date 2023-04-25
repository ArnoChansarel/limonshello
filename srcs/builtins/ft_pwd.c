/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:57:01 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/25 13:19:32 by ade-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_cmd *cmd)
{
	char	buf[PATH_MAX + 1];

	(void) *cmd;
	if (getcwd(buf, PATH_MAX))
		printf("%s\n", buf);
	else
		printf("ERROR\n");
	return (0);
}
