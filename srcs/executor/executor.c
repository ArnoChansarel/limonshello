/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:25:59 by achansar          #+#    #+#             */
/*   Updated: 2023/02/23 15:01:18 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int open_redirections(t_process *process, t_cmd *ele)// Implique de remettre fd a 0 apres les avoir ferme
{
    if (ele->rd_in)
    {
        // if (ft_strncmp(ele->rd_in, "<<", 2) == 0)
        //     get_here_doc(process, ele->rd_in + 2);
        if (open_infile(process, ele))
            return (1);//                             exit ?
        //close pipe before
    }
    if (ele->rd_out)
    {
        if (open_outfile(process, ele))
        {
            if (process->fd1)
                close(process->fd1);
            return (1);//                             exit ?
        }
        // close pipe ?
    }
    return (0);
}

int	child(t_process *process, t_cmd *ele, char **env)
{
	char	*cmd;

    if (ele->rd_in || ele->rd_out)
        open_redirections(process, ele);
    // if (bultin)
    //else 
	cmd = get_cmd(process, ele->cmd);
	if (!cmd)
	{
		// cmd_not_found(process, ele->cmd[0]);
		exit(127);
	}
	close(process->pipe[0]);
	dup2(process->fd1, STDIN_FILENO);
	close(process->fd1);
	dup2(process->pipe[1], STDOUT_FILENO);
	close(process->pipe[1]);
	if (execve(cmd, ele->cmd, env) == -1)
		perror("execve ");
	return (0);
}

int executor(t_process *process, t_cmd **cmd_lst, int pipes, char **env)
{
    /*
    Create pipes
    launch processes (fork if needed)
    
    */
    (void)pipes;
    pipe(process->pipe);
    child(process, *cmd_lst, env);
    return (0);
}
