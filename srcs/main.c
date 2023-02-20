/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:50:06 by achansar          #+#    #+#             */
/*   Updated: 2023/02/20 17:31:22 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
probleme 1  : syntax error near unexpected token `|'
                quand token mal place
probleme 2	: check double pipe ou faux chevrons des le debut
probleme 3  : si builtin, checker arguments suivant (unset vide, pwd + arg doit renvoyer erreur...)
              a checker juste apres la lexlist
probleme 4  : 
*/

int	error_msg(char *str)
{
	write(2, "Error : ", 8);
	write(2, str, ft_strlen(str));
	return (1);
}

int main(void)
{
    t_parser *lst;
    char *line;

    /*
    Minishell loop {
        line = readline
        parser()
        executor()
        free()
    }
    */
    line = readline("minishell>");
    // printf("line = %s.", line);
    if(parser(line, &lst))
        return (1);
    ft_printparse(lst);
    free(line);
    return (0);
}
