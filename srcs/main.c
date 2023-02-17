/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:50:06 by achansar          #+#    #+#             */
/*   Updated: 2023/02/17 15:03:59 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
probleme 1  : syntax error near unexpected token `|'
                quand token mal place
probleme 2	: check double pipe ou faux chevrons des le debut

*/

/*
CREATE DISPLAY PARSER ELEMENTS FUNCTION
*/

int	check_doubles(char *line)
{
	while (*line)//              => check si token est premier ou dernier ele
	{
		if (is_token(line))
		{
			if (is_token((line + is_token(line))))
			{
				printf("Unexpected Token.\n");
				return (1);
			}
		}
		line++;
	}
	return (0);
}

int main(void)
{
    static char *line;

    line = readline("minishell>");
	if(check_doubles(line))//             => reste a checker avec les espaces.
		return (1);
    if(parser(line))
        return (1);
    free(line);
    return (0);
}