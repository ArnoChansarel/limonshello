/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnalove <arnalove@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:11:56 by achansar          #+#    #+#             */
/*   Updated: 2023/03/05 19:16:14 by arnalove         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int is_builtin(char *str)
{
    if (ft_strncmp(str, "echo", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "cd", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "pwd", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "export", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "unset", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "env", ft_strlen(str) + 1) == 0)
        return (1);
    else if (ft_strncmp(str, "exit", ft_strlen(str) + 1) == 0)
        return (1);
    return (0);
}

void    get_builtin_function(char *str, int (**builtin)(struct s_cmd *))
{
    if (ft_strncmp(str, "echo", ft_strlen(str) + 1) == 0)
        *builtin = ft_echo;
    else if (ft_strncmp(str, "cd", ft_strlen(str) + 1) == 0)
        *builtin = ft_cd;
    else if (ft_strncmp(str, "pwd", ft_strlen(str) + 1) == 0)
        *builtin = ft_pwd;
    // else if (ft_strncmp(str, "export", ft_strlen(str) + 1) == 0)
    //     builtin = &ft_export;
    // else if (ft_strncmp(str, "unset", ft_strlen(str) + 1) == 0)
    //     builtin = &ft_unset;
    // else if (ft_strncmp(str, "env", ft_strlen(str) + 1) == 0)
    //     builtin = &ft_env;
    // else if (ft_strncmp(str, "exit", ft_strlen(str) + 1) == 0)
    //     builtin = &ft_exit;
}
