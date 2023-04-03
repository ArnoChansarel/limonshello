/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:52:21 by ade-bast          #+#    #+#             */
/*   Updated: 2023/04/03 10:34:46 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_array(char **tobefreed)
{
	int	i;

	i = 0;
	while (tobefreed[i])
	{
		free(tobefreed[i]);
		i++;
	}
	free(tobefreed);
}
// int	get_cmd(char *str)
// {
//     if (ft_strncmp(str, "echo", ft_strlen(str) + 1) == 0)
//         return(ECHO);
//     else if (ft_strncmp(str, "cd", ft_strlen(str) + 1) == 0)
//         return(CD);
//     else if (ft_strncmp(str, "pwd", ft_strlen(str) + 1) == 0)
//         return(PWD);
//     else if (ft_strncmp(str, "export", ft_strlen(str) + 1) == 0)
//         return(EXPORT);
//     else if (ft_strncmp(str, "unset", ft_strlen(str) + 1) == 0)
//         return(UNSET);
//     else if (ft_strncmp(str, "env", ft_strlen(str) + 1) == 0)
//         return(ENV);
//     else if (ft_strncmp(str, "exit", ft_strlen(str) + 1) == 0)
//         return (EXIT);
//     return 0;
// }
