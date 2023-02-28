/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:50:06 by achansar          #+#    #+#             */
/*   Updated: 2023/02/28 14:18:07 by achansar         ###   ########.fr       */
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

int init_process(t_process *pro)
{
    pro->cmd_paths = NULL;
    pro->env_path = NULL;
    pro->fd1 = -1;
    pro->fd2 = -1;
    pro->here_doc = 0;
    pro->pid = -1;
    return (0);
}

int main(int argc, char **argv, char **env)
{
    t_process     process;
    t_cmd       *lst;
    char        *line;
	t_cmd		cmd;
    int         pipes;

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
   
   build_env_list(env, &cmd);
   while (1)
   {
        line = readline("minishell$>");
		
        // printf("line = %s.", line);
        if (parser(line, &lst, &pipes))
            return (1);
        ft_printparse(lst);
        // process = malloc(sizeof(t_process *)); pourquoi ne pas malloc ?
        init_process(&process);
        executor(&process, &lst, pipes, env);
        // executor(&lst);
		
        free(line);
   }
   return (0);
}
