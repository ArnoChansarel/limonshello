/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bast <ade-bast@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:50:06 by achansar          #+#    #+#             */
/*   Updated: 2023/04/03 09:15:36 by ade-bast         ###   ########.fr       */
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

int	exit_value = 0;

// exit_value = 0;

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
	sig_handler(0);
    env = build_env_list(envp);// free apres protection
    if (!env)
        return (1);
    print_head();
    while (1)
    {
        line = readline("LimonShello $> ");
		if (!line)
			exit(exit_value); // to update avec la globale
        if (*line)
        {
            if (parser(line, &lst, &pipes, env))
                return (1);
            ft_printparse(lst);
            init_process(&process);
            executor(&process, lst, pipes, envp);
            // ft_unlink(&lst);
        }
		add_history(line);
        free(line);
    }
    return (0);
}

// int	main(int argc, char ** argv, char **envp)
// {
// 	argc = 0;
// 	argv = 0;
// 	t_cmd	cmd;
// 	char	*str;
// 	char	*prompt = ">$";

// 	build_env_list(envp, &cmd);
// 	while (1)
// 	{
// 		sig_handler(0);
// 		cmd.cmd = NULL;
// 		str = readline(prompt);
// 		if (!str)
// 		ft_exit(NULL);
// 		cmd.cmd = ft_split(str, ' ');
// 		if (strcmp(cmd.cmd[0], "echo") == 0)
// 			ft_echo(&cmd);
// 		if (strcmp(cmd.cmd[0], "pwd") == 0)
// 			ft_pwd(&cmd);
// 		if (strcmp(cmd.cmd[0], "export") == 0)
// 			ft_export(&cmd);		
// 		if (strcmp(cmd.cmd[0], "unset") == 0)
// 			ft_unset(&cmd);
// 		if (strcmp(cmd.cmd[0], "cd") == 0)
// 			ft_cd(&cmd);
// 		if (strcmp(cmd.cmd[0], "env") == 0)
// 			ft_env(&cmd);
// 		if (strcmp(cmd.cmd[0], "exit") == 0)
// 			ft_exit(&cmd);
// 		if (strcmp(cmd.cmd[0], "env2") == 0)
// 			ft_print_in_order(&cmd);
// 		if (strcmp(cmd.cmd[0], "env3") == 0)
// 			ft_print_in_order(&cmd);
// 		ft_free_array(cmd.cmd);
// 			if (ft_strlen(str) != 0)

// 		free(str);
// 	}
// 	return (0);
// }
