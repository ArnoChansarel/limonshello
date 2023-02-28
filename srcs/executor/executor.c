// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   executor.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/21 17:25:59 by achansar          #+#    #+#             */
// /*   Updated: 2023/02/22 17:28:43 by achansar         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../includes/minishell.h"

// int open_redirections(t_pipex *pipex, t_cmd *ele)
// {
//     if (ele->rd_in)
//     {
//         if(ft_strncmp(ele->rd_in, "<<", 2) == 0)
//             get_here_doc(pipex, ele->rd_in + 2);//                         => fix issue from pipex
//         open_file();
//         //close pipe before
//     }
//     if (ele->rd_out)
//     {
        
//     }
// }

// int	child(t_pipex *pipex, t_cmd *ele, char **env)
// {
// 	char	*cmd;

//     if (ele->rd_in || ele->rd_out)
//         open_redirections(pipex, ele);
//     // if (bultin)
//     //else 
// 	cmd = get_cmd(pipex, ele->cmd);
// 	if (!cmd)
// 	{
// 		cmd_not_found(pipex, pipex->command[0]);
// 		exit(127);
// 	}
// 	close(pipex->pipe[0]);
// 	dup2(pipex->fd1, STDIN_FILENO);
// 	close(pipex->fd1);
// 	dup2(pipex->pipe[1], STDOUT_FILENO);
// 	close(pipex->pipe[1]);
// 	if (execve(cmd, pipex->command, env) == -1)
// 		perror("execve ");
// 	return (0);
// }

// // static int	child_middle(t_pipex *pipex, char *arg, char **env)
// // {
// // 	char	*cmd;

// // 	cmd = get_cmd(pipex, pipex->args, arg);
// // 	if (!cmd)
// // 	{
// // 		cmd_not_found(pipex, pipex->command[0]);
// // 		exit(127);
// // 	}
// // 	close(pipex->pipe[0]);
// // 	dup2(pipex->pipe[1], STDOUT_FILENO);
// // 	if (execve(cmd, pipex->command, env) == -1)
// // 		perror("execve ");
// // 	return (0);
// // }

// int executor(t_cmd **cmd_lst, int pipes)
// {
//     /*
//     Create pipes
//     launch processes (fork if needed)
    
//     */
//     return (0);
// }
