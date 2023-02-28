/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:50:06 by achansar          #+#    #+#             */
/*   Updated: 2023/02/27 18:37:11 by ade-bast         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
    int         pipes;
    t_cmd       *lst;
    char        *line;
	t_cmd		cmd;
	char 		**temp_test;

	(void) argc;
	(void) argv;
    pipes = 0;
    /*
    Minishell loop {
        line = readline
        parser()
        executor()
        free()
    }
    */
   
   build_env_list(envp, &cmd);
   while (1)
   {
        line = readline("minishell$>");
		
        // printf("line = %s.", line);
        if (parser(line, &lst, &pipes))
            return (1);
        ft_printparse(lst);
        // executor(&lst);

		temp_test = ft_split(line, ' ');
		printf("------------------------%s\n",temp_test[0]);
		buitins_exec(get_cmd(temp_test[0]), &cmd);
		
        free(line);
   }
   return (0);
}
