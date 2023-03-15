/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:50:06 by achansar          #+#    #+#             */
/*   Updated: 2023/03/15 13:29:29 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
probleme 1  : here_doc
probleme 2	: SHLVL +999 + letters = 1
probleme 3  : si builtin, checker arguments suivant (unset vide, pwd + arg doit renvoyer erreur...)
              a checker juste apres la lexlist
probleme 4  : expander : si $? comment on fait
probleme 5  : AWK
probleme 6  : encore probleme d'espace.. (echo hello' '> outfile)
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
    pro->pipes_array = NULL;
    pro->fd1 = -1;
    pro->fd2 = -1;
    pro->here_doc = 0;
    pro->pid = -1;
    return (0);
}

int ft_unlink(t_cmd **cmd)
{
    char    *name;
    t_cmd   *head;

    head = *cmd;
    while (head)
    {
        name = ft_strjoin("here_doc", ft_itoa(head->index));
        unlink(name);
        free(name);
        head = head->next;
    }
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    t_process     process;
    t_cmd       *lst;
    char        *line;
    int         pipes;
    t_env       *env;

	(void) argc;
	(void) argv;
    pipes = 0;

    env = build_env_list(envp);// free apres protection
    if (!env)
        return (1);
    while (1)
    {
        line = readline("minishell$> ");
		
        if (*line)
        {
            if (parser(line, &lst, &pipes, env))
                return (1);
            ft_printparse(lst);
            init_process(&process);
            executor(&process, &lst, pipes, envp);
            ft_unlink(&lst);
        }
        free(line);
    }
    return (0);
}
